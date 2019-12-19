#pragma once
#include <iostream>
#include <vector>
#include "PlayerManager.h"
#include "HeroManager.h"

using namespace std;

namespace sv {
	ofstream sessionList("sessionList.txt", ios::app);
}

class GameManager {
public:
	vector<Session> sessionList;

	int performGameSesion(vector<Player>& finders) {
		vector<TeamPart> toTeamPart(10);

		if (finders.size() < 10)
			return 0;

		//create a session object
		sessionList.resize(sessionList.size() + 1);
		int sessionNumber = sessionList.size();

		//player selection system
		int randomFinder = rand() % finders.size();
		toTeamPart[0].player = finders[randomFinder];
		finders.erase(finders.begin() + randomFinder);

		short int minRank = toTeamPart[0].player.getRank();
		short int maxRank = toTeamPart[0].player.getRank();
		short int nowCount = 1;

		//200 in same team
		//but dont 100 between teams

		while (true) {
			randomFinder = rand() % finders.size();
			if (nowCount < 10) {
				if (finders[randomFinder].getRank() < minRank + 200 && finders[randomFinder].getRank() > maxRank - 200) {
					toTeamPart[++nowCount - 1].player = finders[randomFinder];
					if (finders[randomFinder].getRank() > maxRank)
						maxRank = finders[randomFinder].getRank();
					if (finders[randomFinder].getRank() < minRank)
						minRank = finders[randomFinder].getRank();
					finders.erase(finders.begin() + randomFinder);
				}
			}
			if (nowCount == 10) {
				break;
			}
		}
		int randomHero = 0;

		vector<Hero> tHero(toHeroes.heroes.size());
		for (int i = 0; i < toHeroes.heroes.size(); i++) {
			tHero[i] = toHeroes.heroes[i];
		} //copy to create new hero vector.

		for (int i = 0; i < 10; i++) {
			randomHero = rand() % tHero.size();
			toTeamPart[i].hero = tHero[randomHero];
			tHero.erase(tHero.begin() + randomHero);
		} //randomize player-hero



		for (int i = 0, k = 0; i < 5; i++, k++) {
			sessionList[sessionNumber - 1].TeamRed[k] = toTeamPart[i];
		}
		for (int i = 5, k = 0; i < 10; i++, k++) {
			sessionList[sessionNumber - 1].TeamBlue[k] = toTeamPart[i];
		}

		return sessionNumber;
	}
	void endGameSession(int sessionNumber) {
		if (sessionNumber == 0)
			return;
		if (sessionList[sessionNumber - 1].getWinner() == true) {
			//winner is blue
			sv::sessionList << sessionList[sessionNumber - 1].getWinner() << endl;
			for (int i = 0; i < 5; i++) {
				int getID = sessionList[sessionNumber - 1].TeamBlue[i].player.getId();
				int num = toPlayers.getByID(getID);
				toPlayers.players[num].setRank(toPlayers.players[num].getRank() + 25);
				getID = sessionList[sessionNumber - 1].TeamRed[i].player.getId();
				num = toPlayers.getByID(getID);
				toPlayers.players[num].setRank(toPlayers.players[num].getRank() - 25);
			}
			cout << "Winner is blue!" << endl;
		}
		else if (sessionList[sessionNumber - 1].getWinner() == false) {
			//winner is red
			sv::sessionList << sessionList[sessionNumber - 1].getWinner() << endl;
			for (int i = 0; i < 5; i++) {
				int getID = sessionList[sessionNumber - 1].TeamRed[i].player.getId();
				int num = toPlayers.getByID(getID);
				toPlayers.players[num].setRank(toPlayers.players[num].getRank() + 25);
				getID = sessionList[sessionNumber - 1].TeamBlue[i].player.getId();
				num = toPlayers.getByID(getID);
				toPlayers.players[num].setRank(toPlayers.players[num].getRank() - 25);
			}
			cout << "Winner is red!" << endl;
		}
		for (int i = 0; i < 5; i++) {
			sv::sessionList << sessionList[sessionNumber - 1].TeamRed[i].player.name << endl;
		}
		for (int i = 0; i < 5; i++) {
			sv::sessionList << sessionList[sessionNumber - 1].TeamBlue[i].player.name << endl;
		}
		for (int i = 0; i < 5; i++) {
			sv::sessionList << sessionList[sessionNumber - 1].TeamRed[i].player.getRank() << endl;
		}
		for (int i = 0; i < 5; i++) {
			sv::sessionList << sessionList[sessionNumber - 1].TeamBlue[i].player.getRank() << endl;
		}
		for (int i = 0; i < 5; i++) {
			sv::sessionList << sessionList[sessionNumber - 1].TeamRed[i].player.getId() << endl;
		}
		for (int i = 0; i < 5; i++) {
			sv::sessionList << sessionList[sessionNumber - 1].TeamBlue[i].player.getId() << endl;
		}
		for (int i = 0; i < 5; i++) {
			sv::sessionList << sessionList[sessionNumber - 1].TeamRed[i].hero.name << endl;
		}
		for (int i = 0; i < 5; i++) {
			sv::sessionList << sessionList[sessionNumber - 1].TeamBlue[i].hero.name << endl;
		}
		sv::sessionList << "end" << endl;
	}
};

GameManager games;