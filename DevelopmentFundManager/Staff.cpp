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

) : Person<V, K>(name, phoneNumber, fundAmount)

{
	department = _department;
	staffNumber = _staffNumber;
	extensionNumber = _extensionNumber;
}

template<typename V, typename K>
void Staff<V, K>::print() const {

	cout << "[������] " << Person<V, K>::getName() << "(���:"
		 << staffNumber << ", �μ�:"
		 << department << "(x"
		 << extensionNumber << ")) "
		 << Person<V, K>::getPhoneNumber() << " " << Person<V, K>::getFundAmount()
		 << endl;
	 
}

template<typename V, typename K>
void Staff<V, K>::read() const {



}