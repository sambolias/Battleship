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

bool board::attackBoard(coord hit)
{
	if (checkHit(hit.x, hit.y))
	{
		if (attackShip(hit))
		{
				return true;	//it was hit
		}

		return false;	//it was already hit
	}
	updateGrid(hit.x, hit.y);
	return false;	//complete miss
}

//Updates board vectors to reflect ship and hit locations
void board::updateGrid()
{
	for (auto i : playerFleet) //loop through player's ships
	{
		for (auto j : i.damage) //loop through each ship's coordinates
		{
			char h = 'U';
			if (j.hit) h = 'X';	//if a ship is hit

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

	for (int y = 0; y <= 10; y++)
	{
		for (int x = 0; x <= 10; x++)
		{
			if (y == 0 && x == 0)
			{
				cout << "  ";
			}
			else if (y == 0)
			{
				cout << x << " ";	//added buffer works here because users don't like 0
			}
			else if (x == 0)
			{
				cout << ((char)(y + 96)) << " ";	//97 is a, subtract 1 to make up for buffer
			}
			else
			{
				char out =  getCord(x - 1, y - 1);	//1 is buffer for numbers
				if (out == 'x')out = '-';
				cout << out << " ";
			}
		}
		cout << "\n";
	}

}

void board::printEnemy()
{
	for (int y = 0; y <= 10; y++)
	{
		for (int x = 0; x <= 10; x++)
		{
			if (y == 0 && x == 0)
			{
				cout << "  ";
			}
			else if (y == 0)
			{
				cout << x << " ";	//added buffer works here because users don't like 0
			}
			else if (x == 0)
			{
				cout << ((char)(y + 96)) << " ";	//97 is a, subtract 1 to make up for buffer
			}
			else {
				char out = getCord(x - 1, y - 1);
				if (out == 'U')out = '-';
		
				cout<<out<< " ";	

			}
		}
		cout << "\n";
	}
	
}

vector<ship>& board::getFleet()
{
	return playerFleet;
}

bool board::attackShip(coord hit)
{
	for (int i = 0; i < playerFleet.size(); i++) //loop through player's ships
	{
		for (int j = 0; j < playerFleet[i].damage.size(); j++) //loop through each ship's coordinates
		{
			if (hit.x == playerFleet[i].damage[j].x && hit.y == playerFleet[i].damage[j].y)
			{
				if (!playerFleet[i].damage[j].hit)
				{
		
					playerFleet[i].isHit();	//register hit
									
					playerFleet[i].damage[j].takeHit();
					updateGrid();
					return true; //successful hit
				}
				break;	//if it was already hit there
			}
		}
	}
	return false;
}
