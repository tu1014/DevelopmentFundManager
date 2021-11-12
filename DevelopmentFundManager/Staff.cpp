#include "Staff.h"
#include <iostream>
using namespace std;

Staff::Staff(
	string name,
	string phoneNumber,
	int fundAmount,
	string _department,
	string _staffNumber,
	string _extensionNumber

) : Person(name, phoneNumber, fundAmount)

{
	department = _department;
	staffNumber = _staffNumber;
	extensionNumber = _extensionNumber;
}

void Staff::print() const {

	cout << "[������] " << getName() << "(���:"
		 << staffNumber << ", �μ�:"
		 << department << "(x"
		 << extensionNumber << ")) "
		 << getPhoneNumber() << " " << getFundAmount()
		 << endl;
	 
}

void Staff::read() const {



}