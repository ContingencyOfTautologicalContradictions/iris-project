#include "FileOperations.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, FileOperations& fo)
    {
        fo.dynamicRegistration = Json::Field<bool>(data, "dynamicRegistration")
        ;
        fo.didCreate = Json::Field<bool>(data, "didCreate");
        fo.willCreate = Json::Field<bool>(data, "willCreate");
        fo.didRename = Json::Field<bool>(data, "didRename");
        fo.willRename = Json::Field<bool>(data, "willRename");
        fo.didDelete = Json::Field<bool>(data, "didDelete");
        fo.willDelete = Json::Field<bool>(data, "willDelete");
    }

    void to_json(nlohmann::json& data, const FileOperations& fo)
    {
        if(fo.dynamicRegistration.Present())
            data["dynamicRegistration"] = fo.dynamicRegistration.Value();
        if(fo.didCreate.Present())
            data["didCreate"] = fo.didCreate.Value();
        if(fo.willCreate.Present())
            data["willCreate"] = fo.willCreate.Value();
        if(fo.didRename.Present())
            data["didRename"] = fo.didRename.Value();
        if(fo.willRename.Present())
            data["willRename"] = fo.willRename.Value();
        if(fo.didDelete.Present())
            data["didDelete"] = fo.didDelete.Value();
        if(fo.willDelete.Present())
            data["willDelete"] = fo.willDelete.Value();
    }
}