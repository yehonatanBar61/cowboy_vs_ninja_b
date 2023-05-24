#ifndef COWBOY_VS_NINJA_B_OLDNINJA_HPP
#define COWBOY_VS_NINJA_B_OLDNINJA_HPP


#include "Ninja.hpp"

namespace ariel{
    class OldNinja : public Ninja{
    public:
        OldNinja(string name, Point location) : Ninja(name, location, 150, 8) {}
    };
}


#endif