#pragma once
#include <string>
using namespace std;

class UserInterface
{



public:

	const static int PRINT_ALL;
	const static int REGISTER;
	const static int UPDATE;
	const static int DELETE;
	const static int QUIT;

	void printMainUI() const;
	void printRegisterUI() const;
	void printUpdateUI() const;
	void printDeleteUI() const;
	void printQuitUI() const;

	const int readInt() const;
	const string readString() const;



private:

};

