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

void APPController::start() {

	ui.printWelcome();
	isRunning = true;
}

const int APPController::readCommand() const {

	ui.printMainUI();
	int command = ui.readInt();

	return command;
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

		checkQuit();
		break;

	default:

		ui.printInvalidInputMessage();
		break;
	}

	cout << endl << endl;

}

void APPController::checkQuit() {
	ui.printQuitUI(fileName);
	string command = ui.readLine();

	if (command == "C" || command == "c") {
		exit();
	}

	else if (command == "W" || command == "w") {
		save();
		exit();
	}

	else {
		ui.printInvalidInputMessage();
	}

}

void APPController::save() {

	ofstream outStream;
	outStream.open(fileName);

	MyList<Person>::Iterator iterator = personList.begin();
	MyList<Person>::Iterator end = personList.end();

	for (iterator; iterator != end; ++iterator) {
		(*iterator).write(outStream);
	}

	cout << "������ �Ϸ��߽��ϴ�" << endl << endl;

}

void APPController::exit() { 
	
	isRunning = false;
	ui.printGoodByeMessage();
}

const bool APPController::getRunningState() const {

	return isRunning;
}

bool APPController::readFile(const string& _fileName) {

	fileName = _fileName;

	ifstream inStream;
	inStream.open(fileName);

	if (inStream.is_open() == false) {

		ui.printFileNotFoundError();
		inStream.close();
		return false;
	}

	string line;

	Person* person;

	while (inStream.eof() == false) {

		getline(inStream, line);
		person = Person::stringToPerson(line);
		insert(person);
		person = NULL;
	}

	inStream.close();
	return true;
}

void APPController::printAll() const {

	cout << endl;
	int size = personList.getSize();

	if(size == 0) cout << "No Data";

	else {

		cout << "<�Ŀ��� ��ü ��ȸ> : �� ";
		cout << size << "���� �Ŀ��Ͽ����ϴ�." << endl << endl;

		MyList<Person>::Iterator iterator = personList.begin();
		MyList<Person>::Iterator end = personList.end();

		for (iterator; iterator != end; ++iterator) {
			cout << *iterator << endl;
		}

	}

	cout << endl;
}

bool APPController::insert(Person* person) {

	if (person == NULL) return false;

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

	if (person == NULL) {

		cout << "���� : �ùٸ��� ���� �Է�" << endl;
		return;
	}

	if (insert(person)) {
		cout << "���� : ";
		cout << *person << endl << endl;
	}
	else cout << "���� : id �Ǵ� ��ȭ��ȣ �ߺ�" << endl;

}

void APPController::updateFundAmount() {

	ui.printUpdateUI();
	string key = ui.readLine();

	ui.printFundAmountUI();
	int amount = ui.readInt();

	if (amount <= 0) {
		cout << "�߸��� �ݾ� �Է�" << endl << endl;
		return;
	}

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