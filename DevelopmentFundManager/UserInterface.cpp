#include "UserInterface.h"
#include <iostream>
#include <string>
using namespace std;

void UserInterface::printMainUI() const {

	cout << "[1] ��ü ��ȸ / [2] �ű� ��Ź�� ��� / [3] ��Ź���� ����"
		<< "/ [4] ��Ź�� ���� / [5] ����" << endl << endl;
	cout << "�޴��� �����ϼ��� : ";
}

void UserInterface::printRegisterUI() const {

	cout << "�ű� ��Ź�� ������ �Է��ϼ��� : ";
}

void UserInterface::printUpdateUI() const {

	cout << "������ ���ϴ� ����̳� �й� �Ǵ� ��ȭ��ȣ(XXX-XXXX-XXXX)�� �Է��ϼ��� : ";
}

void UserInterface::printDeleteUI() const {

	cout << "������ ���ϴ� ����̳� �й� �Ǵ� ��ȭ��ȣ(XXX-XXXX-XXXX)�� �Է��ϼ��� : ";
}

void UserInterface::printQuitUI(string fileName) const {

	cout << "���� ������ " << fileName << "�� �����Ϸ��� W/w, "
		<< fileName << "�� ���� ���·� �����Ϸ��� C/c : ";
}

void UserInterface::printWelcome() const {

	cout << endl << endl
		<< "***********************************"
		<< "������� ���� ���α׷�"
		<< "***********************************"
		<< endl << endl << endl << endl;
}

void UserInterface::printGoodByeMessage() const {

	cout << endl << "Good Bye!! ... " << endl;
}

void UserInterface::printInvalidInputMessage() const {

	cout << endl << ">>  �ùٸ��� ���� �Է��Դϴ�." << endl;
}

void UserInterface::printFileNotFoundError() const {

	cout << "File Not Found Error" << endl;
}

// ����ó�� �ʿ�
const int UserInterface::readInt() const {

	int i;
	cin >> i;
	cout << endl;

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

	cout << "�߰� ��Ź���� �Է��ϼ��� : ";
}

void UserInterface::printPersonNotFoundError() const {

	cout << "�Ŀ��ڸ� ã�� �� �����ϴ�." << endl << endl;
}