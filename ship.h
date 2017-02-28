//ship.h
//Sam Erie and Aisha Peters
//
//For CS 372
//Project 1

#pragma once
#include <string>
using std::string;
#include <vector>
using std::vector;

class ship
{
private:

	struct shipData
	{
		shipData(int xx, int yy)
		{
			x = xx;
			y = yy;
		}
		int x, y;
		bool hit = false;
	};


public:

	ship(int x, int y, int type, bool vertical);
	vector<shipData> damage;
	int getSize();
	string getName();
	bool isGood();

private:
	int type; //1-5 for 5 ship types
	bool good = false;
};
