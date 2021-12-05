#include "APPController.h"
#include "UserInterface.h"

int main(int argc, char* argv[]) {

	APPController controller;

	if (argc != 2) {

		cout << "명령형 인자와 함께 실행해주세요." << endl;
		return 1;
	}

	string fileName = argv[1];
	while (controller.readFile(fileName) == false) {

		cout << "파일명을 다시 입력하세요 :";
		cin >> fileName;
		cout << endl << endl;
		
	}

	while (controller.getRunningState()) {

		int command = controller.readCommand();
		controller.executeCommand(command);
	}


	return 0;

}