#pragma once
#include <string>
using namespace std;

class UserInterface
{

public:

	void printMainUI() const;
	void printRegisterUI() const;
	void printUpdateUI() const;
	void printDeleteUI() const;
	void printQuitUI(string fileName) const;
	void printWelcome() const;
	void printGoodByeMessage() const;
	void printInvalidInputMessage() const;
	void printFileNotFoundError() const;

	// 예외처리 필요
	const int readInt() const;
	const string readLine() const;

private:

};

