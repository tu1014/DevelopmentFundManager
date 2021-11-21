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

bool DataManipulator::insert(Person* person) {

	if (person == NULL) {

		// cout << "�߸��� ���ڵ�" << endl;
		// �߸��� �Է� ������ (���Ŀ� ���� �ʴ� ������?)
		return false;

	}

	if (personList.insert(*person) == false) {
		// �ߺ� �߻�
		delete person;
		return false;
	}

	return true;

}

int DataManipulator::getSize() const {

	return personList.getSize();
}

bool DataManipulator::readFile(const string _fileName) {

	fileName = _fileName;

	ifstream inStream;
	inStream.open(fileName);

	if (inStream.is_open() == false) {

		cout << "    ������ �� �� �����ϴ�." << endl;
		return false;
	}

	string line;
	
	Person* person;

	while (inStream.eof() == false) {

		getline(inStream, line);
		// cout << line << endl;

		person = Person::stringToPerson(line);

		insert(person);

		person = NULL;

	}

	return true;

}
