#pragma once

namespace Iris::Meta
{
    namespace Detail
    {
        template<class, class> class Same
        {
        public:
            static consteval bool Value()
            {
                return false;
            }
        };

        template<class T> class Same<T, T>
        {
        public:
            static consteval bool Value()
            {
                return true;
            }
        };
    }

    template<class T, class U> concept Same = Detail::Same<T, U>::Value();
}