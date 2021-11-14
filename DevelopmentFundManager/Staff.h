#pragma once
#include <string>
#include "Person.h"

template<typename V, typename K>
class Staff : public Person<V, K>
{

public:

	Staff(
		string name,
		K phoneNumber,
		V fundAmount,
		string department,
		K staffNum,
		string extentsionNum
	);

	void print() const;
	void read() const;

private:

	string department;
	K staffNumber;
	string extensionNumber;


};

