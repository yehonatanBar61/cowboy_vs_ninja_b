#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Point.hpp"
#include "Character.hpp"

namespace ariel
{

    class Cowboy: public Character {
        private:
            int bullets;

        public:
            /*
                A cowboy always spawns with 6 bullets and 110 hit points
            */
            Cowboy(string name, Point position);
            /*
                If the cowboy is not dead and has bullets left, the cowboy shoots the enemy, 
                subtracting 10 hit points from the enemy - and losing 1 bullet.
                Otherwise, no damage will be done to the enemy
            */
            void shoot(Character *enemy);
            bool hasboolets();
            void reload();
            string print();
            int getBullets();
    };
}

#endif