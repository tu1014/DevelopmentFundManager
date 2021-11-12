#pragma once
#include <string>
#include "Person.h"

class Student : public Person
{

public:

	Student(
		string name,
		string phoneNumber,
		int fundAmount,
		string department,
		string stdNumber
	);
	~Student();

	void print() const;
	void read() const;

private:

	string department;
	string studentNumber;


};

