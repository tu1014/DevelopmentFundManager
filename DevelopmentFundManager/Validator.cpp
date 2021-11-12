#include "Validator.h"
#include <string>
using namespace std;


bool Validator::isValidFundAmount(int amount) {

	if (amount > 0) return true;
	else return false;

}

bool Validator::isValidPhoneNumber(string phoneNumber) {

	int length = phoneNumber.length();

	if (length != 13) return false;

	for (int i = 0; i < 3; i++)
		if (isDigit(phoneNumber[i]) == false) return false;

	if (phoneNumber[3] != '-') return false;

	for (int i = 4; i < 8; i++) {
		if (isDigit(phoneNumber[i]) == false) return false;
	}

	if (phoneNumber[8] != '-') return false;

	for (int i = 9; i < 13; i++) {
		if (isDigit(phoneNumber[i]) == false) return false;
	}

	return true;

}

bool Validator::isDigit(char c) {

	return ('0' <= c && c <= '9');

}