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

void APPController::readFile(const string fileName) {

	dataManipulator.readFile(fileName);
}

void APPController::executeCommand(const int command) {

	switch (command) {

	case PRINT_ALL:

		cout << 1 << endl;
		break;

	case REGISTER:

		cout << 2 << endl;
		break;

	case UPDATE:

		cout << 3 << endl;
		break;

	case DELETE:

		cout << 4 << endl;
		break;

	case QUIT:

		// cout << 5 << endl;
		exit();
		break;

	default:

		ui.printInvalidInputMessage();
		break;
	}

}