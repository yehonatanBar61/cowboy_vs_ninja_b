#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Character.hpp"
#include <unordered_set>
#include   <cxxabi.h>

namespace ariel{
   // constructors:
    Character::Character() :name("yehonatan"), location(Point(0,0)), hitPoints(0) , inTeam(false){}

    Character::Character(string name, Point position, int HitCounter) : name(name), location(position), hitPoints(HitCounter) ,inTeam(false){}

    // functions
    bool Character::isAlive() const{
        if(this->getHitPoints() > 0){
            return true;
        }
        return false;
    }

    double Character::distance(Character *character) {
        return this->location.distance(character->location);
    }

    void Character::hit(int num) {
        if(num < 0){
            throw invalid_argument("Cant hit negative");
        }
        this->hitPoints -= num;
    }

    string Character::getName(){
        return this->name;
    }

    Point Character::getLocation(){
        return this->location;
    }

    int Character::getHitPoints() const{
        return this->hitPoints;
    }

    void Character::print(){
        if (Cowboy *cowboy = dynamic_cast<Cowboy*> (this)) {
            cout << cowboy->print();
        } else if (Ninja *ninja = dynamic_cast<Ninja*> (this)) {
            cout << ninja->print();
        }   
    }

    void Character::setLocation(Point loc){
        this->location = loc;
    }

    bool Character::isInTeam(){
        return this->inTeam;
    }

    void Character::setInTeam(){
        this->inTeam = true;
    } 
}



