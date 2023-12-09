#pragma once
#include "DocumentSelector.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] SelectionRangeRegistrationOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;

        std::optional<DocumentSelector> documentSelector;

        Json::Field<std::string> id;
    };

    void from_json(const nlohmann::json&, SelectionRangeRegistrationOptions&);

    void to_json(nlohmann::json&, const SelectionRangeRegistrationOptions&);
}