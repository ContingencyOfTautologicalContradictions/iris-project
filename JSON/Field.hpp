#pragma once
#include "../Meta/Serialisable.hpp"
#include "../Meta/DefaultConstructible.hpp"

namespace Iris::Json
{
    template<class T> class [[nodiscard]] Field final
    {
        bool present = false;

        T value;
    public:
        constexpr Field() noexcept requires Meta::DefaultConstructible<T> =
        default;

        Field(const nlohmann::json& data) noexcept : present(true), value(data.
        get<T>()){}

        Field(const nlohmann::json& data, const char* name) noexcept requires
        Meta::Serialisable<T>
        {
            if(data.contains(name))
            {
                present = true;
                value = data.at(name).get<T>();
            }
        }

        [[nodiscard]] auto Present() const noexcept -> bool
        {
            return present;
        }

        [[nodiscard]] auto Value() noexcept -> T&
        {
            return value;
        }

        [[nodiscard]] auto Value() const noexcept -> T
        {
            return value;
        }

        auto Set() noexcept -> void
        {
            present = true;
        }
    };
}