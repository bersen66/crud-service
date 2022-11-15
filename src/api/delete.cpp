#include "api/delete.hpp"

namespace api
{
std::string Delete::HandleRequestThrow(const userver::server::http::HttpRequest& request,
                                       userver::server::request::RequestContext& context) const
{
  return "Called DELETE";
}
} // namespace api