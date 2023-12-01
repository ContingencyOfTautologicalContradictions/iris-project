#include "SymbolKind.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, SymbolKind& sk)
    {
        sk.valueSet = Json::Field<std::vector<ESymbolKind>>(data, "valueSet");
    }

    void to_json(nlohmann::json& data, const SymbolKind& sk)
    {
        if(sk.valueSet.Present())
            data["valueSet"] = sk.valueSet.Value();
    }
}