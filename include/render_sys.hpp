#pragma once


#include "gtx.hpp"
#include "position_cmp.hpp"
#include "sprite_cmp.hpp"

#ifdef MOON_PLATFORM_LINUX
#include <Moon/template/core/gtx/gtx.tpp>
#include <Moon/template/core/sys/sys.tpp>

#include <ncurses.h>

namespace Moon::Terminal
{

    struct RenderSys_t : Moon::Core::System_t<Moon::Terminal::Gtx_t>
    {
        bool alive() override
        {
            return true;
        }

        void update(Moon::Terminal::Gtx_t *gtx) override
        {
            wclear(stdscr);
            for (auto &cmp : gtx->getComponents<Sprite_t>())
            {
                auto *pos = gtx->getRequiredComponent<Position_t<std::uint8_t>>(cmp.eid);

                if (!pos)
                    continue;

                cmp.draw(pos->x, pos->y);
            }
        }
    };
}

#endif