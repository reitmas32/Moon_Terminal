#pragma once

#include <Moon/include/tools/platform_info.hpp>

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
        RenderSys_t();

        ~RenderSys_t();

        bool alive() override;

        void update(Moon::Terminal::Gtx_t *gtx) override;
    };
}

#endif