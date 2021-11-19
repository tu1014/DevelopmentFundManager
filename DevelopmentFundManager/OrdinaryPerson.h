#pragma once
#include <string>
#include <sstream>
#include "Person.h"

class OrdinaryPerson : public Person
{
public:

	OrdinaryPerson();

	OrdinaryPerson(
		string name,
		string phoneNumber,
		int fundAmount
	);

	void print() const;
	void read(stringstream& ss);

	// set lastCode
	// get lastCode �ʿ�

	bool isDuplicatedKey(string key) const;

	bool operator==(const Person& person) const;


private:

	// ���α׷� ���� �� ������ �а� ������ ��Ź�� �ڵ带 ������Ʈ ���־�� ��
	// ���Ͽ��� �Ϲ��� �о���� �� ���� ũ�� ���Ͽ� ����������
	static string lastCode;

	string depositorCode;



};

