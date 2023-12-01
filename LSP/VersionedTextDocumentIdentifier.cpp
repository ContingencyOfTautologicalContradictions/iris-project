#include "VersionedTextDocumentIdentifier.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, VersionedTextDocumentIdentifier&
    vtdi)
    {
        vtdi.uri = data.at("uri").get<DocumentUri>();
        vtdi.version = data.at("version").get<std::int64_t>();
    }

    void to_json(nlohmann::json& data, const VersionedTextDocumentIdentifier&
    vtdi)
    {
        data["uri"] = vtdi.uri;
        data["version"] = vtdi.version;
    }
}