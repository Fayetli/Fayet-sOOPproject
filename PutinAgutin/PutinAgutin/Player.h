#pragma once
#include <iostream>

using namespace std;


class Player {
public:
	string name;
	static int count;

private:
	short int rank;
	int id;

public:
	Player() :id(++count), rank(1000) {}
	Player(string name) :name(name), rank(1000), id(++count) {}

	void changeName(string name) {
		this->name = name;
	}

	void setId(short int id) {
		this->id = id;
	}

	int getId() {
		return id;
	}

	void setRank(short int rank) {
		this->rank = rank;
	}

	short int getRank() {
		return rank;
	}
};