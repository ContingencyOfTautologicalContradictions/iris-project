#include "DiagnosticRelatedInformation.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DiagnosticRelatedInformation&
    dri)
    {
        dri.location = data.at("location").get<Location>();
        dri.message = data.at("message").get<std::string>();
    }

    void to_json(nlohmann::json& data, const DiagnosticRelatedInformation& dri)
    {
        data["location"] = dri.location;
        data["message"] = dri.message;
    }
}