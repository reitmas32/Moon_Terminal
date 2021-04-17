#include <input_sys.hpp>

#ifdef MOON_PLATFORM_LINUX

namespace Moon::Terminal
{
    InputSys_t::InputSys_t()
    {
        initscr();
        cbreak();
        noecho();
        scrollok(stdscr, TRUE);
        nodelay(stdscr, TRUE);
    }

    InputSys_t::~InputSys_t(){
        endwin();
    }

    bool InputSys_t::alive(){
        return true;
    }

} // namespace Moon::Terminal

#endif