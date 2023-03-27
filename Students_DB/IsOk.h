#pragma once
#include <string>

bool IsCorrectDate(std::string sDate) {
	if (sDate.length() < 8 || sDate.length() > 10) {
		return false;
	}
	else {
		int day = 0;
		int month = 0;
		int year = 0;
		int flag = 0;
		for (int i = 0; i < sDate.length(); i++) {
			if (sDate[i] == '.') flag++;
			else if (flag == 0 && ((int)sDate[i] - 48) >= 0 && ((int)sDate[i] - 48) <= 9) day = day * 10 + ((int)sDate[i] - 48);
			else if (flag == 1 && ((int)sDate[i] - 48) >= 0 && ((int)sDate[i] - 48) <= 9) month = month * 10 + ((int)sDate[i] - 48);
			else if (flag == 2 && ((int)sDate[i] - 48) >= 0 && ((int)sDate[i] - 48) <= 9) year = year * 10 + ((int)sDate[i] - 48);
			else return false;
		}
		if (day < 1) {
			return false;
		}
		switch (month) {
		case 1: {
			if (day > 31) {
				return false;
			}
			else break;
		}
		case 2: {
			if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
				if (day > 29) {
					return false;
				}
				else break;
			}
			else {
				if (day > 28) {
					return false;
				}
				else break;
			}
		}
		case 3: {
			if (day > 31) {
				return false;
			}
			else break;
		}
		case 4: {
			if (day > 30) {
				return false;
			}
			else break;
		}
		case 5: {
			if (day > 31) {
				return false;
			}
			else break;
		}
		case 6: {
			if (day > 30) {
				return false;
			}
			else break;
		}
		case 7: {
			if (day > 31) {
				return false;
			}
			else break;
		}
		case 8: {
			if (day > 31) {
				return false;
			}
			else break;
		}
		case 9: {
			if (day > 30) {
				return false;
			}
			else break;
		}
		case 10: {
			if (day > 31) {
				return false;
			}
			else break;
		}
		case 11: {
			if (day > 30) {
				return false;
			}
			else break;
		}
		case 12: {
			if (day > 31) {
				return false;
			}
			else break;
		}
		default: {
			return false;
		}
		}
		if (year < 1900 || year > 2005) {
			return false;
		}
		return true;
	}
}
