#include "Staff.h"
#include <iostream>
using namespace std;

Staff::Staff(
	string name,
	string phoneNumber,
	int fundAmount,
	string _department,
	string _staffNumber,
	string _extensionNumber

) : Person(name, phoneNumber, fundAmount)

{
	department = _department;
	staffNumber = _staffNumber;
	extensionNumber = _extensionNumber;
}

Staff::Staff() : Person() {}

void Staff::print() const {

	cout << "   [교직원] " << getName() << "(사번:"
		 << staffNumber << ", 부서:"
		 << department << "(x"
		 << extensionNumber << ")) "
		 << getPhoneNumber() << " " << getFundAmount();
	 
}

void Staff::read(stringstream& ss) {

	ss >> staffNumber;

	string name;
	ss >> name;
	setName(name);

	ss >> department;
	ss >> extensionNumber;

	string phoneNumber;
	ss >> phoneNumber;
	setPhoneNumber(phoneNumber);

	int fundAmount;
	ss >> fundAmount;
	setFundAmount(fundAmount);

}

void Staff::write(ofstream& outStream) const {

	outStream << "교직원 " << staffNumber << " ";
	outStream << getName() << " " << department << " ";
	outStream << extensionNumber << " ";
	outStream << getPhoneNumber() << " ";
	outStream << getFundAmount() << "\n";

}

bool Staff::isDuplicatedKey(const string& key) const {

	if (key == getPhoneNumber()) return true;
	if (key == staffNumber) return true;

	return false;
}

bool Staff::operator==(const Person& person) const {

	if (person.isDuplicatedKey(getPhoneNumber())) return true;
	if (person.isDuplicatedKey(staffNumber)) return true;

	else return false;
}

bool Staff::operator==(const string& key) const {

	if (isDuplicatedKey(key)) return true;
	if (isDuplicatedKey(key)) return true;

	else return false;
}