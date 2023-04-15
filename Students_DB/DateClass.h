#pragma once
#include <string>
using namespace std;

class DateClass{
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
	bool IsCorrectDate(std::string sDate) {
		if (sDate.length() < 8 || sDate.length() > 10) {
			return false;
		}
		else {
			int _day = 0;
			int _month = 0;
			int _year = 0;
			int flag = 0;
			for (int i = 0; i < sDate.length(); i++) {
				if (sDate[i] == '.') flag++;
				else if (flag == 0 && ((int)sDate[i] - 48) >= 0 && ((int)sDate[i] - 48) <= 9) _day = _day * 10 + ((int)sDate[i] - 48);
				else if (flag == 1 && ((int)sDate[i] - 48) >= 0 && ((int)sDate[i] - 48) <= 9) _month = _month * 10 + ((int)sDate[i] - 48);
				else if (flag == 2 && ((int)sDate[i] - 48) >= 0 && ((int)sDate[i] - 48) <= 9) _year = _year * 10 + ((int)sDate[i] - 48);
				else return false;//19.8.2019
			}
			if (_day < 1) {
				return false;
			}
			switch (_month) {
			case 1: case 3: case 5: case 7: case 8: case 10: case 12: {
				if (_day > 31) {
					return false;
				}
				else break;
			}
			case 4: case 6: case 9: case 11: {
				if (_day > 30) {
					return false;
				}
				else break;
			}
			case 2: {
				if (_year % 400 == 0 || (_year % 100 != 0 && _year % 4 == 0)) {
					if (_day > 29) {
						return false;
					}
					else break;
				}
				else {
					if (_day > 28) {
						return false;
					}
					else break;
				}
			}
			}
			if (_year < 1900 || _year > 3000) {
				return false;
			}
			return true;
		}
	}
public:
	DateClass() {
		day = 0;
		month = 0;
		year = 0;
	}
	bool SetDate(string sDate) {
		int flag = 0;
		if (!IsCorrectDate(sDate)) return false;
		day = 0; month = 0; year = 0;
		for (int i = 0; i < sDate.length(); i++) {
			if (sDate[i] == '.') flag++;
			else if (flag == 0) day = day * 10 + ((int)sDate[i] - 48);
			else if (flag == 1) month = month * 10 + ((int)sDate[i] - 48);
			else if (flag == 2) year = year * 10 + ((int)sDate[i] - 48);
		}
		return true;
	}
	unsigned int GetDay() {
		return day;
	}
	unsigned int GetMonth() {
		return month;
	}
	unsigned int GetYear() {
		return year;
	}
};

