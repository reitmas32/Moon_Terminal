#pragma once

#include <thread>

#include <iostream>

#include <Moon/include/tools/platform_info.hpp>

#ifdef MOON_PLATFORM_LINUX
#include <Moon/template/core/gtx/gtx.tpp>
#include <Moon/template/core/sys/sys.tpp>

#include <ncurses.h>

#include "moon_key_codes.hpp"

#include "gtx.hpp"

namespace Moon::Terminal
{

    struct InputSys_t : Moon::Core::System_t<Moon::Terminal::Gtx_t>
    {

        InputSys_t();

        ~InputSys_t();

        bool alive() override;

        void update(Moon::Terminal::Gtx_t *gtx) override;
    };
}

#endif