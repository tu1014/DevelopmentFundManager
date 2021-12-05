#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "Person.h"
using namespace std;

class Student : public Person
{

public:

	Student();

	Student(
		string name,
		string phoneNumber,
		int fundAmount,
		string department,
		string stdNumber
	);
	~Student();

	void print() const;
	void read(stringstream& ss);
	void write(ofstream& outStream) const;

	bool isDuplicatedKey(string key) const;

	bool operator==(const Person& person) const;
	bool operator==(const string& key) const;

	// friend 


private:

	string department;
	string studentNumber;


};

