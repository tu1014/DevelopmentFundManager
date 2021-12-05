#include "APPController.h"
#include "UserInterface.h"

int main(int argc, char* argv[]) {

	APPController controller;

	if (argc != 2) {

		cout << "����� ���ڿ� �Բ� �������ּ���." << endl;
		return 1;
	}

	string fileName = argv[1];
	while (controller.readFile(fileName) == false) {

		cout << "���ϸ��� �ٽ� �Է��ϼ��� :";
		cin >> fileName;
		cout << endl << endl;
		
	}

	while (controller.getRunningState()) {

		int command = controller.readCommand();
		controller.executeCommand(command);
	}


	return 0;

}