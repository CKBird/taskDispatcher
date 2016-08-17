//Christopher Bird
//August 16th, 2016
//TCB.h - Header for base class of (T)ask (C)ontrol (B)locks

#include <string>
#include <time>

using namespace std;

class TCB {

public:
	TCB(); //Create void TCB, never used
	TCB(string inType, int inPri, int inIter);
	~TCB();
	inline string getType()						{ return type; }
	inline void setType(string inType)			{ type = inType; }
	inline int getPriority()					{ return priority; }
	inline void setPriority(int inPri)			{ priority = inPri; }
	inline int getIterator()					{ return iterator; }
	inline void setIterator(int inIter)			{ iterator = inIter; }
	
private:
	string type;
	int priority;
	int iterator;
	TCB *next;
	TCB *prev;
	time_t timeEnqueue;
	time_t timeDequeue;
	time_t timeCreate;

}