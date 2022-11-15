#include "api/create.hpp"
#include "api/delete.hpp"
#include "api/read.hpp"
#include "api/update.hpp"

#include "userver/components/minimal_server_component_list.hpp"
#include "userver/logging/log.hpp"

#include "userver/utils/daemon_run.hpp"


int main(int argc, char** argv)
{
  const auto component_list = userver::components::MinimalServerComponentList()
                                  .Append<api::Create>()
                                  .Append<api::Read>()
                                  .Append<api::Update>()
                                  .Append<api::Delete>();

  return userver::utils::DaemonMain(argc, argv, component_list);
}
