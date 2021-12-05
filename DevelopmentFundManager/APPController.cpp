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

	if (command == "C" || command == "c") exit();

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

	cout << "저장을 완료했습니다" << endl << endl;

}

void APPController::exit() { 
	
	isRunning = false;
	ui.printGoodByeMessage();
}

const bool APPController::getRunningState() const {

	return isRunning;
}

void APPController::fileNotFound() {

	ui.printFileNotFoundError();
}

bool APPController::readFile(const string _fileName) {

	fileName = _fileName;

	ifstream inStream;
	inStream.open(fileName);

	if (inStream.is_open() == false) {

		cout << "    파일을 열 수 없습니다." << endl;
		// inStream.close();
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
	// 파일 네임 다시 받기 예외 처리
}

void APPController::printAll() {

	cout << endl;
	int size = personList.getSize();

	if(size == 0) cout << "No Data";

	else {

		cout << "<후원자 전체 조회> : 총 ";
		cout << size << "명이 후원하였습니다." << endl << endl;

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
		// 중복 발생
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
		cout << "성공 : ";
		cout << *person << endl << endl;
	}
	else cout << "실패 : id 또는 전화번호 중복" << endl;

}

void APPController::updateFundAmount() {

	ui.printUpdateUI();
	string key = ui.readLine();

	ui.printFundAmountUI();
	int amount = ui.readInt();

	Person* target = personList.deleteWithKey(key);

	cout << endl;
	if (target == NULL) ui.printPersonNotFoundError();
	else {
		target->setFundAmount(target->getFundAmount() + amount);
		cout << "<변경> " << *target << endl;
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
		cout << "<삭제> " << *target << endl;
		delete target;
	}

	cout << endl;
}