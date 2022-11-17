#include "api/delete.hpp"

#include "userver/components/component_config.hpp"
#include "userver/components/component_context.hpp"
#include "userver/server/handlers/http_handler_base.hpp"

namespace api::service {

Delete::Delete(const userver::components::ComponentConfig& config,
               const userver::components::ComponentContext& context)
    : HttpHandlerBase(config, context)
    , pg_cluster(context.FindComponent<userver::components::Postgres>("dbb")
                     .GetCluster()) {
  LOG_INFO() << "Delete constructed";
}

std::string Delete::HandleRequestThrow(
    const userver::server::http::HttpRequest& request,
    userver::server::request::RequestContext& context) const {
  const auto& id_string = request.GetPathArg("id");

  if (id_string.empty()) {
    return "NOT DELETED";
  }

  pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster,
                      fmt::format("DELETE FROM users WHERE id={};", id_string));

  return "DELETED";
}

}  // namespace api::service