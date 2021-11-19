#pragma once
#include "Person.h"
#include "MyList.hpp"
#include "string"

class DataManipulator
{

public:

	DataManipulator();
	void setFileName(const string fileName);
	void readFile(const string fileName);


private:

	MyList<Person> personList;
	string fileName;


};

