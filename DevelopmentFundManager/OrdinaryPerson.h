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
	// get lastCode 필요

	bool isDuplicatedKey(string key) const;

	bool operator==(const Person& person) const;


private:

	// 프로그램 시작 시 파일을 읽고 마지막 기탁자 코드를 업데이트 해주어야 함
	// 파일에서 일반인 읽어들일 때 마다 크기 비교하여 갱신해주자
	static string lastCode;

	string depositorCode;



};

