#include "game.h"

game::game()
{
	user[0] = new player;
	user[1] = new enemy;
}

void game::play()
{
	cout << "---Welcome to the thrilling game of Battleship---\n\n\n";
	user[0]->initBoard();
	user[1]->initBoard();
	cout << "\n\n\n\n";
	coord attack(0,0);
	bool hit;

	//user[turn] works for 2 players because boolean value = 0 or 1

	while (!gameover)
	{
		if (!turn)	drawBoards();
		attack = user[turn]->playerTurn();

		hit = user[!turn]->getBoard().attackBoard(attack);

		if (hit)
		{
			if (!turn)
			{
				cout << "\nIt's a hit!\n";
			}
			else cout << "\nYou got hit!\n";
		}
		else
		{
			if(!turn)
			cout << "\nYou missed.\n";
		}


		//change turn
		turn = !turn;

		//sumfleet makes gameover true if ships have life, so it needs !
		gameover = !(bool) sumFleet(user[turn]->getBoard().getFleet());
	}

	cout << "\nGAME OVER!\nPlayer " << ((int)turn) + 1 << " lost.\n";
}

int game::sumFleet(vector<ship>& fleet)
{
	int sum=0;

	for (auto i : fleet)
	{
		sum += i.getLife();
	}

	return sum;
}

void game::drawBoards()
{
	cout << "                              YOUR BOARD\n";
	user[turn]->getBoard().print();
	cout << "                              ENEMY'S BOARD\n";
	user[!turn]->getBoard().printEnemy();
}
