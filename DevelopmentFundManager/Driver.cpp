#include "APPController.h"
#include "UserInterface.h"

int main(int argc, char* argv[]) {

	APPController controller;

	if (argc != 2)
		controller.fileNotFound();

	
	controller.readFile(argv[1]);

	while (controller.getRunningState()) {

		int command = controller.readCommand();
		controller.executeCommand(command);
	}


	return 0;

}