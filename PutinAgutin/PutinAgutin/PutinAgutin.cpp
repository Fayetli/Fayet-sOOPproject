#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <dos.h>
#include <stdio.h>
#include <fstream>
//bugs: 0?
using namespace std;

short int playerCount = 0;
short int heroCount = 0;

fstream sessionList("sessionList.txt", ios::app);

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

void setStartTime() {
    //waves
}
class gameManager;
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
    int getByID(int id) {
        for (int i = 0; i < pPlayer.size(); i++) {
            if (id == pPlayer[i].getId())
                return i;
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
PlayerManager players;
class Session {
public:
    Session() {}

    ~Session() {
        //write to log
        for (int i = 0; i < 5; i++) {
            sessionList << TeamRed[i].player.name << endl;
            sessionList << TeamRed[i].player.getRank() << endl;
            sessionList << TeamRed[i].player.getId() << endl;
            sessionList << TeamRed[i].hero.name << endl;
        }
        for (int i = 0; i < 5; i++) {
            sessionList << TeamBlue[i].player.name << endl;
            sessionList << TeamBlue[i].player.getRank() << endl;
            sessionList << TeamBlue[i].player.getId() << endl;
            sessionList << TeamBlue[i].hero.name << endl;
        }
        if (getWinner() == true) {
            //winner is blue
            sessionList << winner << endl;
            for (int i = 0; i < 5; i++) {
                int getID = this->TeamBlue[i].player.getId();
                int num = 0;
                cout << "ID: " << getID << endl;
                num = players.getByID(getID);
                cout << "Num: " << num << endl;
                pPlayer[num].setRank(pPlayer[num].getRank() + 25);
                getID = this->TeamRed[i].player.getId();
                cout << "ID: " << getID << endl;
                num = players.getByID(getID);
                cout << "Num: " << num << endl;
                pPlayer[num].setRank(pPlayer[num].getRank() - 25);
                
            }
            cout << "Winner is blue!" << endl;
        }
        else if(getWinner() == false){
            //winner is red
            sessionList << winner << endl;
            for (int i = 0; i < 5; i++) {
                int getID = this->TeamRed[i].player.getId();
                int num = 0;
                cout << "ID: " << getID << endl;
                num = players.getByID(getID);
                cout << "Num: " << num << endl;
                pPlayer[num].setRank(pPlayer[num].getRank() + 25);
                getID = this->TeamBlue[i].player.getId();
                cout << "ID: " << getID << endl;
                num = players.getByID(getID);
                cout << "Num: " << num << endl;
                pPlayer[num].setRank(pPlayer[num].getRank() - 25);
            }
            cout << "Winner is red!" << endl;
        }
        cout << "Eeeeeend!" << endl;
        

        delete[] TeamRed;
        delete[] TeamBlue;
    }
    void setWinner(bool i) {
        winner = i;
    }
    bool getWinner() {
        return winner;
    }
    TeamPart *TeamBlue = new TeamPart[5];
    TeamPart *TeamRed = new TeamPart[5];
private:
    bool winner;
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
public:
    vector<Session> sessionList;//waves
};

void createTeam() {
    //waves
}

int main()
{
   srand(time(0));

   createHero();
   //create 10 standart hero and player
   createPlayer();

   HeroManager heroes;
   //heroes manager

   heroes.removeHero(5); //waves changes
   heroes.addHero("Kekal`", 550, 50, 250);

   PlayerManager players;
   //players manager

   players.removePlayer(5); //waves changes
   players.addPlayer("Volodya");

   for (int i = 0; i < pHero.size(); i++) {
       pHero[i].printInfo();
       cout << endl;
   } //waves output

   for (int i = 0; i < pPlayer.size(); i++) {
       pPlayer[i].printInfo();
       cout << endl;
   } //waves output

   short int arrayPlayerRank[10] = {1187, 1105, 1100, 1095, 1035, 1050, 1175, 1157, 1108, 1083};
   for (int i = 0; i < 10; i++) {
       pPlayer[i].setRank(arrayPlayerRank[i]);
   }//to example
   for (int i = 0; i < pPlayer.size(); i++) {
       pPlayer[i].printInfo();
       cout << endl;
   } //waves output


    int findersCount = 10;//example
    vector<Player> finders(10);//create a vector with players who find a match
    for (int i = 0; i < findersCount; i++) {
    finders[i] = pPlayer[i];
    }//example
     //must to create a system to add a player who find a match and... online in thread
    
    //session in thead
   {
    vector<Session> pSession (0);



    //create a session object
    //when created session
    pSession.resize(pSession.size() + 1);
    int sessionNumber = pSession.size();
    cout << sessionNumber << endl;
       //create session

       vector<TeamPart> toTeamPart(10);
       //player selection system
       int randomFinder = rand() % finders.size();
       toTeamPart[0].player = finders[randomFinder];
       finders.erase(finders.begin() + randomFinder);

       short int minRank = toTeamPart[0].player.getRank();
       short int maxRank = toTeamPart[0].player.getRank();
       short int nowCount = 1;

       while (true) {
           randomFinder = rand() % finders.size();
           //cout << randomFinder << endl;
           if (nowCount < 5) {
               if (finders[randomFinder].getRank() < minRank + 200 && finders[randomFinder].getRank() > maxRank - 200) {
                   toTeamPart[++nowCount - 1].player = finders[randomFinder];
                   finders.erase(finders.begin() + randomFinder);
                   toTeamPart[nowCount - 1].printInfo();
               }
           }
           else if (nowCount >= 5 && nowCount < 10) {
               if (finders[randomFinder].getRank() < minRank + 200 && finders[randomFinder].getRank() > maxRank - 200) {
                   toTeamPart[++nowCount - 1].player = finders[randomFinder];
                   finders.erase(finders.begin() + randomFinder);
                   toTeamPart[nowCount - 1].printInfo();
               }
           }
           if (nowCount == 10) {
               break;
           }
           cout << nowCount << endl;
       }
       cout << "End" << endl;
       int randomHero = 0;

       vector<Hero> tHero(pHero.size());
       for (int i = 0; i < pHero.size(); i++) {
           tHero[i] = pHero[i];
       } //copy to create new hero vector.
     
       for (int i = 0; i < 10; i++) {
           randomHero = rand() % tHero.size();
           toTeamPart[i].hero = tHero[randomHero];
           tHero.erase(tHero.begin() + randomHero);
       } //randomize player-hero
       
       for (int i = 0; i < 10; i++) {
           toTeamPart[i].printInfo();
           cout << endl;
       } //output

       cout << "kek" << endl;
       int k = 0;
       for (int i = 0; i < 5; i++, k++) {
           pSession[sessionNumber - 1].TeamRed[k] = toTeamPart[i];
       }
       k = 0;
       for (int i = 5; i < 10; i++, k++) {
           pSession[sessionNumber - 1].TeamBlue[k] = toTeamPart[i];
       }
       cout << "lol" << endl;


       pSession[sessionNumber - 1].setWinner(0);












       
   }
   









   system("pause");

   sessionList.close();
}
