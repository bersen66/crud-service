#include "api/create.hpp"
#include "fmt/core.h"
#include "userver/components/component_context.hpp"
#include "userver/components/component_config.hpp"
#include "userver/server/handlers/http_handler_base.hpp"

namespace api::service {

    Create::Create(const userver::components::ComponentConfig &config,
                   const userver::components::ComponentContext &context)
            : HttpHandlerBase(config, context),
              pg_cluster(
                      context.FindComponent<userver::components::Postgres>("dbb")
                              .GetCluster()
              ) {
        pg_cluster->Execute(
                userver::storages::postgres::ClusterHostType::kMaster,
                "CREATE TABLE IF NOT EXISTS users ("
                    "id serial NOT NULL PRIMARY KEY,"
                    "name VARCHAR(255) NOT NULL"
                ");");
    }

    std::string Create::HandleRequestThrow(
            const userver::server::http::HttpRequest &request,
            userver::server::request::RequestContext &context) const {

        const auto &name = request.GetPathArg("name");
        LOG_CRITICAL() << name;

        if (!name.empty()) {
            LOG_CRITICAL() << "Inserting: " << name << " to database";
            pg_cluster->Execute(
                    userver::storages::postgres::ClusterHostType::kMaster,
                    "INSERT INTO users (name)"
                    "VALUES"
                    "('" + name + "');"
            );

            return "CREATED";

        } else {
            throw std::runtime_error("Name is empty!");
        }


        return "NOT CREATED";


    }
}  // namespace api::service