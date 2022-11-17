#pragma once

#include "userver/server/handlers/http_handler_base.hpp"
#include "userver/storages/postgres/postgres.hpp"

namespace api::service {

class Read final : public userver::server::handlers::HttpHandlerBase {
public:
  static constexpr std::string_view kName = "handle-read";

  Read(const userver::components::ComponentConfig& config,
       const userver::components::ComponentContext& context);

  std::string HandleRequestThrow(
      const userver::server::http::HttpRequest& request,
      userver::server::request::RequestContext& context) const override;

private:
  userver::storages::postgres::ClusterPtr pg_cluster;
};

}  // namespace api::service