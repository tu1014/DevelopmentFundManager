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

	cout << "   [������] " << getName() << "(���:"
		 << staffNumber << ", �μ�:"
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

bool Staff::isDuplicatedKey(string key) const {

	if (key == getPhoneNumber()) return true;
	if (key == staffNumber) return true;

	return false;
}

bool Staff::operator==(const Person& person) const {

	if (person.isDuplicatedKey(getPhoneNumber())) return true;
	if (person.isDuplicatedKey(staffNumber)) return true;

	else return false;
}