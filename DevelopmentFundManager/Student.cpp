#include "Student.h"
#include <iostream>

template<typename V, typename K>
Student<V, K>::Student(
	string name,
	K phoneNumber,
	V fundAmount,
	string _department,
	K _stdNumber

) : Person<V, K>(name, phoneNumber, fundAmount)

{
	department = _department;
	studentNumber = _stdNumber;
}

template<typename V, typename K>
Student<V, K>::~Student() {}

template<typename V, typename K>
void Student<V, K>::print() const {

	cout << "[ 학생 ] " << Person<V, K>::getName() << "(학번:"
		 << studentNumber << ", 학과:"
		 << department << ") "
		 << Person<V, K>::getPhoneNumber() << " " << Person<V, K>::getFundAmount()
		 << endl;

}

template<typename V, typename K>
void Student<V, K>::read() const {

	// 파일 입출력 공부 후 작성



};