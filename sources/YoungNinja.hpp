#ifndef COWBOY_VS_NINJA_B_YOUNGNINJA_HPP
#define COWBOY_VS_NINJA_B_YOUNGNINJA_HPP


#include "Ninja.hpp"

namespace ariel{
    class YoungNinja: public Ninja {
        public:
            YoungNinja(string name, Point position) : Ninja(name, position, 100, 14){}
    };
}

#endif 