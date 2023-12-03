#include "DidChangeWatchedFilesClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    DidChangeWatchedFilesClientCapabilities& dcwfcc)
    {
        dcwfcc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
        dcwfcc.relativePatternSupport = Json::Field<bool>(data,
        "relativePatternSupport");
    }

    void to_json(nlohmann::json& data, const
    DidChangeWatchedFilesClientCapabilities& dcwfcc)
    {
        if(dcwfcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = dcwfcc.dynamicRegistration.Value();
        if(dcwfcc.relativePatternSupport.Present())
            data["relativePatternSupport"] = dcwfcc.relativePatternSupport.
            Value();
    }
}