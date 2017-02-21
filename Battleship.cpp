
#include "Battleship.h"


bool board::placeShip(ship &place)
{
	if (place.good)
	{
		for (auto i : place.damage)
		{
			if (checkHit(i.x, i.y)) return false;
		}
		
		playerShips.push_back(place);
		return true;
	}

	return false;
}

bool board::checkHit(int x, int y)
{
	for (auto i : playerShips)
	{
		for (auto j : i.damage)
		{
			if (x == j.x && y == j.y) return true;
		}
	}

	return false;
}

void board::updateGrid(int hx, int hy)
{
	for (auto i : playerShips)
	{
		for (auto j : i.damage)
		{
			char h = '1';
			if (j.hit) h = '0';
			
				grid[j.x][j.y] = h;
			
		}
	}

	grid[hx][hy] = 'x';
}


board::board()
{
	fill_n(*grid, sizeof(grid), '-');	//populate grid with dashes
}





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

ship::ship(int x, int y, int t, bool verticle) : type(t)
{
	
	for (int i = 0; i < getSize(); i++)
	{
		shipData dataPoint(x, y);
		if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9))
		{
			good = true;
			damage.push_back(dataPoint);
		}
		else
		{
			good = false;
			break;
		}

		verticle ? y++ : x++;

	}
}
