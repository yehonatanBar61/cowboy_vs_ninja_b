#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "doctest.h"
using namespace std;

#include "sources/Team.hpp"

using namespace ariel;

TEST_CASE("Point") {
    Point a(33.5,34.5), b(33.6,33.7);
    // Shallow tests
    CHECK_NOTHROW(a.getX());
    CHECK_NOTHROW(a.getY());

    CHECK_EQ(b.getX(), 33.6);
    CHECK_EQ(b.getY(), 33.7);

    CHECK_EQ(a.print(), "(33.5,34.5)");
    CHECK_EQ(a.distance(b), 0.1);
}

TEST_CASE("Character") {
    Point a(33.5,34.5), b(33.6,33.7);
    Character char1("char1", a, 35) , char2("char2", b, 40);

    // check constructors doesnt throw
    CHECK_NOTHROW(Character());
    CHECK_NOTHROW(Character{"name", a, 40});

    CHECK(char1.isAlive());
    CHECK(char2.isAlive());

    CHECK_EQ(char1.getName(), "char1");

    CHECK_EQ(char1.distance(&char2), char2.distance(&char1));
    CHECK_EQ(char1.getHitPoint(), 35);
    CHECK_EQ(char2.getHitPoint(), 40);

    CHECK_EQ(char1.getLocation(), a);

}

TEST_CASE("Cowboy") {
    Point a(33.5,34.5), b(33.6,33.7);

    Cowboy cow1("Cowboy1", a);
    Cowboy cow2("Cowboy2", a);

    // check initial values for cowboy
    CHECK(cow1.hasboolets());
    CHECK(cow1.isAlive());
    CHECK_EQ(cow1.getHitPoint(), 110);
    CHECK_EQ(cow1.getBullets(), 6);
    
    CHECK_NOTHROW(cow1.shoot(&cow2));
    //after shooting he should have left 5 bullets
    CHECK_EQ(cow1.getBullets(), 5);
    //he sould be able to relaod
    CHECK_NOTHROW(cow1.reload());

    for(int i = 0; i < 6; i++){
        cow1.shoot(&cow2);
    }
    //after shooting 6 times he should have left 0 bullets
    CHECK_EQ(cow1.getBullets(), 0);
    CHECK(!cow1.hasboolets());
    // after cow1 chot cow2 6 times cow2 soud have left 110-60 = 50 bullets
    CHECK_EQ(cow2.getBullets(), 50);
    // sould be able to reload cow1
    CHECK_NOTHROW(cow1.reload());
    
}

TEST_CASE("Ninja") {
    Point a(33.5,34.5), b(33.6,33.7);
    Ninja n1("n1", a, 100, 1);
    Ninja n2("n2", b, 120, 14);
    CHECK_NOTHROW(n1.move(&n2));
     
    CHECK_NOTHROW(n1.slash(&n2));
    // slash 3 times to kill
    for(int i = 0; i < 3; i++){
        n1.slash(&n2);
    }
    // n2 sould be dead
    CHECK_FALSE(n2.isAlive());
    
    YoungNinja y("Young", a);
    CHECK_EQ(y.getHitPoint(), 100);
    CHECK_EQ(y.getSpeed(), 14);

    TrainedNinja t("Trained", a);
    CHECK_EQ(t.getHitPoint(), 120);
    CHECK_EQ(t.getSpeed(), 12);

    OldNinja o("Old", a);
    CHECK_EQ(o.getHitPoint(), 150);
    CHECK_EQ(o.getSpeed(), 8);
}

TEST_CASE("Team") {
    Point a(33.5,34.5), b(33.6,33.7), c(5,6);

    Ninja ninja("ninja", a, 100, 1);
    Cowboy Cowboy("Cowboy", c);
    YoungNinja YoungNinja("YoungNinja", b);

    //creating 2 teams
    Team team1(&ninja);
    Team team2(&YoungNinja);

    // cheak print
    CHECK_NOTHROW(team2.print());

    // sould be able to add char to the team
    CHECK_NOTHROW(team1.add(&Cowboy));
    // after adding there are 2 chars in the team
    CHECK_EQ(team1.stillAlive(), 2);

    CHECK_NOTHROW(team1.attack(&team2));
    
}
