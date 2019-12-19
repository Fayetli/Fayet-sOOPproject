#pragma once
#include <iostream>
#include <fstream>

using namespace std;

namespace sv {
	ofstream heroes("heroes.txt", ios::app);
}

class HeroManager {
public:
	vector<Hero> heroes;

	Hero getHeroByName(string name) {
		for (int i = 0; i < heroes.size(); i++) {
			if (heroes[i].name == name) {
				return heroes[i];
			}
		}
	}

	int getHeroNumByName(string name) {
		for (int i = 0; i < heroes.size(); i++) {
			if (heroes[i].name == name) {
				return i;
			}
		}
	}

	void addHero(string name, short int damage, short int hp, short int speed) {
		heroes.resize(heroes.size() + 1);
		heroes[heroes.size() - 1].name = name;
		heroes[heroes.size() - 1].hp = hp;
		heroes[heroes.size() - 1].damage = damage;
		heroes[heroes.size() - 1].speed = speed;

		sv::heroes << name << endl;
		sv::heroes << speed << endl;
		sv::heroes << damage << endl;
		sv::heroes << hp << endl;
		sv::heroes << heroes[heroes.size() - 1].id << endl;
	}

	void removeHero(short int number) {
		heroes.erase(heroes.begin() + number - 1);
		for (int i = 0; i < heroes.size(); i++) {
			heroes[i].id = i + 1;
		}
	}
};

HeroManager toHeroes;