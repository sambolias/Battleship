//Battleship.cpp
//Sam Erie and Aisha Peters
//
//For CS 372
//Project 1

#include "game.h"

#include <iostream>
using std::cin;

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
			cout << b.getBoard().getCord(x,y) << " ";
		}
		cout << "\n";
	}

	/*bool one = true, two = true;

	cout << (test ? "true" : "false")<<"\n";
	*/

	while (std::cin.get() != 10);
    return 0;
}
