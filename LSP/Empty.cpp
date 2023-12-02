#include "Empty.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json&, Empty&){}

    void to_json(nlohmann::json&, const Empty&){}
}