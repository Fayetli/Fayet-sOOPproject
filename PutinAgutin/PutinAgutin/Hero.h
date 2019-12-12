#ifndef HERO_H
#define HERO_H

#include <iostream>

using namespace std;

short int setHeroID();

class Hero {
public:
    Hero(): id(setHeroID()) {}
    Hero(string name, int hp, short int damage, short int speed) :name(name), hp(hp),
                 damage(damage), speed(speed), id(setHeroID()){}

    void printInfo();
    string name;
    int hp;
    short int damage;
    short int speed;
    short int id;
private:

};

#endif