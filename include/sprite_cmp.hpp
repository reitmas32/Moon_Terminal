#pragma once

#include <Moon/include/tools/platform_info.hpp>

#ifdef MOON_PLATFORM_LINUX

#include <fstream>

#include <Moon/template/core/cmp/cmp.tpp>
#include <Moon/template/core/cmp/cmp_storage.tpp>

#include <ncurses.h>

namespace Moon::Terminal
{
    struct Sprite_t : Moon::Core::Component_t<Sprite_t>
    {
        std::vector<char> sprite;
        std::uint16_t h{0}, w{0};
        Sprite_t(Moon::Alias::EntityId eid);
        Sprite_t(
            Moon::Alias::EntityId eid,
            std::vector<char> sprite,
            std::uint16_t h,
            std::uint16_t w);

        Sprite_t(Moon::Alias::EntityId eid, const std::string file);
        Sprite_t() = default;
        ~Sprite_t() = default;

        void draw(std::uint16_t x, std::uint16_t y);
    };

}

#endif