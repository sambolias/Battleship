//player.h
//Sam Erie and Aisha Peters
//
//For CS 372
//Project 1

#include "board.h"

#pragma once
class player
{
public:
	player() = default;
	~player() = default;
	void initBoard();
	virtual coord playerTurn();
	board & getBoard();
	bool computer = false;

private:
	virtual ship pickShip();
	coord pickCoord();
	board playerBoard;
	
	
};

class enemy : public player
{
public:
	enemy();
	~enemy() = default;
	virtual coord playerTurn();
	virtual ship pickShip();
private:
	vector<coord> hits;
	coord lastHit;
	bool sank;

};