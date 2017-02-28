//board.cpp
//Sam Erie and Aisha Peters
//
//For CS 372
//Project 1

#include "board.h"


//Initializes an empty board
board::board()
{
	fill_n(*grid, sizeof(grid), '-');	//populate grid with dashes
}

//Returns true if the given ship object has coordinates not in use by another
//ship object, else returns false.
bool board::placeShip(ship place)
{
	if (place.isGood()) //if the coordinates are valid
	{
		for (auto i : place.damage) //check for ship overlap at all coordinates
		{
			if (checkHit(i.x, i.y)) return false;
		}

		playerFleet.push_back(place); //add validated ship
		return true;
	}

	return false;
}

//Returns true if given coordinates are in use by an existing ship object,
// else returns false.
bool board::checkHit(int x, int y)
{
	for (auto i : playerFleet) //loop through player's ships
	{
		for (auto j : i.damage) //loop through each ship's coordinates
		{
			if (x == j.x && y == j.y) return true; //if coordinates match
		}
	}

	return false;
}

//Updates board vectors to reflect ship and hit locations
void board::updateGrid()
{
	for (auto i : playerFleet) //loop through player's ships
	{
		for (auto j : i.damage) //loop through each ship's coordinates
		{
			char h = '1';
			if (j.hit) h = '0';	//if a ship is hit

			grid[j.x][j.y] = h;

		}
	}
}

//Updates given board coordinates
void board::updateGrid(int hx, int hy)
{
	if (grid[hx][hy] == '-') grid[hx][hy] = 'x';

	updateGrid();
}

//Returns given coordinate from grid
char board::getCord(int x, int y)
{
	return grid[x][y];
}

//Returns size of player's ships
int board::fleetSize()
{
	return playerFleet.size();
}

//Prints the grid
void board::print()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			cout << getCord(x,y) << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
