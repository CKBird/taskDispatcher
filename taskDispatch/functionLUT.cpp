//Christopher Bird
//August 16th, 2016
//functionLUT.cpp - Source for base class of function LUT class

#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "functionLUT.h"
using namespace std;

functionLUT::functionLUT() {
	srand(time(NULL));
}

void functionLUT::executeFunction(string inType) {
	if(inType == "DISPLAY") {
		display();
		return;
	}
	else if(inType == "ADD") {
		add();
		return;
	}
	else if(inType == "SUBTRACT") {
		sub();
		return;
	}
	else {
		cout << "Function not found in database." << endl;
	}	
}

void functionLUT::display() {
	int quoteChoice = rand() % 5 + 1;
	if(quoteChoice == 1) {
		cout << "I want every light you've got dumped on that runway." << endl;
	}
	else if (quoteChoice == 2) {
		cout << "I picked the wrong day to stop huffing glue." << endl;
	}
	else if (quoteChoice == 3) {
		cout << "Oh me bum!" << endl;
	}
	else if (quoteChoice == 4) {
		cout << "Want to burn a couple of vacation days sleeping on the ground outside?" << endl;
	}
	else if (quoteChoice == 5) {
		cout << "I can't read this disertation now, I'll mark it as new..." << endl;
	}
	else {
		cout << "To Rand or not to Rand, that is where I messed up." << endl;
	}
}

void functionLUT::add() {
	int leftOper = rand()%100 + 1;
	int rightOper = rand()%100 + 1;
	int sum = leftOper + rightOper;
	cout << leftOper << " + " << rightOper << " = " << sum << endl;
}

void functionLUT::sub() {
	int leftOper = rand()%100 + 1;
	int rightOper = rand()%100 + 1;
	int sum = leftOper - rightOper;
	cout << leftOper << " - " << rightOper << " = " << sum << endl;
}