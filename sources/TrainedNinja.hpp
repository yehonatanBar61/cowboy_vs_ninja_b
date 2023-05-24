#ifndef COWBOY_VS_NINJA_B_TRAINEDNINJA_HPP
#define COWBOY_VS_NINJA_B_TRAINEDNINJA_HPP


#include "Ninja.hpp"

namespace ariel{
    class TrainedNinja : public Ninja{
        public:
            TrainedNinja(string name, Point position) : Ninja(name, position, 120, 12) {}
    };
}


#endif