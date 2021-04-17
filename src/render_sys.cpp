#include <render_sys.hpp>

namespace Moon::Terminal
{
    RenderSys_t::RenderSys_t() {}

    RenderSys_t::~RenderSys_t() {}

    bool RenderSys_t::alive()
    {
        return true;
    }

    void RenderSys_t::update(Moon::Terminal::Gtx_t *gtx)
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
} // namespace Moon::Terminal
