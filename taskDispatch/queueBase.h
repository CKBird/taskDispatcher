//Christopher Bird
//August 16th, 2016
//queueBase.h - Header for base class of main queue class

#ifndef QUEUE_BASE_H
#define QUEUE_BASE_H

#include <string>
//#include <time.h>

#include "TCB.h"

using namespace std;

class queueBase {

public:
	queueBase(); 							//Default queueBase
	queueBase(TCB *inHead);					//Create queue with head attached
	~queueBase();
	//inline void createHead(TCB *currTCB)	{ head = currTCB; }
	inline TCB* getHead()					{ return head; }
	inline TCB* getNext(TCB *currTCB)		{ return currTCB->getNext(); }
	void enqueueEnd(TCB *newTCB);			//Adds newTCB to end of queue
	void enqueuePri(TCB *newTCB);			//Slots newTCB into queue at correct priority placement
	//void deleteAll();						//Deletes all objects in queue including head (essentially dead)
	//void deleteLast();					//Deletes the last object in the queue (most recently added)
	void printQueue();
	TCB* popFront();						//Dequeues head (highest priority)
	bool isEmpty();
	
	
private:
	TCB *head;
};

#endif //QUEUE_BASE_H