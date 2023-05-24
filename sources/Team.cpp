
#include <unordered_set>
#include "Team.hpp"


namespace ariel {

    // constructors:
    Team::Team() : leader(new Character()){
        leader->setInTeam();
        this->teaMates.push_back(leader);
    }

    Team::Team(Character *leader) : leader(leader) {
        if (leader->isInTeam())
            throw runtime_error("[!] Leader already in a team");
        this->teaMates.push_back(leader);
        leader->setInTeam();
    }


    void Team::add(Character *mem) {
        if (mem->isInTeam())
            throw std::runtime_error("[!] Character already in a team");
        if (teaMates.size() >= 10)
            throw std::runtime_error("[!] Team already has 10 members");
        Cowboy* chare = dynamic_cast<Cowboy*>(mem);
        if (chare) {
            teaMates.insert(teaMates.end(), chare);
        } else {
            teaMates.insert(teaMates.begin(), mem);
        }
        mem->setInTeam();
    }

    void Team::attack(Team *enemyT) {

        // Checking edge cases:
        if (enemyT == nullptr)
            throw invalid_argument("[!] enemy Team cant be null");

        if (this->stillAlive() == 0)
            throw runtime_error("[!] attacking with no live members");

        if (enemyT->stillAlive() == 0)
            throw runtime_error("[!] attacking team with no leaving members");
        
        if (this == enemyT)
            throw runtime_error("[!] attacking the myself");
        
        // if need to find new leader, finding the closest to the priveus
        if (!leader->isAlive()) {
            Character *closestCharacter = updateLeader();
            leader = closestCharacter;
        }

        Character *Target = chooseEnemy(enemyT->teaMates);

        //iterating throw all members in the team and implementing the attack
        for (Character *mem: this->teaMates) {
            if (Target != nullptr) {
                if (mem->isAlive()) {

                    // detecting the type of character and initiating the relevent attack
                    if (auto *cowboy = dynamic_cast<Cowboy *>(mem)) {
                        cowboy->shoot(Target);
                    }
                    else if (auto *ninja = dynamic_cast<Ninja *>(mem)) {
                        if (ninja->distance(Target) < 1.0) 
                            ninja->slash(Target);
                        else 
                            ninja->move(Target);      
                    }

                }
            }else {
                cout << "Enemy team neutralized" << endl;
                return;
            }
            if (!Target->isAlive())
                Target = chooseEnemy(enemyT->teaMates);
        }
    }


    Character *Team::updateLeader() {
        Character *newLeader = nullptr;
        double minDis = MAXFLOAT;
        for (Character *member: this->teaMates) {
            double dis = leader->distance(member);
            if (dis < minDis && leader != member && member->isAlive()) {
                minDis = dis;
                newLeader = member;
            }
        }
        return newLeader;
    }

    Character *Team::chooseEnemy(const vector<ariel::Character *> &mem) {
        double minDis = MAXFLOAT;
        Character *newEnemy = nullptr;
        for (Character *enemy: mem) {
            if (enemy->isAlive()) {
                double dis = leader->distance(enemy);
                if (dis < minDis) {
                    minDis = dis;
                    newEnemy = enemy;
                }
            }
        }
        return newEnemy;
    }

    int Team::stillAlive() const{
        int counter = 0;
        for (const Character* member : this->teaMates) {
            if (member->isAlive()) {
                counter++;
            }
        }
        return counter;
    }


    vector<Character *> Team::getTeaMates() const{
        return this->teaMates;
    }

    void Team::addMember(Character *mem) {
        this->teaMates.push_back(mem);
    }

    Character *Team::getLeader() const{
        return leader;
    }

    void Team::setLeader(Character *leader) {
        this->leader = leader;
    }

    void Team::print() const{
        for (Character *member: this->teaMates) {
            member->print();
        }
    }


    Team::~Team() {
        for (Character *member: this->teaMates) {
            delete member;
        }
    }

}