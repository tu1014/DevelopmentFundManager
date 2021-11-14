#pragma once
#include <string>
#include "Person.h"

class OrdinaryPerson : public Person
{
public:

	OrdinaryPerson(
		string name,
		string phoneNumber,
		int fundAmount
	);

	void print() const;
	void read() const;

	// set lastCode
	// get lastCode �ʿ�


private:

	// ���α׷� ���� �� ������ �а� ������ ��Ź�� �ڵ带 ������Ʈ ���־�� ��
	// ���Ͽ��� �Ϲ��� �о���� �� ���� ũ�� ���Ͽ� ����������
	static string lastCode;

	string depositorCode;



};
