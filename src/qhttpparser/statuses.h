#ifndef STATUSES_H
#define STATUSES_H

STATUS_CODE(100, "Continue", Continue)
STATUS_CODE(101, "Switching Protocols", SwitchingProtocols)
STATUS_CODE(102, "Processing", Processing)                 // RFC 2518) obsoleted by RFC 4918
STATUS_CODE(200, "OK", OK)
STATUS_CODE(201, "Created", Created)
STATUS_CODE(202, "Accepted", Accepted)
STATUS_CODE(203, "Non-Authoritative Information", NonAuthoritativeInformation)
STATUS_CODE(204, "No Content", NoContent)
STATUS_CODE(205, "Reset Content", ResetContent)
STATUS_CODE(206, "Partial Content", PartialContent)
STATUS_CODE(207, "Multi-Status", MultiStatus)               // RFC 4918
STATUS_CODE(300, "Multiple Choices", MultipleChoices)
STATUS_CODE(301, "Moved Permanently", MovedPermanently)
STATUS_CODE(302, "Moved Temporarily", MovedTemporarily)
STATUS_CODE(303, "See Other", SeeOther)
STATUS_CODE(304, "Not Modified", NotModified)
STATUS_CODE(305, "Use Proxy", UseProxy)
STATUS_CODE(307, "Temporary Redirect", TemporaryRedirect)
STATUS_CODE(400, "Bad Request", BadRequest)
STATUS_CODE(401, "Unauthorized", Unauthorized)
STATUS_CODE(402, "Payment Required", PaymentRequired)
STATUS_CODE(403, "Forbidden", Forbidden)
STATUS_CODE(404, "Not Found", NotFound)
STATUS_CODE(405, "Method Not Allowed", MethodNotAllowed)
STATUS_CODE(406, "Not Acceptable", NotAcceptable)
STATUS_CODE(407, "Proxy Authentication Required", ProxyAuthenticationRequired)
STATUS_CODE(408, "Request Time-out", RequestTimeOut)
STATUS_CODE(409, "Conflict", Conflict)
STATUS_CODE(410, "Gone", Gone)
STATUS_CODE(411, "Length Required", LengthRequired)
STATUS_CODE(412, "Precondition Failed", PreconditionFailed)
STATUS_CODE(413, "Request Entity Too Large", RequestEntityTooLarge)
STATUS_CODE(414, "Request-URI Too Large", RequestURITooLarge)
STATUS_CODE(415, "Unsupported Media Type", UnsupportedMediaType)
STATUS_CODE(416, "Requested Range Not Satisfiable", RequestedRangeNotSatisfiable)
STATUS_CODE(417, "Expectation Failed", ExpectationFailed)
STATUS_CODE(418, "I\"m a teapot", Im_a_teapot)              // RFC 2324
STATUS_CODE(422, "Unprocessable Entity", UnprocessableEntity)       // RFC 4918
STATUS_CODE(423, "Locked", Locked)                     // RFC 4918
STATUS_CODE(424, "Failed Dependency", FailedDependency)          // RFC 4918
STATUS_CODE(425, "Unordered Collection", UnorderedCollection)       // RFC 4918
STATUS_CODE(426, "Upgrade Required", UpgradeRequired)           // RFC 2817
STATUS_CODE(500, "Internal Server Error", InternalServerError)
STATUS_CODE(501, "Not Implemented", NotImplemented)
STATUS_CODE(502, "Bad Gateway", BadGateway)
STATUS_CODE(503, "Service Unavailable", ServiceUnavailable)
STATUS_CODE(504, "Gateway Time-out", GatewayTimeOut)
STATUS_CODE(505, "HTTP Version not supported", HTTPVersionNotSupported)
STATUS_CODE(506, "Variant Also Negotiates", VariantAlsoNegotiates)    // RFC 2295
STATUS_CODE(507, "Insufficient Storage", InsufficientStorage)       // RFC 4918
STATUS_CODE(509, "Bandwidth Limit Exceeded", BandwidthLimitExceeded)
STATUS_CODE(510, "Not Extended", NotExtended)                // RFC 2774

#endif // STATUSES_H
