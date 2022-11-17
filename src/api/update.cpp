#include "api/update.hpp"

#include "userver/components/component_context.hpp"

namespace api::service {

Update::Update(const userver::components::ComponentConfig& config,
               const userver::components::ComponentContext& context)
    : HttpHandlerBase(config, context)
    , pg_cluster(context.FindComponent<userver::components::Postgres>("dbb")
                     .GetCluster()) {}

std::string Update::HandleRequestThrow(
    const userver::server::http::HttpRequest& request,
    userver::server::request::RequestContext& context) const {
  const auto& id_string = request.GetPathArg("id");
  const auto& new_name = request.GetPathArg("new_name");

  if (id_string.empty() || new_name.empty()) {
    return "Not updated!";
  }

  pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster,
                      fmt::format("UPDATE users SET name='{}' WHERE id={};",
                                  new_name, id_string));
  return "Updated";
}
}  // namespace api::service