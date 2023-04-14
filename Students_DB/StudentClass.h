#pragma once
#include "DateClass.h"
#include "MarksClass.h"

struct FullName {
	std::string firstName;
	std::string secondName;
	std::string surName;
};

struct Mark {
	std::string name;
	int mark;
};

class StudentClass {
private:
	FullName name;
	DateClass birthDate;
	unsigned int admissionYear;
	std::string fuculty;
	std::string department;
	std::string group;
	std::string accountBookNumber;
	bool sex; // man => true   woman => false
	Mark examMarks[9][10];

	int NameCheck(string namestring) {
		for (int i = 0; i < namestring.length(); i++) {
			if (namestring[i] == ' ') return 1; //не должно быть пробелов
			if (((namestring[i] >= 65) && (namestring[i] <= 90)) || ((namestring[i] >= 97) && (namestring[i] <= 122))) return 2; // проверка на иностранные символы
			if ((namestring[i] >= 48) && (namestring[i] <= 57)) return 3;  //проверка на числа 
			if (!((namestring[i] >= -64) && (namestring[i] <= -1) || (namestring[i] != -88) || (namestring[i] <= -72))) return 4; //проверка на все остальное
		}
		return 0;
	}
public:
	StudentClass() {
		name = { "", "", "" };
		birthDate.SetDate("01.01.1970");
		admissionYear = 1970;
		fuculty = "";
		department = "";
		group = "";
		accountBookNumber = "";
		sex = true;
	}
	int SetFirstName(std::string namestring) {
		if (NameCheck(namestring) == 0) name.firstName = namestring;
		return NameCheck(namestring);
	}

	int SetSecondName(std::string namestring){
		if (NameCheck(namestring) == 0) name.secondName = namestring;
		return NameCheck(namestring);
	}

	int SetSurname(std::string namestring){
		name.surName = namestring;
	}

	string GetFirstName(){
		return name.firstName;
	}

	string GetSceondName() {
		return name.secondName;
	}

	string GetSurName() {
		return name.surName;
	}

	bool SetBirthDate(std::string snDate){
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

	std::string GetFuculty(){
		return fuculty;
	}

	void SetDepartment(){
		
	}

	std::string GetDepartment(){
		return department;
	}

	void SetGroup() {

	}

	std::string GetGroup() {
		return group;
	}

	void SetAccountBookNumber() {

	}

	std::string GetAccountBookNumber() {
		return accountBookNumber;
	}

	void SetSex(bool _sex){
		sex = _sex;
	}

	bool GetSex(){
		return sex;
	}

	void SetMark(unsigned short mark, std::string , unsigned short semestr, unsigned short subj){
		examMarks[semestr][subj].mark = mark;

	}
};

