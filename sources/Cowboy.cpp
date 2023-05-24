#include "Cowboy.hpp"

using namespace std;

namespace ariel{

    // constructor
    Cowboy::Cowboy(string name, Point position) : Character(name, position, 110), bullets(6) {}

    void Cowboy::shoot(Character *enemy) {
        if(!enemy->isAlive()){
            throw runtime_error("[!] Attacking a dead character");
        }else if(this == enemy)
            throw runtime_error("[!] cant shoot myself");
        else if(!this->isAlive())
            throw runtime_error("[!] Cowboy is dead");

        if (this->hasboolets()) {
            this->bullets--;
            enemy->hit(10);
        } else{
            this->reload();
        }
    }

    bool Cowboy::hasboolets() {
        if (this->bullets > 0)
            return true;
        else
            return false;
    }

    void Cowboy::reload() {
        if(!this->isAlive()){
            throw runtime_error("[!] Dead cowboy cant reload");
        }
        this->bullets = 6;
    }


    string Cowboy::print(){
        if (!isAlive())
            return "Cowboy = (" + this->getName() + ")";
        else {
            return "Cowboy = " + this->getName() + ", points left: " + to_string(this->getHitPoints());
        }
    }

    int Cowboy::getBullets() {
        return this->bullets;
    }
}

