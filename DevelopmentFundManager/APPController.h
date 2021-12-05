#pragma once
#include "UserInterface.h"
#include "MyList.hpp"
#include "Person.h"

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
	bool readFile(const string& fileName);


private:

	UserInterface ui;
	MyList<Person> personList;
	string fileName;

	bool isRunning;

	void start();
	void exit();
	void printAll() const;
	void registerPerson();
	void updateFundAmount();
	void deletePerson();
	void checkQuit();
	void save();

	bool insert(Person* person);

};

