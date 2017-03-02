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

		if (!good && !computer) { cout << "You can't place your ship there\n"; }//maybe this should say why
		else 
		{
			playerBoard.updateGrid();
			if(!computer) playerBoard.print(); 
		}

	}
	playerBoard.updateGrid();
}

//Promps user for ship coordinates and places valid ships on board
ship player::pickShip()
{
	//these should be placed in class, instead of inaccessable ones in ship class
	vector<string> shipTypes = { "Destroyer","Submarine","Cruiser","Battleship","Carrier" };
	vector<int> shipSizes = { 2,3,3,4,5 };

	
	char choice;
	bool vertical = false;
	int shipNumber = playerBoard.fleetSize();

	cout << "Placing your " << shipTypes[shipNumber] << " which is " << shipSizes[shipNumber] << " squares long.\n";
	
	coord place = pickCoord();

	cout << "\nDo you want to place that vertically (y/n): ";
	cin >> choice;

	choice = tolower(choice);

	if (choice == 'y')vertical = true;

	return ship(place.x, place.y, shipNumber + 1, vertical);
}

coord player::playerTurn()
{
	cout << "Give attack coordinates\n";

	return pickCoord();
}

//Returns player's board
board &player::getBoard()
{
	return playerBoard;
}

coord player::pickCoord()
{
	int x, y; 
	char charY;
	bool good=false;

	while (!good)
	{
		cin.clear();
		cout << "Give vertical coordinate (a - j): ";

		cin >> charY;
		//translates to range [0,9]
		y = tolower(charY);
		y = y - 97;

		cout << "\nGive horizontal coordinate (1-10): ";

		cin >> x;
		//translates to domain [0,9]
		x--;

		if (x < 0 || x > 9 || y < 0 || y > 9)	//coords out of bounds
		{
			cout << "\nThose coordinates are out of bounds, try again\n";
		}
		else good = true;
	}

	return coord(x,y);
}

enemy::enemy():player()
{
	computer = true;
	srand(time(0));
}

coord enemy::playerTurn()
{
	int x, y;

	do
	{
		x = rand() % 10;
		y = rand() % 10;
	} while (std::find(hits.begin(), hits.end(), coord(x, y)) != hits.end());

	hits.push_back(coord(x, y));

	return coord(x,y);
}

ship enemy::pickShip()
{
	int x = rand() % 10;
	int y = rand() % 10;
	bool v = rand() % 2;

	return ship(x,y,getBoard().fleetSize()+1,v);
}
