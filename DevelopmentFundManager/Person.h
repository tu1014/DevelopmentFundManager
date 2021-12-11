#pragma once
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Person
{

public:

	Person();
	Person(string name, string phoneNumber, int fundAmount);
	virtual ~Person(); // 동적 할당 멤버 없다 >> default 사용?

	bool addFundAmount(int amount);
	const string getName() const;
	const string getPhoneNumber() const;
	const int getFundAmount() const;

	bool operator>(const Person& person) const;
	bool operator<(const Person& person) const;

	void setName(const string& name);
	void setPhoneNumber(const string& phoneNumber);
	void setFundAmount(const int fundAmount);
	
	virtual bool isDuplicatedKey(const string& key) const = 0;

	virtual void read(stringstream& ss) = 0;
	virtual void write(ofstream& outStream) const = 0;
	virtual void print() const = 0;
	virtual bool isValid() const = 0;
	bool isValidPhoneNumber(const string& number) const;

	virtual bool operator==(const Person& person) const = 0;
	virtual bool operator==(const string& key) const = 0;
	

	friend ostream& operator<<(ostream& outputStream, const Person& person);

	static Person* stringToPerson(string& line);

private:

	string name;
	string phoneNumber;
	int fundAmount;



};

