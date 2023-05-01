#pragma once
#include "List.h"
#include "StudentClass.h"
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <regex>
#include "DateClass.h"

#define DOWN 80
#define UP 72
#define ENTER 13
#define ESCAPE 27


int NameCheck(std::string _nameString);

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
	std::string faculty;
	std::string department;
	std::string group;
	std::string accountBookNumber;
	bool sex; // man => true   woman => false
	Mark examMarks[9][10];
	float averageMark;

public:
	StudentClass() {
		name = { "Undefined", "Undefined", "Undefined" };
		birthDate.SetDate("01.01.1970");
		admissionYear = 1970;
		faculty = "Undefined";
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
		averageMark = 0;
	}

	int SetFirstName(std::string _nameString) {
		if (NameCheck(_nameString) == 0) name.firstName = _nameString;
		return NameCheck(_nameString);
	}

	std::string GetFirstName() {
		return name.firstName;
	}

	int SetSecondName(std::string _nameString){
		if (NameCheck(_nameString) == 0) name.secondName = _nameString;
		return NameCheck(_nameString);
	}

	std::string GetSecondName() {
		return name.secondName;
	}

	int SetSurName(std::string _nameString){
		if (NameCheck(_nameString) == 0) name.surName = _nameString;
		return NameCheck(_nameString);
	}

	std::string GetSurName() {
		return name.surName;
	}

	bool SetBirthDate(std::string _stringDate){
		return birthDate.SetDate(_stringDate);
	}

	DateClass GetBirthDate() const{
		return birthDate;
	}

	int SetAdmissionYear(std::string _stringDate) {
		int _year = 0;
		for (int i = 0; i < _stringDate.length(); i++) {
			if (!((_stringDate[i] >= 48) && (_stringDate[i] <= 57))) return 1;  //проверка на все кроме чисел
			else {
				_year = _year * 10 + ((int)_stringDate[i] - 48);
			}
		}
		if (_year > 2023 || _year < 1970) return 2; //некорректность даты
		admissionYear = _year;
		return 0;
	}

	unsigned int GetAdmissionYear() const {
		return admissionYear;
	}

	int SetFaculty(std::string _faculty){
		if (NameCheck(_faculty) == 0) faculty = _faculty;
		return NameCheck(_faculty);
	}

	std::string GetFaculty(){
		return faculty;
	}

	int SetDepartment(std::string _department){
		static const std::regex regexDepartment("[А-Я]{2}[-][0-9]{1,2}");
		if (std::regex_match(_department.c_str(), regexDepartment)) department = _department;
		return std::regex_match(_department.c_str(), regexDepartment);
	}

	std::string GetDepartment(){
		return department;
	}

	bool SetGroup(std::string _group) {
		static const std::regex regexGroup("[А-Я]{4}[-][0-9]{2}[-][0-9]{2}");
		if (std::regex_match(_group.c_str(), regexGroup)) group = _group;
		return std::regex_match(_group.c_str(), regexGroup);
	}

	std::string GetGroup() {
		return group;
	}

	bool SetAccountBookNumber(std::string _accountBookNumber) {
		static const std::regex regexAccountBookNumber("[0-9]{2}[А-Я][0-9]{4}");
		if (std::regex_match(_accountBookNumber.c_str(), regexAccountBookNumber)) accountBookNumber = _accountBookNumber;
		return std::regex_match(_accountBookNumber.c_str(), regexAccountBookNumber);
	}

	std::string GetAccountBookNumber() {
		return accountBookNumber;
	}

	void SetSex(bool _sex){
		sex = _sex;
	}

	bool GetSex() const{
		return sex;
	}

	void SetValueMark(int _semester, int _numberOfMark, int _value) {
		examMarks[_semester][_numberOfMark].mark = _value;
		CalculateAverageMark();
	}

	void SetNameMark(int _semester, int _numberOfMark, std::string _name) {
		examMarks[_semester][_numberOfMark].name = _name;
	}

	int AddNameMark(int _semester, std::string _name) {
		for (int i = 0; i < 10; i++) {
			if (examMarks[_semester][i].name == "Undefined") {
				examMarks[_semester][i].name = _name;
				return i;
			}
		}
		return -1;
	}

	int GetValueMark(int _semester, int _numberOfMark) const{
		return examMarks[_semester][_numberOfMark].mark;
	}

	std::string GetNameMark(int _semester, int _numberOfMark) {
		return examMarks[_semester][_numberOfMark].name;
	}

	int GetNumberOfMarks(int _semester) const{
		int count = 0;
		for (int i = 0; i < 10; i++) {
			if (examMarks[_semester][i].mark != -1) count++;
		}
		return count;
	}

	void DeleteMark(int _semester, int _numberOfMark) {
		int i = _numberOfMark;
		while ((i < 9) && (examMarks[_semester][i].name != "Undefined")) {
			examMarks[_semester][i] = examMarks[_semester][i + 1];
			i++;
		}
		if (i == 9 && (examMarks[_semester][i].name != "Undefined")) {
			examMarks[_semester][i].name = "Undefined";
			examMarks[_semester][i].mark = -1;
		}

		CalculateAverageMark();
	}

	void CalculateAverageMark() {
		int count = 0;
		float sum = 0;
		for (int i = 0; i < 9; i++ ) {
			for (int j = 0; j < 10; j++) {
				if (examMarks[i][j].mark >= 2) {
					count++;
					sum += examMarks[i][j].mark;
				}
			}
		}
		if (count != 0) {
			averageMark = round(sum / count * 100) / 100;
		}
	}

	float GetAverageMark() const {
		return averageMark;
	}
};



void AddFirstName(StudentClass* _student);

void AddSecondName(StudentClass* _student);

void AddSurName(StudentClass* _student);

void AddBirthDate(StudentClass* _student);

void AddAdmissionYear(StudentClass* _student);

void AddFaculty(StudentClass* _student);

void AddDepartment(StudentClass* _student);

void AddGroup(StudentClass* _student);

void AddAccountBookNumber(StudentClass* _student);

void ChooseSex(StudentClass* _student);

void AddStudent(List<StudentClass>& _students);

void AddSubject(List<std::string>& _subjects);

bool IsSubjectInSession(StudentClass* student, std::string _subject, int _semester);

void AddSessionSubject(StudentClass* student, List<std::string>& _subjectNames, int _semester);

void AddMark(StudentClass* student, int _semester, int _numberOfMark);

void DeleteSubject(List<std::string>& _subjects, int _numberOfSubject, List<StudentClass>& _students);

void ExecuteOrder66(List<StudentClass>& _students);