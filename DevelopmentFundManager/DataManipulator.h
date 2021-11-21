#pragma once
#include "Person.h"
#include "MyList.hpp"
#include "string"

class DataManipulator
{

public:

	DataManipulator();
	// &으로 바꾸기
	void setFileName(const string fileName);
	bool readFile(const string fileName);
	bool isEmpty() const;
	void printAll() const;
	bool insert(Person* person);
	int getSize() const;

	Person* updateFundAmount(const string& key, int fundAmount);


private:

	MyList<Person> personList;
	string fileName;


};

