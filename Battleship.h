//Battleship.h
//Sam Erie and Aisha Peters
//
//For CS 372
//Project 1

#pragma once


#include <iostream>
using std::cout;

#include <algorithm>
using std::fill_n;

#include <vector>
using std::vector;

#include <string>
using std::string;



class ship
{
	struct shipData
	{
		shipData(int xx, int yy)
		{
			x = xx;
			y = yy;
		}
		int x, y;
		bool hit=false;
	};

	int type; //1-5 for 5 ship types
	
	
public:

	ship(int x, int y, int type, bool verticle);
	bool good = false;
	vector<shipData> damage;
	int getSize()
	{
		switch (type)
		{
		case 1: return 2;
		case 2: return 3;
		case 3: return 3;
		case 4: return 4;
		case 5: return 5;
		default: return -1;
		}

		return -1;
	}
	string getName()
	{
		switch (type)
		{
			case 1: return "Destroyer";	//size  --2
			case 2: return "Submarine";	//		--3
			case 3: return "Cruiser";	//		--3
			case 4: return "Battleship";	//	--4
			case 5: return "Carrier";		//	--5
			default: return "Error in getName(): This ship has no name";
		}

		return "Error in getName(): this ship has no type";
	}

};




class board
{
public:

	board();

	bool placeShip(ship &place);
	bool checkHit(int x, int y);
	void updateGrid(int hx, int hy);
//private:	need public for debugging

	char grid[10][10];
	vector<ship> playerShips;	//board filled when size = 5


};


class player
{
	board playerBoard;
};

class game
{	//this handles game prompts, all output to console of gfx done externally
	player user[2];
};
