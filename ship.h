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
#include <algorithm>
using std::fill_n;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::cin;
#include <time.h>

struct coord
{
	coord() = default;
	coord(int xx, int yy);

	int x;
	int y;

	
};

bool operator==(const coord & a,const coord & b);

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
	public:
		void takeHit();
	};


public:

	ship(int x, int y, int type, bool vertical);
	vector<shipData> damage;
	int getSize();
	string getName();
	bool isGood();
	int getLife();
	void isHit();

private:
	
	int type; //1-5 for 5 ship types
	bool good = false;
	int life;
};
