#include "APPController.h"
#include "UserInterface.h"
#include <fstream>
#include <sstream>
#include "Student.h"
#include "Person.h"
#include "OrdinaryPerson.h"
#include "Staff.h"

// command
const int APPController::PRINT_ALL = 1;
const int APPController::REGISTER = 2;
const int APPController::UPDATE = 3;
const int APPController::DELETE = 4;
const int APPController::QUIT = 5;

APPController::APPController() {

	start();
}

void APPController::exit() { 
	
	isRunning = false;
	ui.printGoodByeMessage();
}

void APPController::start() {

	ui.printWelcome();
	isRunning = true;
}

const bool APPController::getRunningState() const {

	return isRunning;
}

const int APPController::readCommand() const {

	ui.printMainUI();
	int command = ui.readInt();

	return command;
}

void APPController::fileNotFound() {

	ui.printFileNotFoundError();
}

bool APPController::readFile(const string _fileName) {

	fileName = _fileName;

	ifstream inStream;
	inStream.open(fileName);

	if (inStream.is_open() == false) {

		cout << "    ������ �� �� �����ϴ�." << endl;
		return false;
	}

	string line;

	Person* person;

	while (inStream.eof() == false) {

		getline(inStream, line);
		// cout << line << endl;

		person = Person::stringToPerson(line);

		insert(person);

		person = NULL;

	}

	return true;
	// ���� ���� �ٽ� �ޱ� ���� ó��
}

void APPController::printAll() {

	cout << endl;
	int size = personList.getSize();

	if(size == 0) cout << "No Data";

	else {

		cout << "<�Ŀ��� ��ü ��ȸ> : �� ";
		cout << size << "���� �Ŀ��Ͽ����ϴ�." << endl << endl;
		personList.print();

	}

	cout << endl;
}

bool APPController::insert(Person* person) {

	if (person == NULL) {

		// cout << "�߸��� ���ڵ�" << endl;
		// �߸��� �Է� ������ (���Ŀ� ���� �ʴ� ������?)
		return false;

	}

	if (personList.insert(person) == false) {
		// �ߺ� �߻�
		delete person;
		return false;
	}

	return true;

}

void APPController::registerPerson() {

	ui.printRegisterUI();
	string line = ui.readLine();

	Person* person = Person::stringToPerson(line);

	cout << endl;

	if (insert(person)) {
		cout << "���� : ";
		cout << *person << endl << endl;
	}
	else cout << "����" << endl;

}

void APPController::updateFundAmount() {

	ui.printUpdateUI();
	string key = ui.readLine();

	ui.printFundAmountUI();
	int amount = ui.readInt();

	// ���� �� �����?
	Person* target = personList.deleteWithKey(key);

	cout << endl;
	if (target == NULL) ui.printPersonNotFoundError();
	else {
		target->setFundAmount(target->getFundAmount() + amount);
		cout << "<����> " << *target << endl;
		insert(target);
	}

	cout << endl;

}

void APPController::deletePerson() {

	ui.printDeleteUI();
	string key = ui.readLine();

	Person* target = personList.deleteWithKey(key);

	if (target == NULL) ui.printPersonNotFoundError();
	else {
		cout << "<����> " << *target << endl;
		delete target;
	}

	cout << endl;
}


void APPController::executeCommand(const int command) {

	switch (command) {

	case PRINT_ALL:

		printAll();
		break;

	case REGISTER:

		registerPerson();
		break;

	case UPDATE:

		updateFundAmount();
		break;

	case DELETE:

		deletePerson();
		break;

	case QUIT:

		exit();
		break;

	default:

		ui.printInvalidInputMessage();
		break;
	}

	cout << endl << endl;

}