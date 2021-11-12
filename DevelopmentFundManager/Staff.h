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

	void print();
	void read();

private:

	string department;
	string staffNumber;
	string extensionNumber;


};

