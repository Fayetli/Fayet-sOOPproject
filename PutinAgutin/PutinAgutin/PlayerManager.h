#pragma once
#include <iostream>
#include <fstream>

using namespace std;

namespace sv {
	ofstream players("players.txt", ios::app);
}

class PlayerManager {
public:
	vector<Player> players;
	
	Player getPlayerByName(string name) {
		for (int i = 0; i < players.size(); i++) {
			if (name == players[i].name)
				return players[i];
		}
	}

	Player getPlayerById(int id) {
		for (int i = 0; i < players.size(); i++) {
			if (id == players[i].getId())
				return players[i];
		}
	}

	int getByID(int id) {
		for (int i = 0; i < players.size(); i++) {
			if (id == players[i].getId())
				return i;
		}
	}

	void addPlayer(string name) {
		players.resize(players.size() + 1);
		players[players.size() - 1].name = name;
		sv::players << name << endl;
		sv::players << 1000 << endl;
		sv::players << players[players.size() - 1].getId() << endl;
	}

	void removePlayer(int number) {
		players.erase(players.begin() + number - 1);
	}
};

PlayerManager toPlayers;