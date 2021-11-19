#include "Person.h"
#include "string"

Person::Person() {}

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

void Person::setName(const string& _name) { name = _name; }
void Person::setPhoneNumber(const string& _phoneNumber) { phoneNumber = _phoneNumber; }
void Person::setFundAmount(const int _fundAmount) { fundAmount = _fundAmount; }

ostream& operator<<(ostream& outputStream, const Person& person) {

	person.print();
	return outputStream;
}

bool Person::operator<(const Person& person) const {

	return (fundAmount < person.fundAmount);
}

bool Person::operator>(const Person& person) const {

	return (fundAmount > person.fundAmount);
}
