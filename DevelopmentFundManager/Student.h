#pragma once
#include <string>
#include <iostream>
#include "Person.h"
using namespace std;

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

	bool isDuplicatedKey(string key) const;

	bool operator==(const Person& person) const;

	// friend 


private:

	string department;
	string studentNumber;


};

