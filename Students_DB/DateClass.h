#pragma once
#include <string>
using namespace std;

class DateClass{
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
public:
	DateClass() {
		day = 0;
		month = 0;
		year = 0;
	}
	void SetDate(string sDate) {
		int flag = 0;
		for (int i = 0; i < sDate.length(); i++) {
			if (sDate[i] == '.') flag++;
			else if (flag == 0) day = day * 10 + ((int)sDate[i] - 48);
			else if (flag == 1) month = month * 10 + ((int)sDate[i] - 48);
			else if (flag == 2) year = year * 10 + ((int)sDate[i] - 48);
		}
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

