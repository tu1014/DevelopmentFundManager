#pragma once
#include <string>
using namespace std;

class Person
{

public:

	Person(string name, string phoneNumber, int fundAmount);
	~Person(); // ���� �Ҵ� ��� ���� >> default ���?

	bool addFundAmount(int amount);
	const string getName() const;
	const string getPhoneNumber() const;
	const int getFundAmount() const;

	// friend �Լ��� ���� �Լ��� ���� �Ұ� >> ��� �Լ��� �������
	virtual void read() = 0;
	virtual void print() = 0;


private:

	string name;
	string phoneNumber;
	int fundAmount;



};

