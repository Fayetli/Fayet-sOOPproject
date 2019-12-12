#include <iostream>
#include <vector>
#include "Heroes.h"
#include "Hero.h"
//bugs: 0?
using namespace std;

short int playerCount = 0;
short int heroCount = 0;

short int setHeroID() {
    return ++heroCount;
}

class Hero {
public:
    Hero() : id(setHeroID()) {}
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

vector<Hero> pHero(10);
string arrayHeroName[] = { "Bulda", "Kukla", "Petuh", "Zelda", "Oximiron",
                               "Danila", "Grush", "Apolon", "Propka", "Magila" };
short int arrayHeroHP[] = { 830, 760, 730, 800, 790, 750, 760, 770, 900, 690 };
short int arraHeroDamage[] = { 73,  70,  65,  67,  73,  80,  83,  85,  66,  74 };
short int arrayHeroSpeed[] = { 230, 245, 280, 250, 250, 230, 225, 220, 220, 250 };

void createHero() {
    for (short int i = 0; i < 10; i++) {
        pHero[i].name = arrayHeroName[i];
        pHero[i].hp = arrayHeroHP[i];
        pHero[i].damage = arraHeroDamage[i];
        pHero[i].speed = arrayHeroSpeed[i];
    }
}

short int setID() {
    return ++playerCount;
}

class Player {
public:
    Player() :id(setID()), rank(1000){}
    Player(string name):name(name),rank(1000),id(setID()) {}

    void changeName() {
        cout << "Enter new name: " << flush;
        string name;
        cin >> name;
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
    short int rank;
    short int id;

};

vector<Player> pPlayer(10);
string arrayPlayerName[] = { "player1", "player2", "player3", "player4", "player5", "player6", "player7", "player8", "player9", "player10" };

void createPlayer() {
    for (short int i = 0; i < 10; i++) {
        pPlayer[i].name = arrayPlayerName[i];
    }
}

class TeamPart {
public:
    TeamPart();
    TeamPart(Player player, Hero hero) :player(player), hero(hero) {}
private:
    Player player;
    Hero hero;
};

void setStartTime() {
    //waves
}

class Session {
public:
    Session() {
        //waves
    }
    void setTeams() {
        //waves
    }

    ~Session() {
        //write to log //waves
        delete[] TeamRed;
        delete[] TeamBlue;
    }
    TeamPart *TeamRed = new TeamPart[5];
    TeamPart *TeamBlue = new TeamPart[5];
private:
    
};


class PlayerManager {
public:
    void printPlayerByName(string name) {
        for (int i = 0; i < pPlayer.size(); i++) {
            if (name == pPlayer[i].name)
                pPlayer[i].printInfo();
        }
    }
    void printPlayerById(short int id) {
        for (int i = 0; i < pPlayer.size(); i++) {
            if (id == pPlayer[i].getId())
                pPlayer[i].printInfo();
        }
    }
    void addPlayer(string name) {
        pPlayer.resize(pPlayer.size() + 1);
        pPlayer[pPlayer.size() - 1].name = name;
    }
    void addPlayer() {
        cout << "Enter name: " << flush;
        string name;
        cin >> name;
        pPlayer.resize(pPlayer.size() + 1);
        pPlayer[pPlayer.size() - 1].name = name;
    }
    void removePlayer(short int number) {
        pPlayer.erase(pPlayer.begin() + number - 1);
    }
};

class HeroManager {
public:
    void printHeroByName(string name) {
        for (int i = 0; i < pHero.size(); i++) {
            if (pHero[i].name == name) {
                pHero[i].printInfo();
                break;
            }
        }
    }
    void addHero(string name, short int damage, short int hp, short int speed) {
        pHero.resize(pHero.size() + 1);
        pHero[pHero.size() - 1].name = name;
        pHero[pHero.size() - 1].hp = hp;
        pHero[pHero.size() - 1].damage = damage;
        pHero[pHero.size() - 1].speed = speed;
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
        pHero.resize(pHero.size() + 1);
        pHero[pHero.size() - 1].name = name;
        pHero[pHero.size() - 1].hp = hp;
        pHero[pHero.size() - 1].damage = damage;
        pHero[pHero.size() - 1].speed = speed;
    }
    void removeHero(short int number) {
        pHero.erase(pHero.begin() + number - 1);
        for (int i = 0; i < pHero.size(); i++) {
            pHero[i].id = i + 1;
        }
        heroCount--;
    }
};

class GameManager {
    //waves
};

void createTeam() {
    //waves
}

int main()
{

   createHero();
   
   createPlayer();

   HeroManager heroes;
   //a.addHero();
   heroes.removeHero(5);
   heroes.addHero("Kekal`", 550, 50, 250);

   PlayerManager players;
   //b.addPlayer();
   players.removePlayer(5);
   players.addPlayer("Volodya");

   for (int i = 0; i < pHero.size(); i++) {
       pHero[i].printInfo();
       cout << endl;
   }

   for (int i = 0; i < pPlayer.size(); i++) {
       pPlayer[i].printInfo();
       cout << endl;
   }


}
