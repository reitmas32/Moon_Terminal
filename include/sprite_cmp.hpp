#pragma once

#ifdef MOON_PLATFORM_LINUX
#include <Moon/template/core/cmp/cmp.tpp>
#include <Moon/template/core/cmp/cmp_storage.tpp>

#include <ncurses.h>

namespace Moon::Terminal
{
    struct Sprite_t : Moon::Core::Component_t<Sprite_t>
    {
        std::vector<char> sprite;
        std::uint16_t h{0}, w{0};
        Sprite_t(Moon::Alias::EntityId eid) : Moon::Core::Component_t<Sprite_t>(eid) {}
        Sprite_t(
            Moon::Alias::EntityId eid,
            std::vector<char> sprite,
            std::uint16_t h,
            std::uint16_t w)
            : Moon::Core::Component_t<Sprite_t>(eid),
              sprite{sprite},
              h{h}, w{w}
        {
        }
        Sprite_t() = default;
        ~Sprite_t() = default;

        void draw(std::uint16_t x, std::uint16_t y)
        {
            for (std::uint16_t i = 0; i < this->h; i++)
            {
                for (std::uint16_t j = 0; j < this->w; j++)
                {
                    move(x + i, y + j);
                    addch(this->sprite[(i * this->w) + j]);
                }
            }
        }
    };

}

#endif