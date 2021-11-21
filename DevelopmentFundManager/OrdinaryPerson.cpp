#include "OrdinaryPerson.h"
#include <iostream>

OrdinaryPerson::OrdinaryPerson(
	string name,
	string phoneNumber,
	int fundAmount

) : Person(name, phoneNumber, fundAmount)

{

	// TODO: static 멤버 사용하여 기탁자 코드 부여
	// 현재는 임시 코드부여
	depositorCode = "V0000001";

}

OrdinaryPerson::OrdinaryPerson() : Person() {}

void OrdinaryPerson::print() const {

	cout << "   [ 일반 ] " << getName() << "(기탁자코드:" 
		 << depositorCode << ") "
		 << getPhoneNumber() << " " << getFundAmount();

}

void OrdinaryPerson::read(stringstream& ss) {



}

bool OrdinaryPerson::isDuplicatedKey(string key) const {

	if (key == getPhoneNumber()) return true;
	if (key == depositorCode) return true;

	return false;
}

bool OrdinaryPerson::operator==(const Person& person) const {

	if (person.isDuplicatedKey(getPhoneNumber())) return true;
	if (person.isDuplicatedKey(depositorCode)) return true;

	else return false;
}

bool OrdinaryPerson::operator==(const string& key) const {

	if (isDuplicatedKey(key)) return true;
	if (isDuplicatedKey(key)) return true;

	else return false;
}
