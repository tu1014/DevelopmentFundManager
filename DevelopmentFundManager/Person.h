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

	bool operator>(const Person& person) const;
	bool operator<(const Person& person) const;
	
	virtual bool isDuplicatedKey(string key) const = 0;

	virtual void read() const = 0;
	virtual void print() const = 0;

	virtual bool operator==(const Person& person) const = 0;

	friend ostream& operator<<(ostream& outputStream, const Person& person);

private:

	string name;
	string phoneNumber;
	int fundAmount;



};

