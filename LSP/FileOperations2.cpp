#include "FileOperations2.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, FileOperations2& fo)
    {
        fo.didCreate = Json::Field<FileOperationRegistrationOptions>(data,
        "didCreate");
        fo.willCreate = Json::Field<FileOperationRegistrationOptions>(data,
        "willCreate");
        fo.didRename = Json::Field<FileOperationRegistrationOptions>(data,
        "didRename");
        fo.willRename = Json::Field<FileOperationRegistrationOptions>(data,
        "willRename");
        fo.didDelete = Json::Field<FileOperationRegistrationOptions>(data,
        "didDelete");
        fo.willDelete = Json::Field<FileOperationRegistrationOptions>(data,
        "willDelete");
    }

    void to_json(nlohmann::json& data, const FileOperations2& fo)
    {
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