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
	stdNumber = _stdNumber;
}

Student::~Student() {}

void Student::print() {

	cout << "[ 학생 ] " << getName() << "(학번:"
		<< stdNumber << ", 학과:"
		<< department << ") "
		<< getPhoneNumber() << " " << getFundAmount()
		<< endl;

}

void Student::read() {

	// 파일 입출력 공부 후 작성



};