//player.cpp
//Sam Erie and Aisha Peters
//
//For CS 372
//Project 1

#include "player.h"
#include <iostream>
using std::cin;
using std::cout;

//Initialize player's board and populate with ships
void player::initBoard()
{

	while (playerBoard.fleetSize() < 5)
	{
		bool good;
							//pickShip() is overloaded for user/computer player
		good = playerBoard.placeShip(pickShip());

		if (!good) { cout << "You can't place your ship there\n"; }//maybe this should say why
		else { playerBoard.updateGrid(); playerBoard.print(); }

	}
}

//Promps user for ship coordinates and places valid ships on board
ship player::pickShip()
{
	//these should be placed in class, instead of inaccessable ones in ship class
	vector<string> shipTypes = { "Destroyer","Submarine","Cruiser","Battleship","Carrier" };
	vector<int> shipSizes = { 2,3,3,4,5 };

	int x, y;
	char charY;
	char choice;
	bool vertical = false;
	int shipNumber = playerBoard.fleetSize();

	cout << "Placing your " << shipTypes[shipNumber] << " which is " << shipSizes[shipNumber] << " squares long.\n";
	cout << "Give vertical coordinate (a - j): ";

	cin >> charY;
	//translates to range [0,9]
	y = tolower(charY);
	y = y - 97;

	cout << "\nGive horizontal coordinate (1-10): ";

	cin >> x;
	//translates to domain [0,9]
	x--;

	cout << "\nDo you want to place that vertically (y/n): ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y')vertical = true;

	return ship(x, y, shipNumber + 1, vertical);
}

//Returns player's board
board &player::getBoard()
{
	return playerBoard;
}
