#pragma once
#include <string>
#include "Person.h"

class Staff : public Person
{

public:

	Staff(
		string name,
		string phoneNumber,
		int fundAmount,
		string department,
		string staffNum,
		string extentsionNum
	);

	void print() const;
	void read() const;

private:

	string department;
	string staffNumber;
	string extensionNumber;


};

