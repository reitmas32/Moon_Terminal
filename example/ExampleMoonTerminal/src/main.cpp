#include <iostream>
//#include <core/cmp/cmp_base.tpp>
#include <tools/platform_info.hpp>
#include <tools/time_step.hpp>

#include <Moon/template/core/ent/ent_base.tpp>
#include <Moon/template/core/ent/ent.tpp>
#include <Moon/template/core/ent/ent_storage.tpp>

#include <Moon_Terminal/include/gtx.hpp>
#include <Moon_Terminal/include/input_sys.hpp>
#include <Moon_Terminal/include/render_sys.hpp>
#include <Moon_Terminal/include/position_cmp.hpp>
#include <Moon_Terminal/include/sprite_cmp.hpp>

struct Player_t : Moon::Core::Entity_t<Player_t>
{
    Player_t() : Moon::Core::Entity_t<Player_t>() {}
    Player_t(Moon::Alias::EntityId eid) : Moon::Core::Entity_t<Player_t>(eid) {}
    ~Player_t() = default;
};

struct Enemy_t : Moon::Core::Entity_t<Enemy_t>
{
    Enemy_t() : Moon::Core::Entity_t<Enemy_t>() {}
    Enemy_t(Moon::Alias::EntityId eid) : Moon::Core::Entity_t<Enemy_t>(eid) {}
    ~Enemy_t() = default;
};

void makeGtx(Moon::Terminal::Gtx_t & gtx)
{
    auto &ent_1 = gtx.addEntity<Player_t>();
    gtx.addComponentById<Player_t, Moon::Terminal::Sprite_t>(ent_1.eid, std::vector<char>{'+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+', '|', ' ', 'P', 'o', 'n', ' ', 't', 'u', ' ', 'm', 'e', 'n', 's', 'a', 'j', 'e', ' ', 'a', 'q', 'u', 'i', '!', '.', '.', '!', ' ', '|', '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' ', '-', '+'}, 3, 27);
    gtx.addComponentById<Player_t, Moon::Terminal::Position_t<std::uint8_t>>(ent_1.eid, 15, 6);

    auto &ent_2 = gtx.addEntity<Enemy_t>();
    gtx.addComponentById<Enemy_t, Moon::Terminal::Sprite_t>(ent_2.eid, std::vector<char>{'+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+', '|', ' ', 'P', 'o', 'n', ' ', 't', 'u', ' ', 'm', 'e', 'n', 's', 'a', 'j', 'e', ' ', 'a', 'q', 'u', 'i', '!', '.', '.', '!', ' ', '|', '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' ', '-', '+'}, 3, 27);
    gtx.addComponentById<Enemy_t, Moon::Terminal::Position_t<std::uint8_t>>(ent_2.eid, 1, 1);
}

int main()
{

    auto gtx = Moon::Terminal::Gtx_t();
    auto sysRender = Moon::Terminal::RenderSys_t();
    auto inputSys = Moon::Terminal::InputSys_t();
    makeGtx(gtx);
    Moon::Tools::TimeStep_t time;
    uint64_t nanos;
    while (gtx.last_key != Moon::Terminal::MOON_KEY_ESC)
    {
        nanos = 1000000000 / 30;
        if (time.ellapsed() > nanos)
        {
            sysRender.update(&gtx);
            time.start();
        }

        inputSys.update(&gtx);
    }

    //a.draw(5,6);
    return 0;
}
