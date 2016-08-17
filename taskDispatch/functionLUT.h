//Christopher Bird
//August 16th, 2016
//functionLUT.h - Header for base class of function LUT class

#ifndef FUNC_LUT_H
#define FUNC_LUT_H

#include <string>

using namespace std;

class functionLUT {

public:
	functionLUT();
	void executeFunction(string inType);
	
private:
	void display();
	void add();
	void sub();
};

#endif //FUNC_LUT_H