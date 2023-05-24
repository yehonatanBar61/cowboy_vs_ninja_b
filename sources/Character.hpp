
#ifndef CPP_HW4_CHARACTER_HPP
#define CPP_HW4_CHARACTER_HPP


#include "Point.hpp"

namespace ariel{
    class Character {
        private:
            string name;
            Point location;
            int hitPoints;
            bool inTeam;

        public:
            Character();
            Character(string name, Point location, int points);
            bool isAlive() const;
            double distance(Character* other);
            void hit(int points);
            int getHitPoints() const;
            void setLocation(Point loc);
            bool isInTeam();
            void setInTeam();
            void print();
            string getName();
            Point getLocation();

            virtual ~Character() = default;

            Character(Character&); 
            Character (Character&& ) noexcept; 
    };
}

#endif
