#include <iostream>
#include "Heroes.h"
#include "Hero.h"

using namespace std;

short int playerCount = 0;

Hero* pHero = new Hero[10];

string arrayHeroName[] = { "Bulda", "Kukla", "Petuh", "Zelda", "Oximiron",
                               "Danila", "Grush", "Apolon", "Luda", "Magila" };
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
        string name;
        cin >> name;
        this->name = name;
    }

    void printInfo() {
        cout << "Name: " << name << endl
            << "Rank: " << rank << endl
            << "ID: " << id << endl;
    }

    string name;
private:
    short int rank;
    short int id;

};

Player* pPlayer = new Player[10];

string arrayPlayerName[] = { "player1", "player2", "player3", "player4", "player5", "player6", "player7", "player8", "player9", "player10" };

void createPlayer() {
    for (short int i = 0; i < playerCount; i++) {
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

}

class Session {
public:
    Session() {

    }
    void setTeams() {
        
    }

    ~Session() {
        //write to log
        delete[] TeamRed;
        delete[] TeamBlue;
    }
    TeamPart *TeamRed = new TeamPart[5];
    TeamPart *TeamBlue = new TeamPart[5];
private:
    
};


class PlayerManager {
public:
    void getPlayerByName(string name) {
        for (int i = 0; i < playerCount; i++) {
            if (name == pPlayer[i].name)
                pPlayer[i].printInfo();
        }
    }
    void getPlayerById(short int id) {

    }
    void addPlayer() {

    }
    void removePlayer() {

    }
};

class HeroManager {

};

class GameManager {

};

void createTeam() {

}

int main()
{

   createHero();

   /*for (int i = 0; i < 10; i++) {
        pHero[i].printInfo();
        cout << endl;
    }*/

   
   createPlayer();

   /*for (int i = 0; i < playerCount; i++) {
       pPlayer[i].printInfo();
       cout << endl;
   }*/

    


   delete[] pPlayer;
   delete[] pHero;
}
