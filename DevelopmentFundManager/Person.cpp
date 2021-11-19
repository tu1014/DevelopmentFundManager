#include "Person.h"
#include "string"

Person::~Person() {

	// new를 사용하여 동적 할당한 멤버에 대해서만 delete 수행
	// delete name;
	// delete phoneNumber;

}

Person::Person(string _name, string _phoneNumber, int _fundAmount) {

	name = _name;
	phoneNumber = _phoneNumber;
	fundAmount = _fundAmount;

}

bool Person::addFundAmount(int amount) {

	if (amount < 0) return false;

	fundAmount += amount;
	return true;

}

const string Person::getName() const { return name; }
const string Person::getPhoneNumber() const  { return phoneNumber; }
const int Person::getFundAmount() const { return fundAmount; }
