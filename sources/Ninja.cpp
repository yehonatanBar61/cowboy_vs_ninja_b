#include "Ninja.hpp"

using namespace std;

namespace ariel{
    // constructor:
    Ninja::Ninja(string name, Point position, int hitPoint, int speed) : Character(name, position, hitPoint), speed(speed) {}

    //move uses the moveTowards method from point to get the new location
    void Ninja::move(Character *enemy) {
        if(isAlive() && enemy->isAlive()){
            Point new_location = this->getLocation().moveTowards(this->getLocation(), enemy->getLocation(), this->getSpeed());
            this->setLocation(new_location);
        }else{
            throw std::runtime_error("[!] the ninja and the enemy need to be alive");
        }
        
    }

    void Ninja::slash(Character *enemy) {
        if(this == enemy)
            throw runtime_error("[!] Cant harm yourself");
        else if(!enemy->isAlive())
            throw runtime_error("[!] Enemy Ninja is dead");
        else if(!isAlive())
            throw runtime_error("[!] Ninja is dead");
        else if (isAlive() && this->distance(enemy) < 1)
            enemy->hit(40);
    }



    string Ninja::print(){
        if (!isAlive())
            return "Ninja = [" + getName() + "] ";
        else
            return "Ninja = " + this->getName() + ", Hit points: " + to_string(this->getHitPoints()) + ", Location: (" +
                to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getY()) + ")\n";
    }

    int Ninja::getSpeed(){
        return this->speed;
    }
}


