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

	cout << "[ 학생 ] " << getName() << "(학번:"
		 << studentNumber << ", 학과:"
		 << department << ") "
		 << getPhoneNumber() << " " << getFundAmount()
		 << endl;

}

void Student::read() const {

	// 파일 입출력 공부 후 작성



};

bool Student::operator==(const Student& student) const {

	if (getPhoneNumber() == student.getPhoneNumber()) return true;

	if (studentNumber == student.studentNumber) return true;

	else return false;

}

bool Student::operator<(const Student& student) const {

	return (getFundAmount() < student.getFundAmount());


}