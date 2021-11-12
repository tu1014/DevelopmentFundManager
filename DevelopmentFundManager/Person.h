#pragma once
#include "string"
using namespace std;

class Person
{

public:

	Person(string name, string phoneNumber, int fundAmount);
	~Person();


private:

	string name;
	string phoneNumber;
	int fundAmount;



};

