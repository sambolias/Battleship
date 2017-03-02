//board.h
//Sam Erie and Aisha Peters
//
//For CS 372
//Project 1

#pragma once
#include "ship.h"



class board
{
public:

	board();
	bool placeShip(ship place);
	bool checkHit(int x, int y);
	bool attackBoard(coord hit);
	
	void updateGrid();
	void updateGrid(int hx, int hy);
	char getCord(int x, int y);
	int  fleetSize();
	void print();
	void printEnemy();
	vector<ship> & getFleet();

private:
	bool attackShip(coord hit);
	char grid[10][10];
	vector<ship> playerFleet;	//board filled when size = 5


};
