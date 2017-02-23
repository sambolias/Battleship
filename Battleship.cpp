//Battleship.cpp
//Sam Erie and Aisha Peters
//
//For CS 372
//Project 1

#include "Battleship.h"

//Returns true if the given ship object has coordinates not in use by another
//ship object, else returns false.
bool board::placeShip(ship &place)
{
	if (place.good) //if the coordinates are valid
	{
		for (auto i : place.damage) //check for ship overlap at all coordinates
		{
			if (checkHit(i.x, i.y)) return false;
		}

		playerShips.push_back(place); //add validated ship
		return true;
	}

	return false;
}

//Returns true if given coordinates are in use by an existing ship object,
// else returns false.
bool board::checkHit(int x, int y)
{
	for (auto i : playerShips) //loop through player's ships
	{
		for (auto j : i.damage) //loop through each ship's coordinates
		{
			if (x == j.x && y == j.y) return true; //if coordinates match
		}
	}

	return false;
}

//Updates board vectors to reflect ship and hit locations
void board::updateGrid(int hx, int hy)
{
	for (auto i : playerShips) //loop through player's ships
	{
		for (auto j : i.damage) //loop through each ship's coordinates
		{
			char h = '1';
			if (j.hit) h = '0';	//if a ship is hit

				grid[j.x][j.y] = h;

		}
	}

	grid[hx][hy] = 'x';
}

//Initializes an empty board
board::board()
{
	fill_n(*grid, sizeof(grid), '-');	//populate grid with dashes
}



//Testing environment for code
int main()
{
	bool test;
	board b;
	ship s(5, 5, 3, false);
	ship t(5, 5, 5, true);
	b.placeShip(s);
	test = b.placeShip(t);
	b.updateGrid(0, 0);

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			cout << b.grid[x][y] << " ";
		}
		cout << "\n";
	}

	bool one = true, two = true;

	cout << (test ? "true" : "false")<<"\n";

    return 0;
}

//Creates a ship object of tpye t with the given coordinates and orientation
ship::ship(int x, int y, int t, bool vertical) : type(t)
{

	for (int i = 0; i < getSize(); i++) // while i is within boundary of ship type size
	{
		shipData dataPoint(x, y); // create coordinate point
		if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9)) // if valid coordinates
		{
			good = true; // update flag
			damage.push_back(dataPoint); //add coordinates to ship's data
		}
		else
		{
			good = false;
			break;
		}

		vertical ? y++ : x++; //if vertical, increase y coordinate, else increase x

	}
}
