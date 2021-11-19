#include "Student.h"
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

Student::~Student() {}

void Student::print() const {

	cout << "[ �л� ] " << getName() << "(�й�:"
		 << studentNumber << ", �а�:"
		 << department << ") "
		 << getPhoneNumber() << " " << getFundAmount()
		 << endl;

}

void Student::read() const {

	// ���� ����� ���� �� �ۼ�



};

bool Student::operator==(const Student& student) const {

	if (getPhoneNumber() == student.getPhoneNumber()) return true;

	if (studentNumber == student.studentNumber) return true;

	else return false;

}

bool Student::operator<(const Student& student) const {

	return (getFundAmount() < student.getFundAmount());


}