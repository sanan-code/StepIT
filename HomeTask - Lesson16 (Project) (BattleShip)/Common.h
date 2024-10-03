#pragma once
#include<iostream>
#include <chrono>
#include <thread>
#include <windows.h>
using namespace std;
using namespace this_thread;
using namespace chrono;

enum ColumnLetters
{
	A = 1,
	B, C, D,
	E, F, G,
	H, I, J
};

void sleep_(int sec) {
	sleep_for(seconds(sec));
}

int GetIntNum_from_ColumnLetters(char ch) {
	switch (ch)
	{
	case 'A':
		return ColumnLetters(A);
		break;
	case 'B':
		return ColumnLetters(B);
		break;
	case 'C':
		return ColumnLetters(C);
		break;
	case 'D':
		return ColumnLetters(D);
		break;
	case 'E':
		return ColumnLetters(E);
		break;
	case 'F':
		return ColumnLetters(F);
		break;
	case 'G':
		return ColumnLetters(G);
		break;
	case 'H':
		return ColumnLetters(H);
		break;
	case 'I':
		return ColumnLetters(I);
		break;
	case 'J':
		return ColumnLetters(J);
		break;
	default:
		break;
	}
}

char GetLetter_from_IntNum(int n) {
	switch (n)
	{
	case 1:
		return 'A';
		break;
	case 2:
		return 'B';
		break;
	case 3:
		return 'C';
		break;
	case 4:
		return 'D';
		break;
	case 5:
		return 'E';
		break;
	case 6:
		return 'F';
		break;
	case 7:
		return 'G';
		break;
	case 8:
		return 'H';
		break;
	case 9:
		return 'I';
		break;
	case 10:
		return 'J';
		break;
	default:
		break;
	}
}

int* GetAddress() {
	int* address = new int[2] {};
	char letter;
	int row;

	cout << endl << "Enter Columm (Letter): ";
	cin >> letter;
	cout << "Enter Row: ";
	cin >> row;

	address[0] = GetIntNum_from_ColumnLetters(letter);
	address[1] = row;

	return address;
}

int GetDirection() {
	int direction = 0;
	cout << "\n...Directions...\n1. Left to right\n2. Top to Bottom\n";
	cout << "Selection: ";
	cin >> direction;
	return direction;
}

void MySetColor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}


