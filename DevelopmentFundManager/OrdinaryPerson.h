#pragma once
#include <string>
#include "Person.h"

template<typename V, typename K>
class OrdinaryPerson : public Person
{
public:

	OrdinaryPerson(
		string name,
		K phoneNumber,
		V fundAmount
	);

	void print() const;
	void read() const;

	// set lastCode
	// get lastCode �ʿ�


private:

	// ���α׷� ���� �� ������ �а� ������ ��Ź�� �ڵ带 ������Ʈ ���־�� ��
	// ���Ͽ��� �Ϲ��� �о���� �� ���� ũ�� ���Ͽ� ����������
	static K lastCode;

	K depositorCode;



};

