
#include "Team2.hpp"





namespace ariel{
    Team2::Team2() : Team(){}
    Team2::Team2(Character *leader) : Team(leader){}

    void Team2::add(Character * member) {
        if (member->isInTeam())
            throw runtime_error("[!] already in a team");
        if (this->getTeaMates().size() < 10) {
            member->setInTeam();
            addMember(member);
        } else
            throw runtime_error("[!] the team is full");
    }
}