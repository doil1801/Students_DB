#pragma once
#include "List.h"
#include <windows.h>
#include "StudentClass.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "FileWork.h"

const int N = 55;
#define DOWN 80
#define UP 72
#define ENTER 13
#define ESCAPE 27


class ConsoleClass {
private:
	HANDLE cs = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string StartMenu = "Главное меню";
	const int lenOfStartMenu = 5;
	std::string fieldsOfStartMenu[5] = {
		"Посмотреть список студентов (изменить данные)",
		"Добавить нового студента",
		"Удалить запись студента",
		"Выполнить вариант 66",
		"Выход"
	};

	const int lenOfStudentProfile = 8;
	std::string studentProfile[8] = {
		"Имя: ",
		"Дата рождения: ",
		"Год поступления: ",
		"Институт: ",
		"Кафедра: ",
		"Группа: ",
		"Номер зачетной книжки: ",
		"Пол: ",
	};

	std::string MenuOfStudents = "Выбор студента";

	const int lenOfRedMenu = 10;
	std::string RedMenu = "Меню редактирования студентов";
	std::string fieldsOfRedMenu[10] = {
		"Добавить(изменить) имя",
		"Добавить(изменить) дату рождения",
		"Добавить(изменить) год поступления",
		"Добавить(изменить) институт",
		"Добавить(изменить) кафедру",
		"Добавить(изменить) группу",
		"Добавить(изменить) номер зачетной книжки",
		"Добавить(изменить) пол",
		"Посмотреть(изменить/добавить) оценки",
		"Выход"
	};

	const int lenOfSessionMenu = 11;
	std::string SessionMenu = "Выбор сессии";
	std::string filedsOfSessionMenu[11] = {
		"Добавить предмет",
		"Добавить/изменить сессию 1",
		"Добавить/изменить сессию 2",
		"Добавить/изменить сессию 3",
		"Добавить/изменить сессию 4",
		"Добавить/изменить сессию 5",
		"Добавить/изменить сессию 6",
		"Добавить/изменить сессию 7",
		"Добавить/изменить сессию 8",
		"Добавить/изменить сессию 9",
		"Выход"
	};

	void DrawLine() {
		std::cout.width(N); std::cout.fill('-'); std::cout << "-" << endl;
		std::cout.fill(' ');
	}

	void DrawDoubleLine() {
		std::cout.width(N); std::cout.fill('-'); std::cout << "-"; std::cout << "     "; std::cout.width(N+2); std::cout.fill('-'); std::cout << "-" << endl;
		std::cout.fill(' ');
	}

	int leng = 0;
	std::string* fieldsOfMenu = NULL;
	std::string UpNote = "";
	int Menu = 0;
	int Choice = 0;
	int action = 0;
	int menuLen = 6;
	int studentChoice = 0;
	int sessionChoice = 0;
	StudentClass edStudent;
public:
	ConsoleClass() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
	}

	void DrawMenu(){
		system("cls");
		switch (Menu) {
		case 0:
			leng = lenOfStartMenu;
			fieldsOfMenu = fieldsOfStartMenu;
			UpNote = StartMenu;
			break;
		case 1:
			leng = lenOfRedMenu;
			fieldsOfMenu = fieldsOfRedMenu;
			UpNote = RedMenu;
			break;
		case 4:
			leng = lenOfSessionMenu;
			fieldsOfMenu = filedsOfSessionMenu;
			UpNote = SessionMenu;
			break;
		} 

		
		DrawLine();
		std::cout.width(N-1); std::cout << left << "|" + UpNote; std::cout << '|' << endl;
		DrawLine();
		for (int i = 0; i < leng; i++) {
			if (i == Choice) {
				std::cout << left << "|"; std::cout.width(N - 2); SetConsoleTextAttribute(cs, FOREGROUND_GREEN); std::cout << "*" + fieldsOfMenu[i]; SetConsoleTextAttribute(cs, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); std::cout << '|' << endl;
			} else {
				std::cout.width(N - 1); std::cout << left << "| " + fieldsOfMenu[i]; std::cout << '|' << endl;
			}
		}
		DrawLine();
	}

	void DrawMenu(List<StudentClass>& _Students) {
		system("cls");
		leng = _Students.Len();
		UpNote = MenuOfStudents;


		DrawLine();
		std::cout.width(N - 1); std::cout << left << "|" + UpNote; std::cout << '|' << endl;
		DrawLine();

		for (int i = 0; i < leng; i++) {
			if (i == Choice) {
				std::cout << left << "|"; std::cout.width(N - 2); SetConsoleTextAttribute(cs, FOREGROUND_GREEN); std::cout << "*" + _Students.Get(i).GetFirstName() + ' ' + _Students.Get(i).GetSecondName() + ' ' + _Students.Get(i).GetSurName(); SetConsoleTextAttribute(cs, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); std::cout << '|' << endl;
			}
			else {
				std::cout.width(N - 1); std::cout << left << "| " + _Students.Get(i).GetFirstName() + ' ' + _Students.Get(i).GetSecondName() + ' ' + _Students.Get(i).GetSurName(); std::cout << '|' << endl;
			}
		}
		if (Choice == leng) {
			std::cout << left << "|"; std::cout.width(N - 2); SetConsoleTextAttribute(cs, FOREGROUND_GREEN);  std::cout << left << "*" + fieldsOfStartMenu[4]; SetConsoleTextAttribute(cs, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); std::cout << '|' << endl;
		} else {
			std::cout.width(N - 1); std::cout << left << "| " + fieldsOfStartMenu[4]; std::cout << '|' << endl;
		}
		DrawLine();
	}

	void DrawMenu(StudentClass _Student) {
		system("cls");
		fieldsOfMenu = fieldsOfRedMenu;
		leng = lenOfRedMenu;
		UpNote = RedMenu;


		DrawLine();
		std::cout.width(N - 1); std::cout << left << "|" + UpNote; std::cout << '|' << endl;
		DrawDoubleLine();
		for (int i = 0; i < leng; i++) {
			if (i == Choice) {
				std::cout << left << "|"; std::cout.width(N - 2); SetConsoleTextAttribute(cs, FOREGROUND_GREEN); std::cout << "*" + fieldsOfMenu[i]; SetConsoleTextAttribute(cs, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); std::cout << "|     ";
			}
			else {
				std::cout.width(N - 1); std::cout << left << "| " + fieldsOfMenu[i]; std::cout << "|     " ;
			}
			switch (i) {
			case 0:
				std::cout << left << "| "; std::cout.width(N - 1); std::cout << _Student.GetFirstName() + ' ' + _Student.GetSecondName() + ' ' + _Student.GetSurName();  std::cout << '|' << endl;
				break;
			case 1:
				std::cout << left << "| "; std::cout.width(N - 1); std::cout << to_string(_Student.GetBirthDate().GetDay()) + '.' + to_string(_Student.GetBirthDate().GetMonth()) + '.' + to_string(_Student.GetBirthDate().GetYear());  std::cout << '|' << endl;
				break;
			case 2:
				std::cout << left << "| "; std::cout.width(N - 1); std::cout << _Student.GetAdmissionYear();  std::cout << '|' << endl;
				break;
			case 3:
				std::cout << left << "| "; std::cout.width(N - 1); std::cout << _Student.GetFuculty();  std::cout << '|' << endl;
				break;
			case 4:
				std::cout << left << "| "; std::cout.width(N - 1); std::cout << _Student.GetDepartment();  std::cout << '|' << endl;
				break;
			case 5:
				std::cout << left << "| "; std::cout.width(N - 1); std::cout << _Student.GetGroup();  std::cout << '|' << endl;
				break;
			case 6:
				std::cout << left << "| "; std::cout.width(N - 1); std::cout << _Student.GetAccountBookNumber();  std::cout << '|' << endl;
				break;
			case 7:
				std::cout << left << "| "; std::cout.width(N - 1); std::cout << (_Student.GetSex() ? "Мужчина" : "Женщина");  std::cout << '|' << endl;
				break;
			default:
				std::cout << left << "| "; std::cout.width(N - 1); std::cout << " ";  std::cout << '|' << endl;
			}
		}
		DrawDoubleLine();
	}

	void Run(List<StudentClass>& _Students, List<string>& _Subjects) {

		while (Menu != -1) {
			switch (Menu) {
			case 0:
				menuLen = lenOfStartMenu;
				DrawMenu();
				break;
			case 1: case 2:
				menuLen = _Students.Len() + 1;
				DrawMenu(_Students);
				break;
			case 3:
				menuLen = lenOfRedMenu;
				DrawMenu(_Students.Get(studentChoice));
				break;
			case 4:
				menuLen = lenOfSessionMenu;
				DrawMenu();
				break;
			}
			
			if (Menu != -1) {
				action = _getch();
				if (action == DOWN) Choice = (Choice + 1) % menuLen;
				if (action == UP) Choice = (Choice - 1 < 0) ? menuLen - 1 : Choice - 1;
				if (action == ENTER) {
					switch (Menu) {
					case 0:
						switch (Choice) {
						case 0:
							Menu = 1;
							break;
						case 1:
							AddStudent(_Students);
							WriteToFile(_Students);
							Menu = 0;
							break;
						case 2:
							Menu = 2;
							break;
						case 4:
							WriteToFile(_Students);
							WriteSubjToFile(_Subjects);
							Menu = -1;
							break;
						}
						break;
					case 1:
						if (Choice == menuLen - 1) {
							Menu = 0;
						} else {
							studentChoice = Choice;
							Menu = 3;
						}
						break;
					case 2:
						if (Choice != menuLen - 1) {
							_Students.Delete(Choice);
						}
						Menu = 0;

						break;
					case 3:
						edStudent = _Students.Get(studentChoice);
						switch (Choice) {
						case 0:
							AddFirstName(&edStudent);
							AddSecondName(&edStudent);
							AddSurName(&edStudent);
							break;
						case 1:
							AddBirthDate(&edStudent);
							break;
						case 2:
							AddAdmissionYear(&edStudent);
							break;
						case 3:
							AddFaculty(&edStudent);
							break;
						case 4:
							AddDepartment(&edStudent);
							break;
						case 5:
							AddGroup(&edStudent);
							break;
						case 6:
							AddAccountBookNumber(&edStudent);
							break;
						case 7:
							ChooseSex(&edStudent);
							break;
						case 8:
							Menu = 4;
							break;
						case 9:
							Menu = 1;
							break;
						}
						_Students.Edit(edStudent, studentChoice);
						WriteToFile(_Students);
						break;
					case 4:
						switch (Choice) {
						case 0:
							AddSubject(_Subjects);
							break;
						case 1: case 2: case 3: case 4: case 5: case 6:case 7: case 8:case 9:
							sessionChoice = Choice - 1;
							Menu = 5;
							break;
						case 10:
							Menu = 3;
							break;
						}
					}
					Choice = 0;
					}
				if (action == ESCAPE) {
					WriteToFile(_Students);
					WriteSubjToFile(_Subjects);
					break;
				}
				}
			} 
			
		}
	
};
