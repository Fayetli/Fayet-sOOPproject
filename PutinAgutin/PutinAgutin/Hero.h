#pragma once
#include <iostream>

using namespace std;

class Hero {
public:
	string name;
	int hp;
	static int count;
	short int damage;
	short int speed;
	short int id;

	Hero() : id(++count) {}
	Hero(string name, int hp, short int damage, short int speed) :name(name), hp(hp),
		damage(damage), speed(speed), id(++count) {}
private:

};