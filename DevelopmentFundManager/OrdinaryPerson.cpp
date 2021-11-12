#include "OrdinaryPerson.h"
#include <iostream>

OrdinaryPerson::OrdinaryPerson(
	string name,
	string phoneNumber,
	int fundAmount

) : Person(name, phoneNumber, fundAmount)

{

	// TODO: static 멤버 사용하여 기탁자 코드 부여
	// 현재는 임시 코드부여
	depositorCode = "";

}

void OrdinaryPerson::print() const {

	cout << "[ 일반 ] " << getName() << "(기탁자코드:" 
		 << depositorCode << ") "
		 << getPhoneNumber() << " " << getFundAmount()
		 << endl;

}

void OrdinaryPerson::read() const {



}
