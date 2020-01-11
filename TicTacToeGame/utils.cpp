#include <iostream>
#include "utils.h"
#include <cmath>
#include <string>
#include <algorithm> 

//Prints cleanly up until board position 100
int * printBoard(int * board[], size_t size)
{

	int boardPos = 0;
	for (int i = 0; i < size; i++)
	{
		for (int idx = 0; idx < size; idx++)
		{

			boardPos++;
			switch (board[i][idx])
			{
			case 1:
				if (size > 3)
				{
					if (boardPos > 9)
					{
						std::cout << " X ";
						break;
					}
					else
					{
						std::cout << " " << "X ";
						break;
					}
				}
				else
				{
					std::cout << "X ";
					break;
				}

			case 2:

				if (size > 3)
				{
					if (boardPos > 9)
					{
						std::cout << " O ";
						break;
					}
					else
					{
						std::cout << " " << "O ";
						break;
					}
				}
				else
				{
					std::cout << "O ";
					break;
				}

			default :
				if (size > 3)
				{
					if (boardPos > 9)
					{
						std::cout << boardPos << " ";
						break;
					}
					else
					{
						std::cout << " " << boardPos << " ";
						break;
					}
				}
				else
				{
					std::cout << boardPos << " ";
					break;
				}
			}

		}
 		std::cout << std::endl;
	}
	return *board;
}

int * placeBoard(int * board[], size_t size, player player)
{
	player.ticPlaced == false;
	while (player.ticPlaced == false)
	{
		//Checks if the spot is full or not, if so try again, if not it replaces the zero with the player's choice.
		if (board[(player.playerInput - 1) / size][(player.playerInput - 1) % size] == 0)
		{
			board[(player.playerInput - 1) / size][(player.playerInput - 1) % size] = player.xoro;
			player.ticPlaced == true;
			return *board;
		}
		else
		{
			system("CLS");
			printBoard(board, size);
			std::cout << "Spot already filled" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Incorrect Input, try again!" << std::endl << "Pick a space, 1 through " << size*size << ", " << player.name << "." << std::endl;
			std::cin >> player.playerInput;

		}
	}
}

bool boardCheckWin(int * board[], size_t size, player player)
{
	//Check for X
	int winCheck = 0;
	//Horizontal Check i ^v idx <>
	for (int i = 0; i < size; i++)
	{
		for (int idx = 0; idx < size; idx++)
		{
			if (board[i][idx] == player.xoro)
			{
				winCheck++;
			}
		}
		//wincheck and reset
		if (winCheck == size)
		{
			player.score++;
			std::cout << std::endl << player.name << " has won!" << std::endl;
			return true;
		}
		else
		{
			winCheck = 0;
		}
		//Vertical check
		for (int idx = 0; idx < size; idx++)
		{
			if (board[idx][i] == player.xoro)
			{
				winCheck++;
			}
		}
		//wincheck and reset
		if (winCheck == size)
		{
			player.score++;
			std::cout << std::endl << player.name << " has won!" << std::endl;
			return true;
		}
		else
		{
			winCheck = 0;
		}
	}

	//Diagonal check top to bottom
	for (int i = 0; i < size; i++)
	{
		if (board[i][i] == player.xoro)
		{
			winCheck++;
		}
	}
	if (winCheck == size)
	{
		player.score++;
		std::cout << std::endl << player.name << " has won!" << std::endl;
		return true;
	}
	else
	{
		winCheck = 0;
	}

	//Diagonal check bottom to top
	for (int i = 0; i < size; i++)
	{
		if (board[size-i-1][i] == player.xoro)
		{
			winCheck++;
		}
	}
	if (winCheck == size)
	{
		player.score++;
		std::cout << std::endl << player.name << " has won!" << std::endl;
		return true;
	}
	else
	{
		winCheck = 0;
	}

	return false;
}

bool boardCheckFull(int * board[], size_t size, player player)
{
	int boardFull = 0;
	for (int i = 0; i < size; i++)
	{
		for (int idx = 0; idx < (size); idx++)
		{
			if (board[i][idx] == 1|| board[i][idx] == 2)
			{
				boardFull++;
			}
		}
		std::cout << std::endl;
	}
	if (boardFull == (size*size))
	{
		std::cout << std::endl<< "It's a tie!" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

//set's all the values on the board back to zero
int * resetBoard(int * board[], size_t size)
{
	for (int i = 0; i < size; i++)
	{
		for (int idx = 0; idx < (size); idx++)
		{
			board[i][idx] = 0;
		}
		std::cout << std::endl;
	}
	return *board;
}