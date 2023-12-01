#include "InitializeParams.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ClientInfo& ci)
    {
        ci.name = data.at("name").get<std::string>();
        ci.version = Json::Field<std::string>(data, "version");
    }

    void to_json(nlohmann::json& data, const ClientInfo& ci)
    {
        data["name"] = ci.name;
        if(ci.version.Present())
            data["version"] = ci.version.Value();
    }

    void from_json(const nlohmann::json& data, InitializeParams& ip)
    {
        if(data.contains("workDoneProgress"))
        {
            ip.workDoneToken.Set();
            const nlohmann::json& workDoneProgress = data.at("workDoneProgress"
            );
            if(workDoneProgress.is_string())
                ip.workDoneToken.Value() = workDoneProgress.get<std::string>();
            else
                ip.workDoneToken.Value() = workDoneProgress.get<std::int64_t>()
                ;
        }
        const nlohmann::json& processId = data.at("processId");
        if(processId.is_number_integer())
            ip.processId = processId.get<std::int64_t>();
        ip.clientInfo = Json::Field<ClientInfo>(data, "clientInfo");
        ip.locale = Json::Field<std::string>(data, "locale");
        if(data.contains("rootPath"))
        {
            ip.rootPath.Set();
            const nlohmann::json& rootPath = data.at("rootPath");
            if(rootPath.is_string())
                ip.rootPath.Value() = rootPath.get<std::string>();
        }
        const nlohmann::json& rootUri = data.at("rootUri");
        if(rootUri.is_string())
            ip.rootUri = rootUri.get<DocumentUri>();
        if(data.contains("initializationOptions"))
        {
            ip.initializationOptions.Set();
            const nlohmann::json& initializationOptions = data.at(
            "initializeOptions");
            if(initializationOptions.is_boolean())
                ip.initializationOptions.Value() = initializationOptions.get<
                bool>();
            else if(initializationOptions.is_number_integer())
                ip.initializationOptions.Value() = initializationOptions.get<
                std::int64_t>();
            else if(initializationOptions.is_string())
                ip.initializationOptions.Value() = initializationOptions.get<
                std::string>();
        }
        //ip.capabilities = data.at("capabilities").get<ClientCapabilities>();
        ip.trace = Json::Field<TraceValue>(data, "trace");
        if(data.contains("workspaceFolders"))
        {
            ip.workspaceFolders.Set();
            const nlohmann::json& workspaceFolders = data.at("workspaceFolders"
            );
            if(not workspaceFolders.is_null())
                ip.workspaceFolders.Value() = workspaceFolders.get<std::vector<
                WorkspaceFolder>>();
        }
    }

    [[nodiscard]] auto jsonify(const std::optional<std::int64_t>& processId)
    noexcept -> nlohmann::json
    {
        nlohmann::json data;
        if(processId.has_value())
            data = processId.value();
        else
            data = nullptr;
        return data;
    }

    [[nodiscard]] auto jsonify(const std::optional<std::string>& rootPath)
    noexcept -> nlohmann::json
    {
        nlohmann::json data;
        if(rootPath.has_value())
            data = rootPath.value();
        else
            data = nullptr;
        return data;
    }

    [[nodiscard]] auto jsonify(const std::optional<std::variant<bool, std::
    int64_t, std::string>>& initializationOptions) noexcept -> nlohmann::json
    {
        nlohmann::json data;
        if(initializationOptions.has_value())
            std::visit([&](auto&& active)
            {
                data = active;
            }, initializationOptions.value());
        else
            data = nullptr;
        return data;
    }

    [[nodiscard]] auto jsonify(const std::optional<std::vector<WorkspaceFolder>
    >& workspaceFolders) noexcept -> nlohmann::json
    {
        nlohmann::json data;
        if(workspaceFolders.has_value())
            for(const WorkspaceFolder& workspaceFolder : workspaceFolders.value
            ())
                data.push_back(workspaceFolder);
        else
            data = nullptr;
        return data;
    }

    void to_json(nlohmann::json& data, const InitializeParams& ip)
    {
        if(ip.workDoneToken.Present())
            std::visit([&](auto&& active)
            {
                data["workDoneToken"] = active;
            }, ip.workDoneToken.Value());
        data["processId"] = jsonify(ip.processId);
        if(ip.clientInfo.Present())
            data["clientInfo"] = ip.clientInfo.Value();
        if(ip.locale.Present())
            data["locale"] = ip.locale.Value();
        if(ip.rootPath.Present())
            data["rootPath"] = jsonify(ip.rootPath.Value());
        data["rootUri"] = jsonify(ip.rootUri);
        if(ip.initializationOptions.Present())
            data["initializationOptions"] = jsonify(ip.initializationOptions.
            Value());
        //data["capabilities"] = ip.capabilities;
        if(ip.trace.Present())
            data["trace"] = ip.trace.Value();
        if(ip.workspaceFolders.Present())
            data["workspaceFolders"] = jsonify(ip.workspaceFolders.Value());
    }
}