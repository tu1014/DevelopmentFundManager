#include "Student.h"
#include <iostream>

template<typename V, typename K>
Student<V, K>::Student(
	string name,
	K phoneNumber,
	V fundAmount,
	string _department,
	K _stdNumber

) : Person(name, phoneNumber, fundAmount)

{
	department = _department;
	studentNumber = _stdNumber;
}

template<typename V, typename K>
Student<V, K>::~Student() {}

template<typename V, typename K>
void Student<V, K>::print() const {

	cout << "[ 학생 ] " << getName() << "(학번:"
		 << studentNumber << ", 학과:"
		 << department << ") "
		 << getPhoneNumber() << " " << getFundAmount()
		 << endl;

}

template<typename V, typename K>
void Student<V, K>::read() const {

	// 파일 입출력 공부 후 작성



};