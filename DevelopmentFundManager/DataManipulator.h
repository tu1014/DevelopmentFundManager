#pragma once
#include "Person.h"
#include "MyList.hpp"
#include "string"

class DataManipulator
{

public:

	DataManipulator();
	void setFileName(const string fileName);
	bool readFile(const string fileName);
	bool isEmpty() const;
	void printAll() const;
	bool insert(Person* person);


private:

	MyList<Person> personList;
	string fileName;


};

