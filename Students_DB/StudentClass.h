#pragma once
#include <regex>
#include "DateClass.h"
#include "List.h"
using namespace std;

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
			if (namestring[i] == ' ') return 1;																					  //проверка на пробелы
			if (((namestring[i] >= 65) && (namestring[i] <= 90)) || ((namestring[i] >= 97) && (namestring[i] <= 122))) return 2;  //проверка на иностранные символы
			if ((namestring[i] >= 48) && (namestring[i] <= 57)) return 3;														  //проверка на числа 
			if (!((namestring[i] >= -64) && (namestring[i] <= -1) || (namestring[i] != -88) || (namestring[i] <= -72))) return 4; //проверка на все остальное
		}
		return 0;
	}
	
public:
	StudentClass() {
		name = { "Undefined", "Undefined", "Undefined" };
		birthDate.SetDate("01.01.1970");
		admissionYear = 1970;
		fuculty = "Undefined";
		department = "Undefined";
		group = "Undefined";
		accountBookNumber = "Undefined";
		sex = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 10; j++) {
				examMarks[i][j].mark = -1;
				examMarks[i][j].name = "Undefined";
			}
		}
	}

	int SetFirstName(std::string namestring) {
		if (NameCheck(namestring) == 0) name.firstName = namestring;
		return NameCheck(namestring);
	}

	string GetFirstName() {
		return name.firstName;
	}

	int SetSecondName(std::string namestring){
		if (NameCheck(namestring) == 0) name.secondName = namestring;
		return NameCheck(namestring);
	}

	string GetSecondName() {
		return name.secondName;
	}

	int SetSurName(std::string namestring){
		if (NameCheck(namestring) == 0) name.surName = namestring;
		return NameCheck(namestring);
	}

	string GetSurName() {
		return name.surName;
	}

	bool SetBirthDate(std::string snDate){
		return birthDate.SetDate(snDate);
	}

	DateClass GetBirthDate(){
		return birthDate;
	}

	int SetAdmissionYear(string datestring) {
		int _year = 0;
		for (int i = 0; i < datestring.length(); i++) {
			if (!((datestring[i] >= 48) && (datestring[i] <= 57))) return 1;  //проверка на все кроме чисел
			else {
				_year = _year * 10 + ((int)datestring[i] - 48);
			}
		}
		if (_year > 2023 || _year < 1970) return 2; //некорректность даты
		admissionYear = _year;
		return 0;
	}

	unsigned int GetAdmissionYear(){
		return admissionYear;
	}

	int SetFuculty(string _fuculty){
		if (NameCheck(_fuculty) == 0) fuculty = _fuculty;
		return NameCheck(_fuculty);
	}

	std::string GetFuculty(){
		return fuculty;
	}

	int SetDepartment(string _department){
		static const regex regex_department("[А-Я]{2}[-][0-9]");
		if (regex_match(_department.c_str(), regex_department)) department = _department;
		return regex_match(_department.c_str(), regex_department);
	}

	std::string GetDepartment(){
		return department;
	}

	bool SetGroup(string _group) {
		static const regex regex_group("[А-Я]{4}[-][0-9]{2}[-][0-9]{2}");
		if (regex_match(_group.c_str(), regex_group)) group = _group;
		return regex_match(_group.c_str(), regex_group);
	}

	std::string GetGroup() {
		return group;
	}

	bool SetAccountBookNumber(string _accBook) {
		static const regex regex_AccBook("[0-9]{2}[А-Я][0-9]{4}");
		if (regex_match(_accBook.c_str(), regex_AccBook)) accountBookNumber = _accBook;
		return regex_match(_accBook.c_str(), regex_AccBook);
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

	void SetValueMark(int _semester, int _pos, int _value) {
		examMarks[_semester][_pos].mark = _value;
	}

	void SetNameMark(int _semester, int _pos, string _name) {
		examMarks[_semester][_pos].name = _name;
	}

	int GetValueMark(int _semester, int _pos) {
		return examMarks[_semester][_pos].mark;
	}

	string GetNameMark(int _semester, int _pos) {
		return examMarks[_semester][_pos].name;
	}
};


