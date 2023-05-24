#ifndef COWBOY_VS_NINJA_B_NINJA_HPP
#define COWBOY_VS_NINJA_B_NINJA_HPP

#include "Character.hpp"

namespace ariel{
    
    class Ninja: public Character {
    
    private:
        int speed;
    
    public:
        Ninja(string name, Point position, int hitPoint, int speed);
        void move(Character *enemy);
        void slash(Character *enemy);
        string print();
        int getSpeed();
    };
}

#endif