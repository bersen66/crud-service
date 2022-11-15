#include "api/read.hpp"

namespace api
{
std::string Read::HandleRequestThrow(const userver::server::http::HttpRequest& request,
                                       userver::server::request::RequestContext& context) const
{
  return "Called READ";
}
} // namespace api