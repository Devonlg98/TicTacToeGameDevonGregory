#include <iostream>
#include <string>
#include "utils.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	//2D array for tictactoe
	int ticTacToeArray[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	int userInputInt;
	bool matchOn = true;
	bool gameOn = true;
	bool incorrectInput = false;
	string userInputString;
	player player1;
	player player2;

	while (gameOn == true)
	{
		cout << "how big would you like the tictactoe to be? x by x?, somewhere between 3 and 10." << endl;
		cin >> userInputInt;
		//Prevent players from breaking array by limiting board size
		if (userInputInt < 3 || userInputInt > 10)
		{
			userInputInt = 3;
		}
		int sizeY = userInputInt;
		int sizeX = userInputInt;
		int boardSize = userInputInt;
		int boardByBoard = userInputInt * userInputInt;
		int **board = new int*[sizeY];
		for (int i = 0; i < sizeY; ++i)
		{
			board[i] = new int[sizeX];
		}
		resetBoard(board, boardSize);
		system("CLS");
		//Displays board in the terminal
		printBoard(board, boardSize);


		//Accepting player input from player 1 and 2
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Player 1, what is your name?" << endl;
		cin >> userInputString;
		system("CLS");
		player1.name = userInputString;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Player 2, what is your name?" << endl;
		cin >> userInputString;
		system("CLS");
		player2.name = userInputString;

		while (matchOn)
		{
			//Accepting player input from player 1 and 2
			//Validating player input and reprompting if necessary
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << player1.name << ", do you want X's or O's? type 1 for X, 2 for O" << endl;
			cin >> userInputInt;
			switch (userInputInt)
			{
			case 1:
				player1.xoro = 1;
				player2.xoro = 2;
				matchOn = false;
				break;

			case 2:
				player1.xoro = 2;
				player2.xoro = 1;
				matchOn = false;
				break;

			default:
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Incorrect Input" << endl << player1.name << " do you want X's or O's? type 1 for X, 2 for O" << endl;
				cin >> userInputInt;
				continue;
			}
		}
		system("CLS");
		matchOn = true;
		while (matchOn)
		{
			printBoard(board, boardSize);
			//player 1
			player1.playerInput = -1;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Pick a space, 1 through " << boardByBoard << ", " << player1.name << "." << endl;
			cin >> player1.playerInput;
			while (player1.playerInput < 1 || player1.playerInput > boardByBoard)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Incorrect Input " << endl << player1.name << "," << endl;
				cout << "Pick a space, 1 through " << boardByBoard <<", "<< player1.name <<"."<< endl;
				cin >>  player1.playerInput;
			}
			placeBoard(board, boardSize, player1);
			system("CLS");
			printBoard(board, boardSize);
			//Checking if a player one has won the tic-tac-toe game
			if (boardCheckWin(board, boardSize, player1) == true)
			{
				break;
			}
			//Checking if a player has caused a tie to occur
			if (boardCheckFull(board, boardSize, player1) == true)
			{
				break;
			}
			system("CLS");

			//player 2

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			printBoard(board, boardSize);
			cout << "Pick a space, 1 through " << boardByBoard << ", " << player2.name << "." << endl;
			cin >> player2.playerInput;
			while (player2.playerInput < 1 || player2.playerInput > boardByBoard)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Incorrect Input " << endl << player2.name << "," << endl;
				cout << "Pick a space, 1 through " << boardByBoard << ", " << player2.name << "." << endl;
				cin >> player2.playerInput;
			}
			placeBoard(board, boardSize, player2);
			system("CLS");
			printBoard(board, boardSize);
			//Checking if a player two has won the tic-tac-toe game
			if (boardCheckWin(board, boardSize, player2) == true)
			{
				break;
			}
			//Checking if a player has caused a tie to occur
			if (boardCheckFull(board, boardSize, player2) == true)
			{
				break;
			}
			system("CLS");
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//Deleting pointer
		for (int i = 0; i < sizeX; i++)
		{
			delete board[i]; 
		}
		//Asks player if they would like to play again or exit
		cout << "Would you like to play again? [1]Yes or [2]No " << endl;
		cin >> userInputInt;
		switch (userInputInt)
		{
		case 1:
			matchOn = true;
			continue;

		case 2:
			matchOn = false;
			gameOn = false;
			break;

		default:
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Incorrect Input, starting new game!" << endl;
			cin >> userInputInt;
			continue;
		}
	}

	return 0;
}