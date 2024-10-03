#pragma once
#include<iostream>
#include"Common.h"
using namespace std;

void StartGameHeader() {
	//oyun baslayanda teqdimat edir

	cout << "\tWelcome to Battle Ship Console Game\n\n\n";
	cout << "Press enter to start...";
	cin.get();
	cout << "Game is loading...\nPLease wait...\n\n";
	sleep_(3);
	system("CLS");
}

char**& GetPlayersName() {

	char** players = new char* [2] {};
	char* firstPlayersName = new char[50] {};
	char* secondPlayersName = new char[50] {};

	cout << "Enter first player name: ";
	cin.getline(firstPlayersName, 50);

	cout << "Enter second player name: ";
	cin.getline(secondPlayersName, 50);

	players[0] = firstPlayersName;
	players[1] = secondPlayersName;

	system("CLS");
	return players;
}


