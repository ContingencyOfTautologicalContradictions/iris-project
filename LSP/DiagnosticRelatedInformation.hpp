#pragma once
#include "Location.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DiagnosticRelatedInformation final
    {
    public:
        Location location;

        std::string message;
    };

    void from_json(const nlohmann::json&, DiagnosticRelatedInformation&);

    void to_json(nlohmann::json&, const DiagnosticRelatedInformation&);
}