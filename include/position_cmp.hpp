#pragma once


#ifdef MOON_PLATFORM_LINUX
#include <Moon/template/core/cmp/cmp.tpp>
#include <Moon/template/core/cmp/cmp_storage.tpp>

#include <ncurses.h>

namespace Moon::Terminal
{
    template <class Type>
    requires std::is_integral<Type>::value 
    struct Position_t : Moon::Core::Component_t<Position_t<Type>>
    {
        Type x{0}, y{0};
        Position_t(Moon::Alias::EntityId eid, Type x, Type y)
            : Moon::Core::Component_t<Position_t>(eid), x{x}, y{y} {}
        Position_t() = default;
        ~Position_t() = default;
    };

}

#endif