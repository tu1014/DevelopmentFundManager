#include "OrdinaryPerson.h"
#include <iostream>

template<typename V, typename K>
OrdinaryPerson<V, K>::OrdinaryPerson(
	string name,
	K phoneNumber,
	V fundAmount

) : Person(name, phoneNumber, fundAmount)

{

	// TODO: static 멤버 사용하여 기탁자 코드 부여
	// 현재는 임시 코드부여
	depositorCode = "";

}

template<typename V, typename K>
void OrdinaryPerson<V, K>::print() const {

	cout << "[ 일반 ] " << getName() << "(기탁자코드:" 
		 << depositorCode << ") "
		 << getPhoneNumber() << " " << getFundAmount()
		 << endl;

}

template<typename V, typename K>
void OrdinaryPerson<V, K>::read() const {



}
