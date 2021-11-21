#include "DataManipulator.h"
#include <fstream>
#include <string>
#include <sstream>
#include "Student.h"
#include "Person.h"
#include "OrdinaryPerson.h"
#include "Staff.h"
using namespace std;

DataManipulator::DataManipulator() {

}

void DataManipulator::setFileName(const string _fileName) {

	fileName = _fileName;
}

bool DataManipulator::isEmpty() const { return (personList.getSize() == 0); }

void DataManipulator::printAll() const { personList.print(); }

bool DataManipulator::readFile(const string _fileName) {

	fileName = _fileName;

	ifstream inStream;
	inStream.open(fileName);

	if (inStream.is_open() == false) {

		cout << "    파일을 열 수 없습니다." << endl;
		return false;
	}

	string line;
	
	Person* person;

	while (inStream.eof() == false) {

		getline(inStream, line);
		// cout << line << endl;

		person = Person::stringToPerson(line);

		if (person == NULL) {

			cout << "잘못된 레코드" << endl;
			continue;
		}

		if (personList.insert(*person) == false) delete person;
		person = NULL;

	}

	return true;

}
