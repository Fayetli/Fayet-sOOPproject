#pragma once
#include <iostream>
#include "TeamPart.h"

using namespace std;

class Session {
public:
	TeamPart* TeamBlue = new TeamPart[5];
	TeamPart* TeamRed = new TeamPart[5];

	Session() {};
	void setWinner(bool i) {
		winner = i;
	}
	bool getWinner() {
		return winner;
	}
private:
	bool winner;
};