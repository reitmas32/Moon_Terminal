#pragma once
#include <Moon/include/tools/platform_info.hpp>
#ifdef MOON_PLATFORM_LINUX
#include <Moon/template/core/gtx/gtx.tpp>

namespace Moon::Terminal
{

    struct Gtx_t : Moon::Core::GameContext_t<Gtx_t>
    {
        Moon::Alias::EventCode last_key{0};

        Gtx_t();

        ~Gtx_t();
    };
}

#endif
