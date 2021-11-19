#include "Student.h"
#include <string>
#include <iostream>

Student::Student(
	string name,
	string phoneNumber,
	int fundAmount,
	string _department,
	string _stdNumber

) : Person(name, phoneNumber, fundAmount)

{
	department = _department;
	studentNumber = _stdNumber;
}

Student::Student() : Person() {}

Student::~Student() {}

void Student::print() const {

	cout << "   [ 학생 ] " << getName() << "(학번:"
		 << studentNumber << ", 학과:"
		 << department << ") "
		 << getPhoneNumber() << " " << getFundAmount();

}

void Student::read(stringstream& ss) {

	ss >> studentNumber;

	string name;
	ss >> name;
	setName(name);

	ss >> department;

	string phoneNumber;
	ss >> phoneNumber;
	setPhoneNumber(phoneNumber);

	int fundAmount;
	ss >> fundAmount;
	setFundAmount(fundAmount);

};

bool Student::isDuplicatedKey(string key) const {

	if (key == getPhoneNumber()) return true;
	if (key == studentNumber) return true;

	return false;
}

bool Student::operator==(const Person& person) const {

	if (person.isDuplicatedKey(getPhoneNumber())) return true;
	if (person.isDuplicatedKey(studentNumber)) return true;

	else return false;
}