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

void board::updateGrid()
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
}

//Updates board vectors to reflect ship and hit locations
void board::updateGrid(int hx, int hy)
{
	if (grid[hx][hy] == '-') grid[hx][hy] = 'x';

	updateGrid();
}

//Initializes an empty board
board::board()
{
	fill_n(*grid, sizeof(grid), '-');	//populate grid with dashes
}

//global board printer for testing -dev
void print(board b)
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			cout << b.grid[x][y] << " ";
		}
		cout << "\n";
	}
}

//Testing environment for code
int main()
{
	/*bool test;
	board b;
	ship s(5, 5, 3, false);
	ship t(4, 5, 2, true);
	b.placeShip(s);
	test = b.placeShip(t);
	b.updateGrid(0, 0);
	*/
	player b;
	b.initBoard();
	b.getBoard().updateGrid();

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			cout << b.getBoard().grid[x][y] << " ";
		}
		cout << "\n";
	}

	/*bool one = true, two = true;

	cout << (test ? "true" : "false")<<"\n";
	*/

	while (std::cin.get() != 10);
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


void player::initBoard()
{
	
	while (playerBoard.playerShips.size() < 5)	//make member function to access playerShips vector
	{
		bool good;
							//pickShip() is overloaded for user/computer player
		good = playerBoard.placeShip(pickShip());

		if (!good) { cout << "You can't place your ship there\n"; }//maybe this should say why
		else { playerBoard.updateGrid(); print(playerBoard); }

	}
}

ship player::pickShip()
{
	//these should be placed in class, instead of inaccessable ones in ship class
	vector<string> shipTypes = { "Destroyer","Submarine","Cruiser","Battleship","Carrier" };
	vector<int> shipSizes = { 2,3,3,4,5 };

	int x, y;
	char charY;
	char choice;
	bool vertical = false;
	int shipNumber = playerBoard.playerShips.size();

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

board & player::getBoard()
{
	return playerBoard;
}
