#include "api/create.hpp"
#include "api/delete.hpp"
#include "api/read.hpp"
#include "api/update.hpp"
#include <userver/testsuite/testsuite_support.hpp>
#include "userver/components/minimal_server_component_list.hpp"
#include "userver/utils/daemon_run.hpp"
#include "userver/clients/http/component.hpp"
#include <userver/clients/dns/component.hpp>

int main(int argc, char **argv) {

    const auto component_list =
            userver::components::MinimalServerComponentList()
                    .Append<userver::components::TestsuiteSupport>()
                    .Append<userver::components::Postgres>("dbb")
                    .Append<userver::clients::dns::Component>()
                    .Append<api::service::Create>()
                    .Append<api::service::Read>()
                    .Append<api::service::Update>()
                    .Append<api::service::Delete>();


    return userver::utils::DaemonMain(argc, argv, component_list);
}
