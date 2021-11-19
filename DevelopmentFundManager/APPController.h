#pragma once
#include "UserInterface.h"
#include "MyList.h"
#include "DataManipulator.h"

class APPController
{
public:

	const static int PRINT_ALL;
	const static int REGISTER;
	const static int UPDATE;
	const static int DELETE;
	const static int QUIT;

	APPController();

	const bool getRunningState() const;

	const int readCommand() const;
	void executeCommand(const int command);
	void fileNotFound();
	void readFile(const string fileName);


private:

	UserInterface ui;
	DataManipulator dataManipulator;

	bool isRunning;

	void start();
	void exit();
	void printAll();
	void registerPerson();
	void updatePerson();
	void deletePerson();
	void quit();




};

