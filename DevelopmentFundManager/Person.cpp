#include "Person.h"
#include "string"
#include "Student.h"
#include "Staff.h"
#include "OrdinaryPerson.h"

bool isDigit(char c);

Person::Person() {
	fundAmount = 0;
}

Person::~Person() {

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

	if (fundAmount == person.fundAmount) {

		if (name == person.name) return (phoneNumber > person.phoneNumber);

		else return (name > person.name);
	}

	return (fundAmount < person.fundAmount);
}

bool Person::operator>(const Person& person) const {

	if (fundAmount == person.fundAmount) {

		if (name == person.name) return (phoneNumber < person.phoneNumber);

		else return (name < person.name);

	}

	return (fundAmount > person.fundAmount);
}

bool Person::isValidPhoneNumber(const string& number) const {

	int length = phoneNumber.length();

	if (length != 13) return false;

	for (int i = 0; i < 3; i++)
		if (isDigit(phoneNumber[i]) == false) return false;

	if (phoneNumber[3] != '-') return false;

	for (int i = 4; i < 8; i++) {
		if (isDigit(phoneNumber[i]) == false) return false;
	}

	if (phoneNumber[8] != '-') return false;

	for (int i = 9; i < 13; i++) {
		if (isDigit(phoneNumber[i]) == false) return false;
	}

	return true;

}

bool isDigit(char c) {

	return ('0' <= c && c <= '9');

}

Person* Person::stringToPerson(string& line) {

	stringstream ss;
	ss.str(""); ss.clear();

	ss << line;

	string personType;
	ss >> personType;

	Person* person = NULL;

	if (personType == "학생") { person = new Student(); }
	else if (personType == "교직원") { person = new Staff(); }
	else if (personType == "일반") { person = new OrdinaryPerson(); }
	else return person;

	(*person).read(ss);

	if((*person).isValid())
		return person;

	else {
		delete person;
		return NULL;
	}

}
