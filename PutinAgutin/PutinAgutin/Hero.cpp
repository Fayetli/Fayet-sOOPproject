#include "Hero.h"

short int heroCount = 0;

short int setHeroID() {
	return ++heroCount;
}

void Hero::printInfo() {
	cout << "Hero: " << name << endl
		<< "HP: " << hp << endl
		<< "Damage: " << damage << endl
		<< "Speed: " << speed << endl
		<< "ID: " << id << endl;
}
