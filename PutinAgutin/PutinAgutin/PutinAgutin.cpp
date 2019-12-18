#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
//bugs: 0?

/*ListOfHeroesm ListOfPlayers, ListOfSession реалізовані через глобальні вектори*/
/*Всі герої, гравці та сесії записуються у тектстові файли*/
//Не добавлено:перепис файлу з героями(при видаленні героя), перепис файлу з плеєрами(при видаленні, та зміні рангу)

using namespace std;

short int playerCount = 0;
short int heroCount = 0;

//toRead
namespace ss {
	ifstream sessionList("sessionList.txt");
	ifstream players("players.txt");
	ifstream heroes("heroes.txt");
}
//toWrite
namespace sv {
	ofstream sessionList("sessionList.txt", ios::app);
	ofstream players("players.txt", ios::app);
	ofstream heroes("heroes.txt", ios::app);
}

short int setHeroID() {
	return ++heroCount;
}

class Hero {
public:
	Hero() : id(setHeroID()) {
	}
	Hero(string name, int hp, short int damage, short int speed) :name(name), hp(hp),
		damage(damage), speed(speed), id(setHeroID()) {}
	void printInfo() {
		cout << "Hero: " << name << endl
			<< "HP: " << hp << endl
			<< "Damage: " << damage << endl
			<< "Speed: " << speed << endl
			<< "ID: " << id << endl;
	}
	string name;
	int hp;
	short int damage;
	short int speed;
	short int id;
private:

};
vector<Hero> heroes(0);

short int setID() {
	return ++playerCount;
}

class Player {
public:
	Player() :id(setID()), rank(1000) {}
	Player(string name) :name(name), rank(1000), id(setID()) {}

	void changeName() {
		cout << "Enter new name: " << flush;
		string name;
		cin >> name;
		this->name = name;
	}
	void changeName(string name) {
		this->name = name;
	}
	void printInfo() {
		cout << "Name: " << name << endl
			<< "Rank: " << rank << endl
			<< "ID: " << id << endl;
	}


	void setId(short int id) {
		this->id = id;
	}

	short int getId() {
		return id;
	}

	void setRank(short int rank) {
		this->rank = rank;
	}

	short int getRank() {
		return rank;
	}

	string name;
private:
	short int rank = 1000;
	short int id = 0;

};
vector<Player> players(0);

class PlayerManager {
public:
	void printPlayerByName(string name) {
		for (int i = 0; i < players.size(); i++) {
			if (name == players[i].name)
				players[i].printInfo();
		}
	}
	void printPlayerById(short int id) {
		for (int i = 0; i < players.size(); i++) {
			if (id == players[i].getId())
				players[i].printInfo();
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
	void addPlayer() {
		cout << "Enter name: " << flush;
		string name;
		cin >> name;
		players.resize(players.size() + 1);
		players[players.size() - 1].name = name;
		sv::players << name << endl;
		sv::players << 1000 << endl;
		sv::players << players[players.size() - 1].getId() << endl;
	}
	void removePlayer(short int number) {
		players.erase(players.begin() + number - 1);
	}
};
PlayerManager toPlayers;

class TeamPart {
public:
	TeamPart() {};
	TeamPart(Player player, Hero hero) :player(player), hero(hero) {}
	void printInfo() {
		cout << "Player: " << player.name << endl
			<< "Rank: " << player.getRank() << endl
			<< "Hero: " << hero.name << endl;
	}
	Player player;
	Hero hero;
private:

};
vector<TeamPart> toTeamPart(10);


class Session {
public:
	Session() {};
	void setWinner(bool i) {
		winner = i;
	}
	bool getWinner() {
		return winner;
	}

	TeamPart* TeamBlue = new TeamPart[5];
	TeamPart* TeamRed = new TeamPart[5];
	//vector<TeamPart> TeamRed(5);
	//vector<TeamPart> TeamBlue(5);
private:
	bool winner;
};
vector<Session> sessionList(0);

class HeroManager {
public:
	void printHeroByName(string name) {
		for (int i = 0; i < heroes.size(); i++) {
			if (heroes[i].name == name) {
				heroes[i].printInfo();
				break;
			}
		}
	}
	int getHeroByName(string name) {
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
	void addHero() {
		string name;
		short int damage, hp, speed;
		cout << "Enter name: " << flush;
		cin >> name;
		cout << "Enter hp: " << flush;
		cin >> hp;
		cout << "Enter damage: " << flush;
		cin >> damage;
		cout << "Enter speed: " << flush;
		cin >> speed;
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
		heroCount--;
	}
};
HeroManager toHeroes;

vector<Player> finders(0);
class GameManager {
public:

	int performGameSesion() {
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
			if (nowCount < 5) {
				if (finders[randomFinder].getRank() < minRank + 200 && finders[randomFinder].getRank() > maxRank - 200) {
					toTeamPart[++nowCount - 1].player = finders[randomFinder];
					finders.erase(finders.begin() + randomFinder);
				}
			}
			else if (nowCount >= 5 && nowCount < 10) {
				if (finders[randomFinder].getRank() < minRank + 200 && finders[randomFinder].getRank() > maxRank - 200) {
					toTeamPart[++nowCount - 1].player = finders[randomFinder];
					finders.erase(finders.begin() + randomFinder);
				}
			}
			if (nowCount == 10) {
				break;
			}
		}
		int randomHero = 0;

		vector<Hero> tHero(heroes.size());
		for (int i = 0; i < heroes.size(); i++) {
			tHero[i] = heroes[i];
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
				players[num].setRank(players[num].getRank() + 25);
				getID = sessionList[sessionNumber - 1].TeamRed[i].player.getId();
				num = toPlayers.getByID(getID);
				players[num].setRank(players[num].getRank() - 25);
			}
			cout << "Winner is blue!" << endl;
		}
		else if (sessionList[sessionNumber - 1].getWinner() == false) {
			//winner is red
			sv::sessionList << sessionList[sessionNumber - 1].getWinner() << endl;
			for (int i = 0; i < 5; i++) {
				int getID = sessionList[sessionNumber - 1].TeamRed[i].player.getId();
				int num = toPlayers.getByID(getID);
				players[num].setRank(players[num].getRank() + 25);
				getID = sessionList[sessionNumber - 1].TeamBlue[i].player.getId();
				num = toPlayers.getByID(getID);
				players[num].setRank(players[num].getRank() - 25);
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

int main()
{
	srand(time(0));


	string line;

	//read heroes
	for (int i = 0; getline(ss::heroes, line); i++) {
		heroes.resize(heroes.size() + 1);
		heroes[i].name = line;
		getline(ss::heroes, line);
		heroes[i].speed = atoi(line.c_str());
		getline(ss::heroes, line);
		heroes[i].damage = atoi(line.c_str());
		getline(ss::heroes, line);
		heroes[i].hp = atoi(line.c_str());
		getline(ss::heroes, line);
		heroes[i].id = atoi(line.c_str());
		heroCount = i;
	}//input heroes from text file to vector

	//output heroes
	/*for (int i = 0; i < heroes.size(); i++) {
		heroes[i].printInfo();
	}*/


	//read players
	for (int i = 0; getline(ss::players, line); i++) {
		players.resize(players.size() + 1);
		players[i].name = line;
		getline(ss::players, line);
		players[i].setRank(atoi(line.c_str()));
		getline(ss::players, line);
		players[i].setId(atoi(line.c_str()));
		playerCount = i;
	}//input players from text file to vector

	//output players
	/*for (int i = 0; i < 10; i++) {
		players[i].printInfo();
	}*/


	//read sessions
	//vector<Session> session(20);
	while (getline(ss::sessionList, line)) {
		sessionList.resize(sessionList.size() + 1);
		int i = sessionList.size() - 1;
		sessionList[i].setWinner(atoi(line.c_str())); //read winner(1 - blue, 0 - red)
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
			toTeamPart[j].hero.damage = heroes[toHeroes.getHeroByName(toTeamPart[j].hero.name)].damage;
			toTeamPart[j].hero.speed = heroes[toHeroes.getHeroByName(toTeamPart[j].hero.name)].speed;
			toTeamPart[j].hero.hp = heroes[toHeroes.getHeroByName(toTeamPart[j].hero.name)].hp;
		}
		for (int j = 0; j < 5; j++) {
			sessionList[i].TeamRed[j] = toTeamPart[j];
		}

		for (int j = 5, k = 0; j < 10; j++, k++) {
			sessionList[i].TeamBlue[k] = toTeamPart[j];
		}

		//sessionList.push_back(session[i]);
	}//input sessions from text file to vector
	for (int i = 0; i < sessionList.size(); i++) {
		cout << sessionList[i].getWinner() << endl;
		for (int j = 0; j < 5; j++) {
			sessionList[i].TeamRed[j].printInfo();
			sessionList[i].TeamBlue[j].printInfo();
		}
	}

	short int arrayPlayerRank[10] = { 1187, 1105, 1100, 1095, 1035, 1050, 1175, 1157, 1108, 1083 };
	for (int i = 0; i < 10; i++) {
		players[i].setRank(arrayPlayerRank[i]);
	}//to example



	//create a vector with players who find a match
	for (int i = 0; i < 10; i++) {
		finders.resize(finders.size() + 1);
		finders[i] = players[i];
	}//example

	 //десь тут предполагається створення вектора в який потоком, напевно, будуть 
	//записуватись плеєри, які шукають ігру, або їхні ID(но тоді трохи треба переписати цей гавно код)

	int sessionNumber = games.performGameSesion();
	//start game




	//end game
	sessionList[sessionNumber - 1].setWinner(0); //set winner

	games.endGameSession(sessionNumber);



	system("pause");

	ss::players.close();
	ss::heroes.close();
	ss::sessionList.close();
	sv::players.close();
	sv::heroes.close();
	sv::sessionList.close();
}
