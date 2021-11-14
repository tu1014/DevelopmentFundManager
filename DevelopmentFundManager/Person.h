#pragma once
#include <string>
using namespace std;

template<typename V, typename K>
class Person
{

public:

	Person(string name, K phoneNumber, V fundAmount);
	~Person(); // ���� �Ҵ� ��� ���� >> default ���?

	bool addFundAmount(V amount);
	const string getName() const;
	const K getPhoneNumber() const;
	const V getFundAmount() const;

	// friend �Լ��� ���� �Լ��� ���� �Ұ� >> ��� �Լ��� �������
	virtual void read() const = 0;
	virtual void print() const = 0;


private:

	string name;
	K phoneNumber;
	V fundAmount;



};

