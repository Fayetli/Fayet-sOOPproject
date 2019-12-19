#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
//bugs: 0?
#include "Hero.h"
#include "Player.h"
#include "Session.h"
#include "TeamPart.h"
#include "HeroManager.h"
#include "PlayerManager.h"
#include "GameManager.h"

using namespace std;

/*Всі герої, гравці та сесії записуються у тектстові файли*/
namespace ss { //toRead
	ifstream sessionList("sessionList.txt");
	ifstream players("players.txt");
	ifstream heroes("heroes.txt");
}

int Hero::count = 0;

int Player::count = 0;

int main()
{
	srand(time(0));


	string line;

	//read heroes
	for (int i = 0; getline(ss::heroes, line); i++) {
		toHeroes.heroes.resize(toHeroes.heroes.size() + 1);
		toHeroes.heroes[i].name = line;
		getline(ss::heroes, line);
		toHeroes.heroes[i].speed = atoi(line.c_str());
		getline(ss::heroes, line);
		toHeroes.heroes[i].damage = atoi(line.c_str());
		getline(ss::heroes, line);
		toHeroes.heroes[i].hp = atoi(line.c_str());
		getline(ss::heroes, line);
		toHeroes.heroes[i].id = atoi(line.c_str());
	}//input heroes from text file to vector
	ss::heroes.close();

	//read players
	for (int i = 0; getline(ss::players, line); i++) {
		toPlayers.players.resize(toPlayers.players.size() + 1);
		toPlayers.players[i].name = line;
		getline(ss::players, line);
		toPlayers.players[i].setRank(atoi(line.c_str()));
		getline(ss::players, line);
		toPlayers.players[i].setId(atoi(line.c_str()));
	}//input players from text file to vector
	ss::players.close();

	//read sessions
	while (getline(ss::sessionList, line)) {
		vector<TeamPart> toTeamPart(10);
		games.sessionList.resize(games.sessionList.size() + 1);
		int i = games.sessionList.size() - 1;
		games.sessionList[i].setWinner(atoi(line.c_str())); //read winner(1 - blue, 0 - red)
		getline(ss::sessionList, line);
		for (int j = 0; j < 10; j++) {
			toTeamPart[j].player.name = line;
			getline(ss::sessionList, line);
		}

		for (int j = 0; j < 10; j++) {
			toTeamPart[j].player.setRank(atoi(line.c_str()));
			getline(ss::sessionList, line);
		}

		for (int j = 0; j < 10; j++) {
			toTeamPart[j].player.setId(atoi(line.c_str()));
			getline(ss::sessionList, line);
		}

		for (int j = 0; j < 10; j++) {
			toTeamPart[j].hero.name = line;
			getline(ss::sessionList, line);
		}
		for (int j = 0; j < 10; j++) {
			toTeamPart[j].hero.damage = toHeroes.heroes[toHeroes.getHeroNumByName(toTeamPart[j].hero.name)].damage;
			toTeamPart[j].hero.speed = toHeroes.heroes[toHeroes.getHeroNumByName(toTeamPart[j].hero.name)].speed;
			toTeamPart[j].hero.hp = toHeroes.heroes[toHeroes.getHeroNumByName(toTeamPart[j].hero.name)].hp;
		}
		for (int j = 0; j < 5; j++) {
			games.sessionList[i].TeamRed[j] = toTeamPart[j];
		}

		for (int j = 5, k = 0; j < 10; j++, k++) {
			games.sessionList[i].TeamBlue[k] = toTeamPart[j];
		}

	}//input sessions from text file to vector
	ss::sessionList.close();

	//////////////
	short int arrayPlayerRank[10] = { 1187, 1105, 1100, 1095, 1035, 1050, 1175, 1157, 1108, 1083 };
	for (int i = 0; i < 10; i++) {
		toPlayers.players[i].setRank(arrayPlayerRank[i]);
	}//to example
	//////////////

	vector<Player> finders(0);
	//create a vector with players who find a match
	for (int i = 0; i < 10; i++) {
		finders.resize(finders.size() + 1);
		finders[i] = toPlayers.players[i];
	}//example
	 //десь тут предполагається створення вектора в який потоком, напевно, будуть 
	//записуватись плеєри, які шукають ігру, або їхні ID(но тоді трохи треба переписати цей гавно код)

	int sessionNumber = games.performGameSesion(finders);
	//start game

	//end game
	games.sessionList[sessionNumber - 1].setWinner(0); //set winner

	games.endGameSession(sessionNumber);

	sv::players.close();
	sv::heroes.close();
	sv::sessionList.close();
}
