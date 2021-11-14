#pragma once
#include <string>
using namespace std;

template<typename V, typename K>
class Person
{

public:

	Person(string name, K phoneNumber, V fundAmount);
	~Person(); // 동적 할당 멤버 없다 >> default 사용?

	bool addFundAmount(V amount);
	const string getName() const;
	const K getPhoneNumber() const;
	const V getFundAmount() const;

	// friend 함수는 가상 함수로 선언 불가 >> 멤버 함수로 사용하자
	virtual void read() const = 0;
	virtual void print() const = 0;


private:

	string name;
	K phoneNumber;
	V fundAmount;



};

