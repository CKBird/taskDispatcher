//Christopher Bird
//August 16th, 2016
//TCB.h - Header for base class of (T)ask (C)ontrol (B)locks

#ifndef TCB_H
#define TCB_H

#include <string>
#include <time.h>

using namespace std;

class TCB {

public:
	TCB(); //Create void TCB, never used
	TCB(string inType, int inIter, int inPri);
	//~TCB() No specific deletes needed, left as default
	inline string getType()						{ return type; }
	inline void setType(string inType)			{ type = inType; }
	inline int getPriority()					{ return priority; }
	inline void setPriority(int inPri)			{ priority = inPri; }
	inline int getIterator()					{ return iterator; }
	inline void setIterator(int inIter)			{ iterator = inIter; }
	inline TCB* getNext()						{ return next; }
	inline void setNext(TCB* currTCB)			{ next = currTCB; }
	inline TCB* getPrev()						{ return prev; }
	inline void setPrev(TCB* currTCB)			{ prev = currTCB; }
	inline void setEnqueueTime()				{ time(&timeEnqueue); }
	inline void setDequeueTime()				{ time(&timeDequeue); }
	inline void incTimesExec()					{ ++numTimesExecuted; }
	inline int getTimesExec()					{ return numTimesExecuted; }
	void regenPriority();
	inline void resetNextPrev()					{ next = NULL; prev = NULL; }
	
private:
	string type;
	int priority;
	int iterator;
	TCB *next;
	TCB *prev;
	time_t timeEnqueue;
	time_t timeDequeue;
	time_t timeCreate;
	int numTimesExecuted;
};

#endif //TCB_H