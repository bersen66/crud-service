#include "api/read.hpp"

#include "userver/components/component_config.hpp"
#include "userver/components/component_context.hpp"

namespace api::service {
Read::Read(const userver::components::ComponentConfig& config,
           const userver::components::ComponentContext& context)
    : HttpHandlerBase(config, context)
    , pg_cluster(context.FindComponent<userver::components::Postgres>("dbb")
                     .GetCluster()) {}

std::string Read::HandleRequestThrow(
    const userver::server::http::HttpRequest& request,
    userver::server::request::RequestContext& context) const {
  const auto& id_string = request.GetPathArg("id");

  if (id_string.empty()) {
    return "Bad request";
  }

  auto result = pg_cluster->Execute(
      userver::storages::postgres::ClusterHostType::kSlave,
      fmt::format("SELECT name FROM users WHERE id={}", id_string));

  return result.AsSingleRow<std::string>();
}

}  // namespace api::service