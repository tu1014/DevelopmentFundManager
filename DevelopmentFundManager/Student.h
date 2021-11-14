#pragma once
#include <string>
#include "Person.h"

template<typename V, typename K>
class Student : public Person
{

public:

	Student(
		string name,
		K phoneNumber,
		V fundAmount,
		string department,
		K stdNumber
	);
	~Student();

	void print() const;
	void read() const;

private:

	string department;
	K studentNumber;


};

