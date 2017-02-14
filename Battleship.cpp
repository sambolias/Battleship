
#include "Battleship.h"


bool board::placeShip(ship &place)
{
	if (fitsOnBoard(place))
	{
		playerShips.push_back(place);
		return true;
	}

	return false;
}

bool board::fitsOnBoard(ship &test)
{
	return false;	//needs test
}


board::board()
{
	fill_n(*grid, sizeof(grid), '-');	//populate grid with dashes
}





int main()
{
	board b;

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			cout << b.grid[x][y] << " ";
		}
		cout << "\n";
	}
	
    return 0;
}

