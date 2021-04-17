#include <sprite_cmp.hpp>

namespace Moon::Terminal
{
    Sprite_t::Sprite_t(Moon::Alias::EntityId eid) : Moon::Core::Component_t<Sprite_t>(eid) {}

    Sprite_t::Sprite_t(
        Moon::Alias::EntityId eid,
        std::vector<char> sprite,
        std::uint16_t h,
        std::uint16_t w)
        : Moon::Core::Component_t<Sprite_t>(eid),
          sprite{sprite},
          h{h}, w{w}
    {
    }

    void Sprite_t::draw(std::uint16_t x, std::uint16_t y)
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

} // namespace Moon::Terminal
