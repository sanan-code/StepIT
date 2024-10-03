#pragma once
#include<iostream>
#include <iomanip>
#include"Common.h"
using namespace std;

//esas oyun taxtasi
int** firstPlayerGameBoard = new int* [10] {};
int** secondPlayerGameBoard = new int* [10] {};

void Init_GameBoard() {
	for (int i = 0; i < 10; i++)
	{
		firstPlayerGameBoard[i] = new int[10] {};
		secondPlayerGameBoard[i] = new int[10] {};
	}
}

void Show_GameBoard(int**& gb, char*& playerName, int t, bool isInWar) {
	//oyuncularin gemileri set etdiyi zaman istifade olunan
	//gb - game board
	//isInWar - doyus vaxti gemilerin yerini gostersin (gostermesin) (false-gostersin, true gostermesin)

	int gbs;

	//header
	if (t == 1) { cout << playerName << " is setting ships..." << endl << endl; }
	else if (t == 2) { cout << playerName << "'s turn" << endl << endl; }

	//main
	for (int i = 0; i < 11; i++)
	{
		//setir
		if (i != 0) {
			MySetColor(1, 2);
			cout << setw(2) << (i) << " ";
			MySetColor(7, 0);
		}

		//sutunlar - oyun taxtasi (gemi, deniz, bomba)
		if (i == 0) {
			MySetColor(1, 2);
			for (int j = 0; j < 11; j++) {
				cout << " " << GetLetter_from_IntNum(j);
			}
			MySetColor(7, 0);
		}
		else {
			for (int j = 0; j < 11; j++) {
				gbs = gb[i - 1][j - 1];
				if (gbs == 0) { cout << "  "; }
				else if (gbs == 1) {
					if (!isInWar) { cout << "G "; }
					else { cout << "  "; }
				}
				else if (gbs == 2) {
					MySetColor(6, 0);
					cout << "* ";
					MySetColor(7, 0);
				}
				else if (gbs == 3) { cout << "x "; }
			}
		}

		cout << endl;
	}

}

void SetOnGameBoard(int**& gb, int r, int c, int s, int direction, int size) {
	for (int i = 0; i < size; i++)
	{
		gb[r - 1][c - 1] = s;
		if (direction == 1) { c += 1; }
		else if (direction == 2) { r += 1; }
	}
}

bool Attack(int**& gb, int r, int c) {
	bool result = false;

	if (gb[r - 1][c - 1] == 0) {
		gb[r - 1][c - 1] = 3;
	}
	else if (gb[r - 1][c - 1] == 1) {
		gb[r - 1][c - 1] = 2;
		result = true;
	}

	return result;
}

bool CheckBoard(int**& gb) {
	//butun taxtani yoxlayir eger butun gemiler vurulubsa oyunu bitirir
	bool result = false;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//hele de vurulmamis gemi var mi?
			if (gb[i][j] == 1) { result = true; break; }
		}
	}

	return result;
}

template <typename T>
void Delete_GameBoard(T arr, int size) {
	for (int i = 0; i < size; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

