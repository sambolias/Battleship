//game.h
//Sam Erie and Aisha Peters
//
//For CS 372
//Project 1

#pragma once

#include "player.h"

class game
{	
	player * user[2];
	bool turn = false;
	bool gameover = false;
	int sumFleet(vector<ship> & fleet);
	void drawBoards();

public:
	game();
	void play();
};