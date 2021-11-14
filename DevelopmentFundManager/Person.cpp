#include "Person.h"
#include "string"

template<typename V, typename K>
Person<V, K>::~Person() {

	// new�� ����Ͽ� ���� �Ҵ��� ����� ���ؼ��� delete ����
	// delete name;
	// delete phoneNumber;

}

template<typename V, typename K>
Person<V, K>::Person(string _name, K _phoneNumber, V _fundAmount) {

	name = _name;
	phoneNumber = _phoneNumber;
	fundAmount = _fundAmount;

}


template<typename V, typename K>
bool Person<V, K>::addFundAmount(V amount) {

	// �̰� �����Ѱ�?
	if (amount < 0) return false;

	fundAmount += amount;
	return true;

}

template<typename V, typename K>
const string Person<V, K>::getName() const { return name; }

template<typename V, typename K>
const K Person<V, K>::getPhoneNumber() const  { return phoneNumber; }

template<typename V, typename K>
const V Person<V, K>::getFundAmount() const { return fundAmount; }