#pragma once
#include "TraceValue.hpp"
#include "ClientInfo.hpp"
#include "WorkspaceFolder.hpp"
#include "WorkDoneProgressParams.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] InitializeParams final
    {
    public:
        Json::Field<ProgressToken> workDoneToken;

        std::optional<std::int64_t> processId;

        Json::Field<ClientInfo> clientInfo;

        Json::Field<std::string> locale;

        Json::Field<std::optional<std::string>> rootPath;

        std::optional<DocumentUri> rootUri;

        Json::Field<std::optional<std::variant<bool, std::int64_t, std::string>
        >> initializationOptions;

        //ClientCapabilities capabilities;

        Json::Field<TraceValue> trace;

        Json::Field<std::optional<std::vector<WorkspaceFolder>>>
        workspaceFolders;
    };

    void from_json(const nlohmann::json&, InitializeParams&);

    void to_json(nlohmann::json&, const InitializeParams&);
}