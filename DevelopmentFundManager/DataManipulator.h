#pragma once
#include "Person.h"
#include "MyList.hpp"
#include "string"

class DataManipulator
{

public:

	DataManipulator();
	// &���� �ٲٱ�
	void setFileName(const string fileName);
	bool readFile(const string fileName);
	bool isEmpty() const;
	void printAll() const;
	bool insert(Person* person);
	int getSize() const;

	Person* updateFundAmount(const string& key, int fundAmount);
	Person* deletePerson(const string& key);

private:

	MyList<Person> personList;
	string fileName;


};

