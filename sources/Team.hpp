
#ifndef COWBOY_VS_NINJA_A_TEAM_HPP
#define COWBOY_VS_NINJA_A_TEAM_HPP

#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <cmath>
#include <algorithm>

using namespace std;
namespace ariel {
    class Team {
        private:
            vector<Character *> teaMates;
            Character *leader;
            
        public:
            Team();
            Team(Character *leader);
            ~Team();
            void add(Character *mem);
            int stillAlive() const;
            Character* chooseEnemy(const vector<Character*>& mem);
            void attack(Team *enemyT);
            vector<Character *> getTeaMates() const;
            void setLeader(Character* leader);
            Character* getLeader() const;
            Character* updateLeader();
            void addMember(Character* mem);
            void print() const;
            //copy constructors
            Team (Team&) = delete; 
            Team (Team&&) noexcept = delete;
            
    };
}

#endif //CPP_HW4_TEAM_HPP
