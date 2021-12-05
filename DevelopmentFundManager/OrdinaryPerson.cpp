#include "OrdinaryPerson.h"
#include <iostream>
using namespace std;

const int OrdinaryPerson::CODE_PART_INDEX = 0;
const int OrdinaryPerson::SEQ_PART_INDEX = 1;
const int OrdinaryPerson::SEQ_PART_LENGTH = 5;
string OrdinaryPerson::lastCode = "";

OrdinaryPerson::OrdinaryPerson(
	string name,
	string phoneNumber,
	int fundAmount

) : Person(name, phoneNumber, fundAmount)

{

	// TODO: static 멤버 사용하여 기탁자 코드 부여
	// 현재는 임시 코드부여
	depositorCode = "V0000001";

}

OrdinaryPerson::OrdinaryPerson() : Person() {}

void OrdinaryPerson::print() const {

	cout << "   [ 일반 ] " << getName() << "(기탁자코드:" 
		 << depositorCode << ") "
		 << getPhoneNumber() << " " << getFundAmount();

}

void OrdinaryPerson::read(stringstream& ss) {

	string tmp;
	ss >> tmp;

	// 파일에서 읽어들일 때
	if (tmp[CODE_PART_INDEX] == 'V') {

		depositorCode = tmp;

		string name;
		ss >> name;
		setName(name);

		// static 멤버 갱신
		if (depositorCode > lastCode) lastCode = depositorCode;

	}

	//// 콘솔에서 입력할 때
	else {

		int seqNum = stoi(lastCode.substr(SEQ_PART_INDEX));
		seqNum++;

		int count = 0;
		int tmpNum = seqNum;
		while (tmpNum != 0) {
			tmpNum = tmpNum / 10;
			++count;
		}

		string newCode = "V";
		for (int i = 0; i < SEQ_PART_LENGTH - count; i++) {
			newCode.append("0");
		}
		newCode.append(to_string(seqNum));

		lastCode = newCode;
		depositorCode = newCode;

		setName(tmp);

	}

	string phoneNumber;
	ss >> phoneNumber;
	setPhoneNumber(phoneNumber);

	int fundAmount;
	ss >> fundAmount;
	setFundAmount(fundAmount);

}

bool OrdinaryPerson::isDuplicatedKey(string key) const {

	if (key == getPhoneNumber()) return true;
	if (key == depositorCode) return true;

	return false;
}

bool OrdinaryPerson::operator==(const Person& person) const {

	if (person.isDuplicatedKey(getPhoneNumber())) return true;
	if (person.isDuplicatedKey(depositorCode)) return true;

	else return false;
}

bool OrdinaryPerson::operator==(const string& key) const {

	if (isDuplicatedKey(key)) return true;
	if (isDuplicatedKey(key)) return true;

	else return false;
}
