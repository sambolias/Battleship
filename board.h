//board.h
//Sam Erie and Aisha Peters
//
//For CS 372
//Project 1

#pragma once
#include "ship.h"

#include <algorithm>
using std::fill_n;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;

class board
{
public:

	board();
	bool placeShip(ship place);
	bool checkHit(int x, int y);
	void updateGrid();
	void updateGrid(int hx, int hy);
	char getCord(int x, int y);
	int  fleetSize();
	void print();

private:

	char grid[10][10];
	vector<ship> playerFleet;	//board filled when size = 5


};
