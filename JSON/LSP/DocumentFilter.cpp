#include "DocumentFilter.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DocumentFilter& df)
    {
        df.language = Json::Field<std::string>(data, "language");
        df.scheme = Json::Field<std::string>(data, "scheme");
        df.pattern = Json::Field<std::string>(data, "pattern");
    }

    void to_json(nlohmann::json& data, const DocumentFilter& df)
    {
        if(df.language.Present())
            data["language"] = df.language.Value();
        if(df.scheme.Present())
            data["scheme"] = df.scheme.Value();
        if(df.pattern.Present())
            data["pattern"] = df.pattern.Value();
    }
}