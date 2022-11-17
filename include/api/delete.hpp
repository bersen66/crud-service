#pragma once

#include "userver/server/handlers/http_handler_base.hpp"
#include "userver/storages/postgres/postgres.hpp"
#include <userver/server/handlers/http_handler_base.hpp>

namespace api::service {

    class Delete final : public userver::server::handlers::HttpHandlerBase {
    public:
        static constexpr std::string_view kName = "handle-delete";

        Delete(const userver::components::ComponentConfig &config,
               const userver::components::ComponentContext &context);

        std::string HandleRequestThrow(
                const userver::server::http::HttpRequest &request,
                userver::server::request::RequestContext &context) const override;

    private:

        userver::storages::postgres::ClusterPtr pg_cluster;
    };

}  // namespace api::service