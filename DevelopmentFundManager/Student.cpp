#include "Student.h"

Student::Student(
	string name,
	string phoneNumber,
	int fundAmount,
	string _department,
	string _stdNumber
)
{

	Person(name, phoneNumber, fundAmount);
	department = _department;
	stdNumber = _stdNumber;


}