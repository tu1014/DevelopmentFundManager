#pragma once
#include <string>
using namespace std;

class Validator
{

public:

	bool static isValidPhoneNumber(string phoneNumber);
	bool static isValidFundAmount(int amount);


private:

	bool static isDigit(char c);

};

