#pragma once
#include <string>
#include <sstream>
#include "Person.h"

class Staff : public Person
{

public:

	Staff();

	Staff(
		string name,
		string phoneNumber,
		int fundAmount,
		string department,
		string staffNum,
		string extentsionNum
	);

	void print() const;
	void read(stringstream& ss);

	bool isDuplicatedKey(string key) const;

	bool operator==(const Person& person) const;
	bool operator==(const string& key) const;

private:

	string department;
	string staffNumber;
	string extensionNumber;


};

