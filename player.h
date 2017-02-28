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

	void initBoard();
	//virtual for class computer: public player
	virtual ship pickShip();
	board & getBoard();

private:
	board playerBoard;
};
