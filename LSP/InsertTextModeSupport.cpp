#include "InsertTextModeSupport.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, InsertTextModeSupport& itms)
    {
        itms.valueSet = data.at("valueSet").get<std::vector<InsertTextMode>>();
    }

    void to_json(nlohmann::json& data, const InsertTextModeSupport& itms)
    {
        data["valueSet"] = itms.valueSet;
    }
}