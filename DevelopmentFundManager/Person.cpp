#include "Person.h"
#include "string"

Person::~Person() {

	// new�� ����Ͽ� ���� �Ҵ��� ����� ���ؼ��� delete ����
	// delete name;
	// delete phoneNumber;

}

Person::Person(string _name, string _phoneNumber, int _fundAmount) {

	name = _name;
	phoneNumber = _phoneNumber;
	fundAmount = _fundAmount;

}