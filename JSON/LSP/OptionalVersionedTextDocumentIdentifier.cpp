#include "OptionalVersionedTextDocumentIdentifier.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    OptionalVersionedTextDocumentIdentifier& ovtdi)
    {
        ovtdi.uri = data.at("uri").get<DocumentUri>();
        const nlohmann::json& version = data.at("version");
        if(version.is_number_integer())
            ovtdi.version = version.get<std::int64_t>();
    }

    void to_json(nlohmann::json& data, const
    OptionalVersionedTextDocumentIdentifier& ovtdi)
    {
        data["uri"] = ovtdi.uri;
        if(ovtdi.version.has_value())
            data["version"] = ovtdi.version.value();
    }
}