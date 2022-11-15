#include "api/update.hpp"

namespace api
{
std::string Update::HandleRequestThrow(const userver::server::http::HttpRequest& request,
                                       userver::server::request::RequestContext& context) const
{
  return "Called UPDATE";
}
} // namespace api