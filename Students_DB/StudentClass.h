#pragma once
#include "DateClass.h"
#include "MarksClass.h"
#include "IsOk.h"
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
	bool sex; // man => true   woman => false
	int examMarks[9][10];
public:
	StudentClass() {
		name = { "", "", "" };
		birthDate.SetDate("00.00.0000");
		admissionYear = 0;
		fuculty = "";
		department = "";
		group = "";
		accountBookNumber = "";
		sex = true;
	}
	void SetName(string nameString) {
		string localStr;
		int flag = 0;
		for (int i = 0; i < nameString.length(); i++) {
			if (nameString[i] == ' ' || nameString[i] == '\0') {
				if (flag == 0) name.firstName = localStr;
				if (flag == 1) name.secondName = localStr;
				if (flag == 2) name.surName = localStr;
				localStr = "";
				flag++;
			}
			else localStr += nameString[i];
		}
		name.surName = localStr;
	}
	FullName GetName(){
		return name;
	}

	bool SetBirthDate(string snDate){
		birthDate.SetDate(snDate);
		return true;
	}

	DateClass GetBirthDate(){
		return birthDate;
	}

	bool SetAdmissionYear(unsigned int year){
		if (year < 1947 || year > 2022) return false;
		admissionYear = year;
		return true;
	}

	unsigned int GetAdmissionYear(){
		return admissionYear;
	}

	void SetFuculty(){
		
	}

	string GetFuculty(){
		return fuculty;
	}

	void SetDepartment(){
		
	}

	string GetDepartment(){
		return department;
	}

	void SetGroup() {

	}

	string GetGroup() {
		return group;
	}

	void SetAccountBookNumber() {

	}

	string GetAccountBookNumber() {
		return accountBookNumber;
	}

	void SetSex(bool sx){
		sex = sx;
	}

	bool GetSex(){
		return sex;
	}

	void SetMark(unsigned short mark, unsigned short semestr, unsigned short subj){
		examMarks[semestr][subj] = mark;
	}
};

