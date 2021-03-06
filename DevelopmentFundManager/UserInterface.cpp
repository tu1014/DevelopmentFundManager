#include "UserInterface.h"
#include <iostream>
#include <string>
using namespace std;

void UserInterface::printMainUI() const {

	cout << "[1] 전체 조회 / [2] 신규 기탁자 등록 / [3] 기탁정보 변경"
		<< "/ [4] 기탁자 삭제 / [5] 종료" << endl << endl;
	cout << "메뉴를 선택하세요 : ";
}

void UserInterface::printRegisterUI() const {

	cout << "신규 기탁자 정보를 입력하세요 : ";
}

void UserInterface::printUpdateUI() const {

	cout << "변경을 원하는 사번이나 학번 또는 전화번호(XXX-XXXX-XXXX)를 입력하세요 : ";
}

void UserInterface::printDeleteUI() const {

	cout << "삭제를 원하는 사번이나 학번 또는 전화번호(XXX-XXXX-XXXX)를 입력하세요 : ";
}

void UserInterface::printQuitUI(string fileName) const {

	cout << "변경 사항을 " << fileName << "에 저장하려면 W/w, "
		<< fileName << "을 이전 상태로 유지하려면 C/c : ";
}

void UserInterface::printWelcome() const {

	cout << endl << endl
		<< "***********************************"
		<< "발전기금 관리 프로그램"
		<< "***********************************"
		<< endl << endl << endl << endl;
}

void UserInterface::printGoodByeMessage() const {

	cout << endl << "Good Bye!! ... " << endl;
}

void UserInterface::printInvalidInputMessage() const {

	cout << endl << ">>  올바르지 않은 입력입니다." << endl;
}

void UserInterface::printFileNotFoundError() const {

	cout << "File Not Found Error" << endl;
}

const int UserInterface::readInt() const {

	int i = 0;
	cin >> i;
	cout << endl;

	if (cin.fail()) {
		cin.clear();
		cin.ignore();
	}

	return i;
}

const string UserInterface::readLine() const {

	string line;
	cin.ignore();
	getline(cin, line);
	cout << endl;
	return line;

}

void UserInterface::printFundAmountUI() const {

	cout << "추가 기탁액을 입력하세요 : ";
}

void UserInterface::printPersonNotFoundError() const {

	cout << "후원자를 찾을 수 없습니다." << endl << endl;
}