#include "OrdinaryPerson.h"
#include <iostream>

OrdinaryPerson::OrdinaryPerson(
	string name,
	string phoneNumber,
	int fundAmount

) : Person(name, phoneNumber, fundAmount)

{

	// TODO: static ��� ����Ͽ� ��Ź�� �ڵ� �ο�
	// ����� �ӽ� �ڵ�ο�
	depositorCode = "V0000001";

}

void OrdinaryPerson::print() const {

	cout << " [ �Ϲ� ] " << getName() << "(��Ź���ڵ�:" 
		 << depositorCode << ") "
		 << getPhoneNumber() << " " << getFundAmount();

}

void OrdinaryPerson::read() const {



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
