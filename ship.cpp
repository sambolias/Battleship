//ship.cpp
//Sam Erie and Aisha Peters
//
//For CS 372
//Project 1

#include "ship.h"


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

//Returns ship type size
	int ship::getSize()
	{
		switch (type)
		{
		case 1: return 2;
		case 2: return 3;
		case 3: return 3;
		case 4: return 4;
		case 5: return 5;
		default: return -1;
		}

		return -1;
	}

//Returns ship type name
	string ship::getName()
	{
		switch (type)
		{
			case 1: return "Destroyer";	//size  --2
			case 2: return "Submarine";	//		--3
			case 3: return "Cruiser";	//		--3
			case 4: return "Battleship";	//	--4
			case 5: return "Carrier";		//	--5
			default: return "Error in getName(): This ship has no name";
		}

		return "Error in getName(): This ship has no name";
	}

//Returns good if ship is valid, false otherwise
	bool ship::isGood(){
		return good;
	}
