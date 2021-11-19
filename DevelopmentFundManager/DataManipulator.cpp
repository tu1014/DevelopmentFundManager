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

		cout << "파일을 열 수 없습니다." << endl;
		return false;
	}

	stringstream ss;
	string line;
	
	Person* person;

	while (inStream.eof() == false) {

		ss.str(""); ss.clear();
		getline(inStream, line);
		// cout << line << endl;
		ss << line;

		string personType;
		ss >> personType;

		if (personType == "학생") { person = new Student(); }
		else if (personType == "교직원") { person = new Staff(); }
		else if (personType == "일반") { person = new OrdinaryPerson(); }
		else { continue; }

		(*person).read(ss);

		if (personList.insert(*person) == false) delete person;
		person = NULL;

	}

	return true;

}
