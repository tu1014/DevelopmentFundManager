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

		// cout << "잘못된 레코드" << endl;
		// 잘못된 입력 데이터 (형식에 맞지 않는 데이터?)
		return false;

	}

	if (personList.insert(person) == false) {
		// 중복 발생
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

		cout << "    파일을 열 수 없습니다." << endl;
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

Person* DataManipulator::updateFundAmount(const string& key, int fundAmount) {

	// 음수  예외 처리??
	/*Person* target = personList.getItemWithKey(key);

	if (target == NULL) return NULL;

	(*target).setFundAmount(target->getFundAmount() + fundAmount);
	return target;*/

	Person* person = deletePerson(key);
	if (person == NULL) return NULL;

	(*person).setFundAmount(person->getFundAmount() + fundAmount);
	insert(person);

	return person;
}

Person* DataManipulator::deletePerson(const string& key) {

	return personList.deleteWithKey(key);

}
