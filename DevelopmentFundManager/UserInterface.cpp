#include "UserInterface.h"
#include <iostream>
#include <string>
using namespace std;

void UserInterface::printMainUI() const {

	cout << " [1] ��ü ��ȸ / [2] �ű� ��Ź�� ��� / [3] ��Ź���� ����"
		<< "/ [4] ��Ź�� ���� / [5] ���� : ";
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
		<< endl << endl;
}

void UserInterface::printGoodByeMessage() const {

	cout << endl << "Good Bye!! ... " << endl;
}

void UserInterface::printInvalidInputMessage() const {

	cout << "�ùٸ��� ���� �Է��Դϴ�." << endl;
}

void UserInterface::printFileNotFoundError() const {

	cout << "File Not Found Error" << endl;
}

// ����ó�� �ʿ�
const int UserInterface::readInt() const {

	int i;
	cin >> i;

	return i;
}

const string UserInterface::readLine() const {

	string line = readLine();
	return line;

}