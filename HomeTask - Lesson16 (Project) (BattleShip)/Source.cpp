#include<iostream>
#include"StartGame.h"
#include"GameBoard.h"
#include"Common.h"
using namespace std;

//Game Board settings
/*
0 - deniz ("  ")
1 - gemi ("G ")
2 - vurulmus gemi ("* ")
3 - gemi olmayan yere hucum ("x ")
*/

//Direction types
/*
1 - Left to right
2 - Top to Bottom
*/

//Ship types
/*
1 eded - 5 deneli
2 eded - 3 deneli
3 eded - 2 deneli
4 eded - 1 deneli
*/

//Show_GameBoard
/*
1 - " is setting ships..."
2 - "' turn"
*/


//void main() {
//	MySetColor(6, 0);
//	cout << "sdsd" << endl;
//	MySetColor(7, 0);
//}

void main() {

#pragma region Variables
	char** players;
	int*** playersGameBoard; //sonad bunu da delete et
	bool game = true;
	int* address;
	int direction;
	int ships[4]{ 5,3,2,1 }; //olcu
	int shipsTimes[4]{ 1,2,3,4 }; //eded
	int pgb = 0;
	int pgb2 = 0;
#pragma endregion

#pragma region Players Info
	//Start Game Introduction
	StartGameHeader();
	players = GetPlayersName();
	playersGameBoard = new int** [2] {firstPlayerGameBoard, secondPlayerGameBoard};

	//Init Game Boards
	Init_GameBoard();

	cout << "Board is loading..." << endl;
	sleep_(2);
	system("CLS");

	//Players is setting ship
	for (int p = 0; p < 2; p++) //players game board
	{
		for (int i = 0; i < 4; i++) //size
		{
			for (int j = 0; j < shipsTimes[i]; j++) //eded
			{
				//show game board
				Show_GameBoard(playersGameBoard[p], players[p], 1, false);
				//Get addres from user (Start address)
				cout << "\nYou are setting ship length: " << ships[i] << " (" << shipsTimes[j] << ")" << endl;
				address = GetAddress();
				//get direction
				if (ships[i] != 1) { direction = GetDirection(); }
				//set addres on game board
				SetOnGameBoard(playersGameBoard[p], address[1], address[0], 1, direction, ships[i]);

				//sleep_(3);
				system("CLS");
				delete[] address;
			}
		}
	}

	//Game is loading
	cout << "Game is loading..." << endl;
	sleep_(2);
	cout << "Game is starting..." << endl;
	sleep_(2);
	cout << "Let's go !!!" << endl;
	sleep_(2);
	system("CLS");
#pragma endregion

#pragma region War
	//pgb - 0 - first player
	//pgb - 1 - second player
	while (true)
	{
		//player's turn
		if (pgb == 1) { pgb2 = 0; }
		else { pgb2 = 1; }

		Show_GameBoard(playersGameBoard[pgb2], players[pgb], 2, true);
		address = GetAddress();
		game = Attack(playersGameBoard[pgb2], address[1], address[0]);

		//novbeti oyuncuya kecir
		if (!game) {
			if (pgb == 1) { pgb = 0; }
			else { pgb += 1; }
		}

		//yoxlama (butun gemiler vurulubsa oyun bitsin)
		if (!CheckBoard(playersGameBoard[pgb])) { break; }
		system("CLS");
	}

	system("CLS");
	cout << endl << "Game ended..." << endl;

	if (pgb == 1) { pgb = 0; }
	else { pgb += 1; }
	cout << players[pgb] << " won..." << endl;

#pragma endregion

#pragma region Final
	delete[] address;
	Delete_GameBoard(firstPlayerGameBoard, 10);
	Delete_GameBoard(secondPlayerGameBoard, 10);
#pragma endregion

}