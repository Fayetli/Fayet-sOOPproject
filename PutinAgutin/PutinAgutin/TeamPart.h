#pragma once
#include <iostream>

using namespace std;

class TeamPart {
public:
	TeamPart() {};
	TeamPart(Player player, Hero hero) :player(player), hero(hero) {}
	Player player;
	Hero hero;
private:

};