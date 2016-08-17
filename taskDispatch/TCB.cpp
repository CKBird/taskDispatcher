//Christopher Bird
//August 16th, 2016
//TCB.cpp - Source for base class of (T)ask (C)ontrol (B)locks

#include <string>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "TCB.h"

using namespace std;

TCB::TCB() {
	//Unused void TCB class
	//Not currently used
}

TCB::TCB(string inType, int inIter, int inPri) {
	type = inType;
	iterator = inIter;
	priority = inPri;
	time(&timeCreate);
	numTimesExecuted = 0;
	srand(time(NULL));
	prev = NULL;
	next = NULL;
}

void TCB::regenPriority() {
	int newPriority = rand()%255 + 1;
	priority = newPriority;
}