#pragma once

#include "userver/server/handlers/http_handler_base.hpp"

namespace api
{

class Read final : public userver::server::handlers::HttpHandlerBase
{
public:
  static constexpr std::string_view kName = "handle-read";
  using userver::server::handlers::HttpHandlerBase::HttpHandlerBase;

  std::string HandleRequestThrow(const userver::server::http::HttpRequest& request,
                                 userver::server::request::RequestContext& context) const override;
};

} // namespace api