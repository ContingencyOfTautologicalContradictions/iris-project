#include "SymbolTag.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, SymbolTag& st)
    {
        st.valueSet = data.at("valueSet").get<std::vector<ESymbolTag>>();
    }

    void to_json(nlohmann::json& data, const SymbolTag& st)
    {
        data["valueSet"] = st.valueSet;
    }
}