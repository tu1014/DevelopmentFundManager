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


private:

	MyList<Person> personList;
	string fileName;


};

