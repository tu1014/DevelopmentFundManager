#include "APPController.h"
#include "UserInterface.h"

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

bool APPController::readFile(const string fileName) {

	return dataManipulator.readFile(fileName);
	// ���� ���� �ٽ� �ޱ� ���� ó��
}

void APPController::printAll() {

	cout << endl;

	if (dataManipulator.isEmpty()) cout << "No Data";

	else {
		cout << "<�Ŀ��� ��ü ��ȸ> : �� ";
		cout << dataManipulator.getSize() << "���� �Ŀ��Ͽ����ϴ�." << endl << endl;
		dataManipulator.printAll();
	}

	cout << endl;
	

}

void APPController::registerPerson() {

	ui.printRegisterUI();
	string line = ui.readLine();

	Person* person = Person::stringToPerson(line);

	cout << endl;

	if (dataManipulator.insert(person)) {
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

	Person* target = dataManipulator.updateFundAmount(key, amount);

	cout << endl;
	if (target == NULL) ui.printPersonNotFoundError();
	else cout << "<����> " << *target << endl;

	cout << endl;

}

void APPController::deletePerson() {

	ui.printDeleteUI();
	string key = ui.readLine();

	Person* target = dataManipulator.deletePerson(key);

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

		// cout << 5 << endl;
		exit();
		break;

	default:

		ui.printInvalidInputMessage();
		break;
	}

	cout << endl << endl;

}