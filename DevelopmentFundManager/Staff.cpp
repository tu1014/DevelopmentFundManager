#include "Staff.h"
#include <iostream>
using namespace std;

template<typename V, typename K>
Staff<V, K>::Staff(
	string name,
	K phoneNumber,
	V fundAmount,
	string _department,
	K _staffNumber,
	string _extensionNumber

) : Person(name, phoneNumber, fundAmount)

{
	department = _department;
	staffNumber = _staffNumber;
	extensionNumber = _extensionNumber;
}

template<typename V, typename K>
void Staff<V, K>::print() const {

	cout << "[교직원] " << getName() << "(사번:"
		 << staffNumber << ", 부서:"
		 << department << "(x"
		 << extensionNumber << ")) "
		 << getPhoneNumber() << " " << getFundAmount()
		 << endl;
	 
}

template<typename V, typename K>
void Staff<V, K>::read() const {



}