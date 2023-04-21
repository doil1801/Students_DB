#pragma once
#include "List.h"
#include <windows.h>
#include "StudentClass.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "FileWork.h"

const int n = 66;
#define DOWN 80
#define UP 72
#define ENTER 13
#define ESCAPE 27


class ConsoleClass {
private:
	HANDLE cs = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string StartMenu = "Главное меню";
	const int lenOfStartMenu = 6;
	std::string fieldsOfStartMenu[6] = {
		"Посмотреть список студентов (удалить или изменить данные)",
		"Добавить данные о новом студенте",
		"Удалить данные о студенте",
		"Сохранить БД",
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
		"Добавить(изменить) оценки",
		"Выход"
	};

	void DrawLine() const{
		std::cout.width(n); std::cout.fill('-'); std::cout << "-" << endl;
		std::cout.fill(' ');
	}

	void DrawDoubleLine() const {
		std::cout.width(n); std::cout.fill('-'); std::cout << "-"; std::cout.width(n); std::cout.fill('-'); std::cout << "     -";
		std::cout.fill(' ');
	}

	int leng = 0;
	std::string* fieldsOfMenu = NULL;
	std::string UpNote = "";
	int Menu = 0;
	int Choice = 0;
	int action = 0;
	int menuLen = 6;
public:
	ConsoleClass() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
	}
	void DrawMenu(){
		system("cls");
		if (Menu == 0) {
			leng = lenOfStartMenu;
			fieldsOfMenu = fieldsOfStartMenu;
			UpNote = StartMenu;
		}
		else if (Menu == 1) {
			leng = lenOfRedMenu;
			fieldsOfMenu = fieldsOfRedMenu;
			UpNote = RedMenu;
		}
		
		DrawLine();
		std::cout.width(n-1); std::cout << left << "|" + UpNote; std::cout << '|' << endl;
		DrawLine();
		for (int i = 0; i < leng; i++) {
			if (i == Choice) {
				std::cout << left << "|"; std::cout.width(n - 2); SetConsoleTextAttribute(cs, FOREGROUND_GREEN); std::cout << "*" + fieldsOfMenu[i]; SetConsoleTextAttribute(cs, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); std::cout << '|' << endl;
			} else {
				std::cout.width(n - 1); std::cout << left << "| " + fieldsOfMenu[i]; std::cout << '|' << endl;
			}
		}
		DrawLine();
	}

	void DrawMenu(List<StudentClass>& _Students) {
		system("cls");
		leng = _Students.Len();
		UpNote = MenuOfStudents;


		DrawLine();
		std::cout.width(n - 1); std::cout << left << "|" + UpNote; std::cout << '|' << endl;
		DrawLine();

		for (int i = 0; i < leng; i++) {
			if (i == Choice) {
				std::cout << left << "|"; std::cout.width(n - 2); SetConsoleTextAttribute(cs, FOREGROUND_GREEN); std::cout << "*" + _Students.Get(i).GetFirstName() + ' ' + _Students.Get(i).GetSecondName() + ' ' + _Students.Get(i).GetSurName(); SetConsoleTextAttribute(cs, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); std::cout << '|' << endl;
			}
			else {
				std::cout.width(n - 1); std::cout << left << "| " + _Students.Get(i).GetFirstName() + ' ' + _Students.Get(i).GetSecondName() + ' ' + _Students.Get(i).GetSurName(); std::cout << '|' << endl;
			}
		}
		if (Choice == leng) {
			std::cout << left << "|"; std::cout.width(n - 2); SetConsoleTextAttribute(cs, FOREGROUND_GREEN);  std::cout << left << "*" + fieldsOfStartMenu[5]; SetConsoleTextAttribute(cs, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); std::cout << '|' << endl;
		} else {
			std::cout.width(n - 1); std::cout << left << "| " + fieldsOfStartMenu[5]; std::cout << '|' << endl;
		}
		DrawLine();
	}

	void DrawMenu(StudentClass _Student) {
		system("cls");
		fieldsOfMenu = fieldsOfRedMenu;
		leng = lenOfRedMenu;
		UpNote = RedMenu;


		DrawLine();
		std::cout.width(n - 1); std::cout << left << "|" + UpNote; std::cout << '|' << endl;
		DrawDoubleLine();
		for (int i = 0; i < leng; i++) {
			if (i == Choice) {
				std::cout << left << "|"; std::cout.width(n - 2); SetConsoleTextAttribute(cs, FOREGROUND_GREEN); std::cout << "*" + fieldsOfMenu[i]; SetConsoleTextAttribute(cs, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); std::cout << "|     ";
				switch (Choice) {
				case 0:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << _Student.GetFirstName() + ' ' + _Student.GetSecondName() + ' ' + _Student.GetSurName();  std::cout << '|' << endl;
					break;
				case 1:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << to_string(_Student.GetBirthDate().GetDay()) + '.' + to_string(_Student.GetBirthDate().GetMonth()) + '.' + to_string(_Student.GetBirthDate().GetYear());  std::cout << '|' << endl;
					break;
				case 2:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << _Student.GetAdmissionYear() ;  std::cout << '|' << endl;
					break;
				case 3:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << _Student.GetFuculty();  std::cout << '|' << endl;
					break;
				case 4:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << _Student.GetDepartment();  std::cout << '|' << endl;
					break;
				case 5:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << _Student.GetGroup();  std::cout << '|' << endl;
					break;
				case 6:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << _Student.GetAccountBookNumber();  std::cout << '|' << endl;
					break;
				case 7:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << _Student.GetSex() ? "Мужчина" : "Женщина";  std::cout << '|' << endl;
					break;
				default:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << " ";  std::cout << '|' << endl;
				}
			}
			else {
				std::cout.width(n - 1); std::cout << left << "| " + fieldsOfMenu[i]; std::cout << "|     " << endl;
				switch (Choice) {
				case 0:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << _Student.GetFirstName() + ' ' + _Student.GetSecondName() + ' ' + _Student.GetSurName();  std::cout << '|' << endl;
					break;
				case 1:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << to_string(_Student.GetBirthDate().GetDay()) + '.' + to_string(_Student.GetBirthDate().GetMonth()) + '.' + to_string(_Student.GetBirthDate().GetYear());  std::cout << '|' << endl;
					break;
				case 2:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << _Student.GetAdmissionYear();  std::cout << '|' << endl;
					break;
				case 3:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << _Student.GetFuculty();  std::cout << '|' << endl;
					break;
				case 4:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << _Student.GetDepartment();  std::cout << '|' << endl;
					break;
				case 5:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << _Student.GetGroup();  std::cout << '|' << endl;
					break;
				case 6:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << _Student.GetAccountBookNumber();  std::cout << '|' << endl;
					break;
				case 7:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << _Student.GetSex() ? "Мужчина" : "Женщина";  std::cout << '|' << endl;
					break;
				default:
					std::cout << left << "| "; std::cout.width(n - 1); std::cout << " ";  std::cout << '|' << endl;
				}
			}
		}
		DrawDoubleLine();
	}

	void Run(List<StudentClass>& _Students, List<string>& _Subjects) {

		while (true) {
			switch (Menu) {
			case 0:
				menuLen = 6;
				DrawMenu();
				break;
			case 1: case 2:
				menuLen = _Students.Len() + 1;
				DrawMenu(_Students);
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
							Menu = 0;
							break;
						case 2:
							Menu = 2;
							break;
						case 5:
							Menu = -1;
							break;
						}
					case 1:
						if (Choice == menuLen - 1) {
							Menu = 0;
						} else
						{
							
						}
						break;
					case 2:
						if (Choice != menuLen - 1) {
							_Students.Delete(Choice);
						}
						Menu = 0;

						break;

					}
					Choice = 0;
					}
				if (action == ESCAPE) break;
				}
			} 
			
		}
	
};
