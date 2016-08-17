//Christopher Bird
//August 16th, 2016
//queueBase.cpp - Source for base class of main queue class

#include <string>
#include <iostream>
#include <iomanip>
//#include <time.h>

#include "queueBase.h"

using namespace std;

queueBase::queueBase() {
	head = NULL;
}

queueBase::queueBase(TCB *inHead) {
	head = inHead;
}

queueBase::~queueBase() {
	//this->deleteAll();
}

/*void queueBase::deleteAll() {
	while(head != NULL)
		this->deleteLast();
}

void queueBase::deleteLast() {
	TCB *tempTCB = head;
	while(tempTCB->getNext() != NULL)
		tempTCB = tempTCB->getNext();
	cout << "test" << endl;
	delete tempTCB;
}*/

void queueBase::enqueueEnd(TCB *newTCB) {
	TCB* currTCB = head;
	if(currTCB == NULL) {
		head = newTCB;
		return;
	}
	while(currTCB->getNext() != NULL) {
		currTCB = currTCB->getNext();
	}
	currTCB->setNext(newTCB);
	newTCB->setPrev(currTCB);	
}

void queueBase::enqueuePri(TCB *newTCB) {
	//We assume current queue is already sorted in order
	//Obvious (potentially slower) way to add is traverse until next is larger priority than current
	//cout << "EnqueuePri" << endl;
	TCB* currTCB = head;
	if(head == NULL) { //No head
		head = newTCB;
		return;
	}
	if(currTCB->getNext() == NULL) {
		if(currTCB->getPriority() > newTCB->getPriority()) {
			TCB* tempTCB = head;
			head = newTCB;
			newTCB->setNext(tempTCB);
			tempTCB->setPrev(newTCB);
			return;
		}
		else {
			currTCB->setNext(newTCB);
			newTCB->setPrev(currTCB);
			return;
		}
	}
	else {
		while(currTCB->getNext() != NULL) {
			if(currTCB->getNext()->getPriority() <= newTCB->getPriority()) {
				currTCB = currTCB->getNext();
			}
			else {
				TCB* tempTCB = currTCB->getNext();
				currTCB->setNext(newTCB);
				newTCB->setNext(tempTCB);
				newTCB->setPrev(currTCB);
				tempTCB->setPrev(newTCB);
				return;
			}
		}
		currTCB->setNext(newTCB);
		newTCB->setPrev(currTCB);
		return;
	} 
	/* To insert C in between A and B in linked list
	A->next = C
	B->prev = C
	C->next = B 
	C->prev = A */
}

void queueBase::printQueue() {
	TCB* currTCB = head;
	int i = 0;
	while(currTCB != NULL){
		cout << "Item: " << i << setw(20) << " Type: " << currTCB->getType() << setw(20) << " Priority: " << currTCB->getPriority() << setw(20) << " Iterations: " << currTCB->getIterator() << endl;
		currTCB = currTCB->getNext();
		++i;
	}
}

TCB* queueBase::popFront() {
	TCB* returnTCB = head;
	if(head == NULL)
		return NULL;
	else if(head->getNext() == NULL)
		head = NULL;
	else {
		head = head->getNext();
		head->setPrev(NULL);
	}
	//cout << "Popping front" << endl;
	return returnTCB;
}

bool queueBase::isEmpty() {
	if(head == NULL)
		return true;
	else
		return false;
}