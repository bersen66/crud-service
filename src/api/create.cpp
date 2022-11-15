#include "api/create.hpp"

namespace api
{
std::string Create::HandleRequestThrow(const userver::server::http::HttpRequest& request,
                                       userver::server::request::RequestContext& context) const
{
  return "Called CREATE";
}
} // namespace api