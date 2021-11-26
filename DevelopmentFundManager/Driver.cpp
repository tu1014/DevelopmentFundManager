#include "APPController.h"
#include "UserInterface.h"

int main(int argc, char* argv[]) {

	APPController controller;

	if (argc != 2) {

		controller.fileNotFound();
		return 1;
	}

	// 명령형 인자 넣어주기 예외처리 : 파일 명 다시 입력 while문 돌리기
	if (controller.readFile(argv[1]) == false) {

		return 1;
	}

	while (controller.getRunningState()) {

		int command = controller.readCommand();
		controller.executeCommand(command);
	}


	return 0;

}