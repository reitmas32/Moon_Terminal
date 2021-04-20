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

    Sprite_t::Sprite_t(Moon::Alias::EntityId eid, const std::string file) : Moon::Core::Component_t<Sprite_t>(eid)
    {
        std::string line;
        std::ifstream myfile(file.c_str());
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                if (line.size() > this->w)
                    this->w = line.size();
                for (auto c : line)
                {
                    this->sprite.push_back(c);
                }
                this->h++;
            }
            myfile.close();
        }

        else
            std::cout << "Unable to open file";
        
    }

    void Sprite_t::draw(std::uint16_t x, std::uint16_t y)
    {
        for (std::uint16_t i = 0; i < this->h; i++)
        {
            for (std::uint16_t j = 0; j < this->w; j++)
            {
                move(y + i, x + j);
                addch(this->sprite[(i * this->w) + j]);
            }
        }
    }

} // namespace Moon::Terminal
