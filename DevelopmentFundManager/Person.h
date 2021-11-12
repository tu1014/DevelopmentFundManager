#pragma once
#include <string>
using namespace std;

class Person
{

public:

	Person(string name, string phoneNumber, int fundAmount);
	~Person(); // 동적 할당 멤버 없다 >> default 사용?

	bool addFundAmount(int amount);
	const string getName() const;
	const string getPhoneNumber() const;
	const int getFundAmount() const;

	// friend 함수는 가상 함수로 선언 불가 >> 멤버 함수로 사용하자
	virtual void read() = 0;
	virtual void print() = 0;


private:

	string name;
	string phoneNumber;
	int fundAmount;



};

