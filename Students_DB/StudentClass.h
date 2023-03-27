#pragma once
#include "DateClass.h"
#include "MarksClass.h"
using namespace std;

struct FullName {
	string firstName;
	string secondName;
	string surName;
};

class StudentClass {
private:
	FullName name;
	DateClass birthDate;
	unsigned int admissionYear;
	string fuculty;
	string department;
	string group;
	string accountBookNumber;
	bool sex; // man => false   woman => true
	MarksClass examRecords[9][10];

public:
	StudentClass() {
		name = { "", "", "" };
		birthDate.SetDate("00.00.0000");
		admissionYear = 0;
		fuculty = "";
		department = "";
		group = "";
		accountBookNumber = "";
		sex = false;
	}
	void SetName(string nameString) {
		string localStr;
		int flag = 0;
		for (int i = 0; i < nameString.length(); i++) {
			if (nameString[i] == ' ') {
				flag++;
			}
			else localStr += nameString[i];
		}
	}
	//todo доделать добавление имен, сеттеры, геттеры
};

