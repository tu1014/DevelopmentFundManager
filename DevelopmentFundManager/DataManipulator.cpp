#include "DataManipulator.h"
#include <fstream>
#include <string>
using namespace std;

DataManipulator::DataManipulator() {

}

void DataManipulator::setFileName(const string _fileName) {

	fileName = _fileName;
}

bool DataManipulator::readFile(const string _fileName) {

	fileName = _fileName;

	ifstream inStream;
	inStream.open(fileName);

	if (inStream.is_open() == false) {

		cout << "������ �� �� �����ϴ�." << endl;
		return false;
	}

	string line;
	
	while (inStream.eof() == false) {

		getline(inStream, line);
		cout << line << endl;

	}

	return true;

}
