#include "OrdinaryPerson.h"
#include <iostream>

OrdinaryPerson::OrdinaryPerson(
	string name,
	string phoneNumber,
	int fundAmount

) : Person(name, phoneNumber, fundAmount)

{

	// TODO: static ��� ����Ͽ� ��Ź�� �ڵ� �ο�
	// ����� �ӽ� �ڵ�ο�
	depositorCode = "";

}

void OrdinaryPerson::print() {

	cout << "[ �Ϲ� ] " << getName() << "(��Ź���ڵ�:" 
		 << depositorCode << ") "
		 << getPhoneNumber() << " " << getFundAmount()
		 << endl;

}

void OrdinaryPerson::read() {



}
