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

void Student::print() {

	cout << "[ �л� ] " << getName() << "(�й�:"
		 << studentNumber << ", �а�:"
		 << department << ") "
		 << getPhoneNumber() << " " << getFundAmount()
		 << endl;

}

void Student::read() {

	// ���� ����� ���� �� �ۼ�



};