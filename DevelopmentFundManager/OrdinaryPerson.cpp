#include "OrdinaryPerson.h"
#include <iostream>

template<typename V, typename K>
OrdinaryPerson<V, K>::OrdinaryPerson(
	string name,
	K phoneNumber,
	V fundAmount

) : Person(name, phoneNumber, fundAmount)

{

	// TODO: static ��� ����Ͽ� ��Ź�� �ڵ� �ο�
	// ����� �ӽ� �ڵ�ο�
	depositorCode = "";

}

template<typename V, typename K>
void OrdinaryPerson<V, K>::print() const {

	cout << "[ �Ϲ� ] " << getName() << "(��Ź���ڵ�:" 
		 << depositorCode << ") "
		 << getPhoneNumber() << " " << getFundAmount()
		 << endl;

}

template<typename V, typename K>
void OrdinaryPerson<V, K>::read() const {



}
