#pragma once
#include <string>
#include <sstream>
#include "Person.h"

class OrdinaryPerson : public Person
{
public:

	OrdinaryPerson();

	OrdinaryPerson(
		string name,
		string phoneNumber,
		int fundAmount
	);

	void print() const;
	void read(stringstream& ss);
	void write(ofstream& outStream) const;

	bool isDuplicatedKey(const string& key) const;
	bool isValid() const;

	bool operator==(const Person& person) const;
	bool operator==(const string& key) const;


private:

	const static int CODE_PART_INDEX;
	const static int SEQ_PART_INDEX;
	const static int SEQ_PART_LENGTH;

	static string lastCode;

	void increaseLastCode();


	string depositorCode;



};

