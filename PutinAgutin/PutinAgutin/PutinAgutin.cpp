#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
//bugs: 0?
using namespace std;

short int playerCount = 0;
short int heroCount = 0;

namespace ss {
    ifstream sessionList("sessionList.txt");
    ifstream players("players.txt");
    ifstream heroes("heroes.txt");
}
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

vector<Hero> heroes(0);
string arrayHeroName[] = { "Bulda", "Kukla", "Petuh", "Zelda", "Oximiron",
                               "Danila", "Grush", "Apolon", "Propka", "Magila" };
short int arrayHeroHP[] = { 830, 760, 730, 800, 790, 750, 760, 770, 900, 690 };
short int arraHeroDamage[] = { 73,  70,  65,  67,  73,  80,  83,  85,  66,  74 };
short int arrayHeroSpeed[] = { 230, 245, 280, 250, 250, 230, 225, 220, 220, 250 };

void createHero() {
    for (short int i = 0; i < 10; i++) {
        heroes[i].name = arrayHeroName[i];
        heroes[i].hp = arrayHeroHP[i];
        heroes[i].damage = arraHeroDamage[i];
        heroes[i].speed = arrayHeroSpeed[i];
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
vector<Player> players(10);

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
    }
    void addPlayer() {
        cout << "Enter name: " << flush;
        string name;
        cin >> name;
        players.resize(players.size() + 1);
        players[players.size() - 1].name = name;
    }
    void removePlayer(short int number) {
        players.erase(players.begin() + number - 1);
    }
};
string arrayPlayerName[] = { "player1", "player2", "player3", "player4", "player5", "player6", "player7", "player8", "player9", "player10" };

void createPlayer() {
    for (short int i = 0; i < 10; i++) {
        players[i].name = arrayPlayerName[i];
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

PlayerManager toPlayers;

class Session {
public:
    Session() {}

    ~Session() {
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
class GameManager {
public:
    GameManager(){}
    

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



int main()
{
   srand(time(0));

   int numberOfLine = 1;
   int i = 0;
   string line;
   while (getline(ss::heroes, line)) {
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
           i++;
   }//input heroes from text file to vector

   /*for (int i = 0; i < 10; i++) {
       heroes[i].printInfo();
   }*/

   i = 0;
   while (getline(ss::players, line)) {
           players.resize(players.size() + 1);
           players[i].name = line;
           getline(ss::players, line);
           players[i].setRank(atoi(line.c_str()));
           getline(ss::players, line);
           players[i].setId(atoi(line.c_str()));
           i++;
   }//input players from text file to vector
   /*for (int i = 0; i < 10; i++) {
       players[i].printInfo();
   }*/

   //i = 0;
   //while (getline(ss::sessionList, line)) {
   //    sessionList.resize(sessionList.size() + 1);
   //    sessionList[i].setWinner(atoi(line.c_str()));
   //    getline(ss::sessionList, line);
   //    for (int j = 0; j < 5; j++) {
   //        sessionList[i].TeamRed[j].player.name = line;
   //        getline(ss::sessionList, line);
   //        sessionList[i].TeamRed[j].player.setRank(atoi(line.c_str()));
   //        getline(ss::sessionList, line);
   //        sessionList[i].TeamRed[j].player.setId(atoi(line.c_str()));
   //        getline(ss::sessionList, line);
   //        sessionList[i].TeamRed[j].hero.name = line;
   //        getline(ss::sessionList, line);
   //    }
   //    for (int j = 0; j < 5; j++) {
   //        sessionList[i].TeamBlue[j].player.name = line;
   //        getline(ss::sessionList, line);
   //        sessionList[i].TeamBlue[j].player.setRank(atoi(line.c_str()));
   //        getline(ss::sessionList, line);
   //        sessionList[i].TeamBlue[j].player.setId(atoi(line.c_str()));
   //        getline(ss::sessionList, line);
   //        sessionList[i].TeamBlue[j].hero.name = line;
   //        getline(ss::sessionList, line);
   //    }

   //    i++;
   //}//input sessions from text file to vector//deosn`t work
   //for (int i = 0; i < sessionList.size(); i++) {
   //    cout << sessionList[i].getWinner();
   //}




   short int arrayPlayerRank[10] = {1187, 1105, 1100, 1095, 1035, 1050, 1175, 1157, 1108, 1083};
   for (int i = 0; i < 10; i++) {
       players[i].setRank(arrayPlayerRank[i]);
   }//to example


    int findersCount = 10;//example
    vector<Player> finders(10);//create a vector with players who find a match
    for (int i = 0; i < findersCount; i++) {
    finders[i] = players[i];
    }//example
     //must to create a system to add a player who find a match and...
    
   




    //create a session object
    sessionList.resize(sessionList.size() + 1);
    int sessionNumber = sessionList.size();
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

       vector<Hero> tHero(heroes.size());
       for (int i = 0; i < heroes.size(); i++) {
           tHero[i] = heroes[i];
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
           sessionList[sessionNumber - 1].TeamRed[k] = toTeamPart[i];
       }
       k = 0;
       for (int i = 5; i < 10; i++, k++) {
           sessionList[sessionNumber - 1].TeamBlue[k] = toTeamPart[i];
       }
       cout << "lol" << endl;


       sessionList[sessionNumber - 1].setWinner(0);




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

       cout << "Eeeeeend!" << endl;
       for (int i = 0; i < 5; i++) {
           sv::sessionList << sessionList[sessionNumber - 1].TeamRed[i].player.name << endl;
           sv::sessionList << sessionList[sessionNumber - 1].TeamRed[i].player.getRank() << endl;
           sv::sessionList << sessionList[sessionNumber - 1].TeamRed[i].player.getId() << endl;
           sv::sessionList << sessionList[sessionNumber - 1].TeamRed[i].hero.name << endl;
       }
       for (int i = 0; i < 5; i++) {
           sv::sessionList << sessionList[sessionNumber - 1].TeamBlue[i].player.name << endl;
           sv::sessionList << sessionList[sessionNumber - 1].TeamBlue[i].player.getRank() << endl;
           sv::sessionList << sessionList[sessionNumber - 1].TeamBlue[i].player.getId() << endl;
           sv::sessionList << sessionList[sessionNumber - 1].TeamBlue[i].hero.name << endl;
       }
       sv::sessionList << endl;







   system("pause");

   ss::players.close();
   ss::heroes.close();
   ss::sessionList.close();
}
