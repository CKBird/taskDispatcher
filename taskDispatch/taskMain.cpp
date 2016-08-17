//Christopher Bird
//Completely rewritten on August 16th, 2016 as old version was crappy and old

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
//#include <rand>

#include "queueBase.h"
#include "TCB.h"
#include "functionLUT.h"

using namespace std;

int main(){
	
	cout << "Initiating Dadsk Dispatcher v1.0" << endl; 
	functionLUT fLUT;	
	
	//Find input file, read in requests and create TCBs for them
	ifstream inputFile;
	inputFile.open("sampleInputTB.txt");
	
	string tempWord = "";
	int tempInt = 0;
	string taskType = "";
	int iterator = 0;
	int priority = 0;
	queueBase readyQueue;
	TCB *currTask;
	if(inputFile.is_open()) {
		while(inputFile >> tempWord) {
			if(tempWord == "DONE") {
				cout << "Ready Queue Created and Filled." << endl;
				break;
			}
			taskType = tempWord;
			inputFile >> tempInt;
			iterator = tempInt;
			inputFile >> tempInt;
			priority = tempInt;
			//cout << "Task Type: " << taskType << setw(30) << " Iterator Value: " << iterator << setw(30) << " Priority Value: " << priority << endl;
			
			currTask = new TCB(taskType, iterator, priority);
			readyQueue.enqueuePri(currTask);
		}
	}
	cout << endl << "Printing Ready Queue before Execution: " << endl;
	readyQueue.printQueue();
	cout << endl;
	
	//Start pulling tasks from queue
	queueBase completedQueue;
	queueBase deadQueue;
	TCB* currTCB;
	while(!readyQueue.isEmpty()) {
		currTCB = readyQueue.popFront(); //Fully removes, not peeks, so readyQueue loses currTCB
		currTCB->setEnqueueTime();
		//cout << "Type: " << currTCB->getType() << setw(20) << " Priority: " << currTCB->getPriority() << setw(20) << " Iterations: " << currTCB->getIterator() << endl;
		if(currTCB->getIterator() == 0) { //Set to run 0 times, will never requeue something with 0 iterator
			currTCB->setDequeueTime();
			currTCB->resetNextPrev();
			deadQueue.enqueueEnd(currTCB);
		}
		else if(currTCB->getPriority() == 0 && currTCB->getTimesExec()) { //If Priority is randomly set to 0, and it has run before, send to completed queue instead of dead queue
			currTCB->setDequeueTime();
			currTCB->resetNextPrev();
			completedQueue.enqueueEnd(currTCB);
		}
		else if(currTCB->getPriority() == 0) { //Cannot hit this if getTimesExec > 0
			currTCB->setDequeueTime();
			currTCB->resetNextPrev();
			deadQueue.enqueueEnd(currTCB);
		}
		else { //Do execute
			fLUT.executeFunction(currTCB->getType()); //This fully executes the function
			if((currTCB->getIterator() - currTCB->getTimesExec()) <= 1) { //Run 200 times, times exec <200, do again
				currTCB->setDequeueTime();
				currTCB->incTimesExec();
				currTCB->resetNextPrev();
				completedQueue.enqueueEnd(currTCB);
			}
			else {
				currTCB->incTimesExec();
				currTCB->regenPriority();
				currTCB->resetNextPrev();
				readyQueue.enqueuePri(currTCB); //Put back into ready queue with new priority and +1 to execCounter
			}
		}
		//Loop until readyQueue is empty
	}	
	cout << endl << "Ready queue is empty, generating report..." << endl;
	cout << "Ready Queue Contents: " << endl;
	readyQueue.printQueue();
	
	cout << endl << "Completed Queue Contents: " << endl;
	completedQueue.printQueue();
	
	cout << endl << "Dead Queue Contents: " << endl;
	deadQueue.printQueue();
	
	cout << endl << "Logging complete, program finished." << endl;
	cout << "Press Enter to Exit" << endl;
	string x;
	getline(cin, x);
	
	return 0;
}