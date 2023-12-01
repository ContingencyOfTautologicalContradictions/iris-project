#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    enum class ErrorCodes : std::int32_t
    {
        ParseError = -32700,
        InvalidRequest = -32600,
        MethodNotFound = -32601,
        InvalidParams = -32602,
        InternalError = -32603,
        JsonrpcReservedErrorRangeStart = -32099,
        ServerNotInitialized = -32002,
        UnknownErrorCode = -32001,
        JsonrpcReservedErrorRangeEnd = -32000,
        LspReservedErrorRangeStart = -32899,
        RequestFailed = -32803,
        ServerCancelled = -32802,
        ContentModified = -32801,
        RequestCancelled = -32800,
        LspReservedErrorRangeEnd = -32800
    };

    [[nodiscard]] auto ErrorCode(ErrorCodes ec) noexcept -> std::int32_t
    {
        return static_cast<std::int32_t>(ec);
    }

    template<class T> class [[nodiscard]] ResponseError final
    {
    public:
        std::int32_t code;

        std::string message;

        Json::Field<std::variant<bool, std::string, std::int64_t, std::vector<T
        >, T>> data;
    };

    template<class T, class U> class [[nodiscard]] Response final
    {
    public:
        std::string jsonrpc;

        std::variant<std::int64_t, std::string> id;

        Json::Field<std::variant<bool, std::string, std::int64_t, std::vector<T
        >, T>> result;

        Json::Field<ResponseError<U>> error;
    };

    
}