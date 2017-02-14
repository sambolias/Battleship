#pragma once


#include <iostream>
using std::cout;

#include <algorithm>
using std::fill_n;

#include <vector>
using std::vector;



class ship
{
	bool verticle;	//true = verticle, false = horizontal
	int x, y;
};

class submarine : public ship
{
	int damage[5];	//find out correct ship sizes
};


class board
{
public:

	board();

	bool placeShip(ship &place);

//private:	need public for debugging

	char grid[10][10];
	vector<ship> playerShips;	//board filled when size = 5

	bool fitsOnBoard(ship &test);

};


class player
{
	board playerBoard;
};

class game
{
	player user[2];
};
