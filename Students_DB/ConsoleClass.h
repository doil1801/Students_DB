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
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	int length = 0;
	std::string* fieldsOfMenu = nullptr;
	std::string upNote;
	int menu = 0;
	int choice = 0;
	int action = 0;
	int menuLength = 6;
	int studentChoice = 0;
	int sessionChoice = 0;
	StudentClass editStudent;

	std::string exit = "Выход";

	std::string startMenu = "Главное меню";
	const int lenOfStartMenu = 5;
	std::string fieldsOfStartMenu[5] = {
		"Посмотреть список студентов (изменить данные)",
		"Добавить нового студента",
		"Удалить запись студента",
		"Выполнить вариант 66",
		exit
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

	std::string menuOfStudents = "Выбор студента";

	std::string subjectDeleteMenu = "Выберите предмет для удаления";

	const int lenOfRedMenu = 10;
	std::string redactionMenu = "Меню редактирования студентов";
	std::string fieldsOfRedactionMenu[10] = {
		"Добавить(изменить) имя",
		"Добавить(изменить) дату рождения",
		"Добавить(изменить) год поступления",
		"Добавить(изменить) институт",
		"Добавить(изменить) кафедру",
		"Добавить(изменить) группу",
		"Добавить(изменить) номер зачетной книжки",
		"Добавить(изменить) пол",
		"Посмотреть(изменить/добавить) оценки",
		exit
	};

	const int lenOfSessionMenu = 12;
	std::string sessionMenu = "Выбор сессии";
	std::string fieldsOfSessionMenu[12] = {
		"Добавить предмет",
		"Удалить предмет",
		"Добавить/изменить сессию 1",
		"Добавить/изменить сессию 2",
		"Добавить/изменить сессию 3",
		"Добавить/изменить сессию 4",
		"Добавить/изменить сессию 5",
		"Добавить/изменить сессию 6",
		"Добавить/изменить сессию 7",
		"Добавить/изменить сессию 8",
		"Добавить/изменить сессию 9",
		exit
	};

	

	void DrawLine(int length) {
		std::cout.width(length); std::cout.fill('-'); std::cout << "-" << std::endl;
		std::cout.fill(' ');
	}

	void DrawDoubleLine(int length) {
		std::cout.width(length); std::cout.fill('-'); std::cout << "-"; std::cout << "     "; std::cout.width(length +2); std::cout.fill('-'); std::cout << "-" << std::endl;
		std::cout.fill(' ');
	}

	void DrawMenu() {
		system("cls");
		switch (menu) {
		case 0:
			length = lenOfStartMenu;
			fieldsOfMenu = fieldsOfStartMenu;
			upNote = startMenu;
			break;
		case 1:
			length = lenOfRedMenu;
			fieldsOfMenu = fieldsOfRedactionMenu;
			upNote = redactionMenu;
			break;
		case 4:
			length = lenOfSessionMenu;
			fieldsOfMenu = fieldsOfSessionMenu;
			upNote = sessionMenu;
			break;
		}


		DrawLine(N);
		std::cout.width(N - 1); std::cout << std::left << "|" + upNote; std::cout << '|' << std::endl;
		DrawLine(N);
		for (int i = 0; i < length; i++) {
			if (i == choice) {
				std::cout << std::left << "|";
				std::cout.width(N - 2);
				SetConsoleTextAttribute(console, FOREGROUND_GREEN);
				std::cout << "*" + fieldsOfMenu[i]; SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				std::cout << '|' << std::endl;
			}
			else {
				std::cout.width(N - 1);
				std::cout << std::left << "| " + fieldsOfMenu[i];
				std::cout << '|' << std::endl;
			}
		}
		DrawLine(N);
	}

	void DrawMenu(List<StudentClass>& _students) {
		system("cls");
		length = _students.Len();
		upNote = menuOfStudents;


		DrawLine(N);
		std::cout.width(N - 1); std::cout << std::left << "|" + upNote; std::cout << '|' << std::endl;
		DrawLine(N);

		for (int i = 0; i < length; i++) {
			if (i == choice) {
				std::cout << std::left << "|";
				std::cout.width(N - 2);
				SetConsoleTextAttribute(console, FOREGROUND_GREEN);
				std::cout << "*" + _students[i].GetFirstName() + ' ' + _students[i].GetSecondName() + ' ' + _students[i].GetSurName();
				SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				std::cout << '|' << std::endl;
			}
			else {
				std::cout.width(N - 1);
				std::cout << std::left << "| " + _students[i].GetFirstName() + ' ' + _students[i].GetSecondName() + ' ' + _students[i].GetSurName();
				std::cout << '|' << std::endl;
			}
		}
		if (choice == length) {
			std::cout << std::left << "|";
			std::cout.width(N - 2);
			SetConsoleTextAttribute(console, FOREGROUND_GREEN);
			std::cout << std::left << "*" + exit;
			SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			std::cout << '|' << std::endl;
		}
		else {
			std::cout.width(N - 1);
			std::cout << std::left << "| " + exit;
			std::cout << '|' << std::endl;
		}
		DrawLine(N);
	}

	void DrawMenu(StudentClass _student) {
		system("cls");
		fieldsOfMenu = fieldsOfRedactionMenu;
		length = lenOfRedMenu;
		upNote = redactionMenu;


		DrawLine(N);
		std::cout.width(N - 1); std::cout << std::left << "|" + upNote; std::cout << '|' << std::endl;
		DrawDoubleLine(N);
		for (int i = 0; i < length; i++) {
			if (i == choice) {
				std::cout << std::left << "|"; std::cout.width(N - 2); SetConsoleTextAttribute(console, FOREGROUND_GREEN); std::cout << "*" + fieldsOfMenu[i]; SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); std::cout << "|     ";
				switch (i) {
				case 0:
					std::cout << std::left << "| "; std::cout.width(N - 1);  SetConsoleTextAttribute(console, FOREGROUND_GREEN); std::cout << _student.GetFirstName() + ' ' + _student.GetSecondName() + ' ' + _student.GetSurName(); SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);  std::cout << '|' << std::endl;
					break;
				case 1:
					std::cout << std::left << "| "; std::cout.width(N - 1);  SetConsoleTextAttribute(console, FOREGROUND_GREEN); std::cout << std::to_string(_student.GetBirthDate().GetDay()) + '.' + std::to_string(_student.GetBirthDate().GetMonth()) + '.' + std::to_string(_student.GetBirthDate().GetYear()); SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);  std::cout << '|' << std::endl;
					break;
				case 2:
					std::cout << std::left << "| "; std::cout.width(N - 1);  SetConsoleTextAttribute(console, FOREGROUND_GREEN); std::cout << _student.GetAdmissionYear(); SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);  std::cout << '|' << std::endl;
					break;
				case 3:
					std::cout << std::left << "| "; std::cout.width(N - 1);  SetConsoleTextAttribute(console, FOREGROUND_GREEN); std::cout << _student.GetFaculty(); SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);  std::cout << '|' << std::endl;
					break; 
				case 4:
					std::cout << std::left << "| "; std::cout.width(N - 1);  SetConsoleTextAttribute(console, FOREGROUND_GREEN); std::cout << _student.GetDepartment(); SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);  std::cout << '|' << std::endl;
					break;
				case 5:
					std::cout << std::left << "| "; std::cout.width(N - 1);  SetConsoleTextAttribute(console, FOREGROUND_GREEN); std::cout << _student.GetGroup(); SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);  std::cout << '|' << std::endl;
					break;
				case 6:
					std::cout << std::left << "| "; std::cout.width(N - 1);  SetConsoleTextAttribute(console, FOREGROUND_GREEN); std::cout << _student.GetAccountBookNumber(); SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);  std::cout << '|' << std::endl;
					break;
				case 7:
					std::cout << std::left << "| "; std::cout.width(N - 1);  SetConsoleTextAttribute(console, FOREGROUND_GREEN); std::cout << (_student.GetSex() ? "М" : "Ж"); SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);  std::cout << '|' << std::endl;
					break;
				case 8:
					std::cout << std::left << "| "; std::cout.width(N - 1);  SetConsoleTextAttribute(console, FOREGROUND_GREEN); std::cout.precision(2); std::cout << std::fixed << _student.GetAverageMark(); SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);  std::cout << "|" << std::endl;
					break;
				default:
					std::cout << std::left << "| "; std::cout.width(N - 1);  std::cout << " ";  std::cout << '|' << std::endl;
					break;
				}
			}
			else {
				std::cout.width(N - 1); std::cout << std::left << "| " + fieldsOfMenu[i]; std::cout << "|     ";
				switch (i) {
				case 0:
					std::cout << std::left << "| "; std::cout.width(N - 1); std::cout << _student.GetFirstName() + ' ' + _student.GetSecondName() + ' ' + _student.GetSurName();  std::cout << '|' << std::endl;
					break;
				case 1:
					std::cout << std::left << "| "; std::cout.width(N - 1); std::cout << std::to_string(_student.GetBirthDate().GetDay()) + '.' + std::to_string(_student.GetBirthDate().GetMonth()) + '.' + std::to_string(_student.GetBirthDate().GetYear());  std::cout << '|' << std::endl;
					break;
				case 2:
					std::cout << std::left << "| "; std::cout.width(N - 1); std::cout << _student.GetAdmissionYear();  std::cout << '|' << std::endl;
					break;
				case 3:
					std::cout << std::left << "| "; std::cout.width(N - 1); std::cout << _student.GetFaculty();  std::cout << '|' << std::endl;
					break;
				case 4:
					std::cout << std::left << "| "; std::cout.width(N - 1); std::cout << _student.GetDepartment();  std::cout << '|' << std::endl;
					break;
				case 5:
					std::cout << std::left << "| "; std::cout.width(N - 1); std::cout << _student.GetGroup();  std::cout << '|' << std::endl;
					break;
				case 6:
					std::cout << std::left << "| "; std::cout.width(N - 1); std::cout << _student.GetAccountBookNumber();  std::cout << '|' << std::endl;
					break;
				case 7:
					std::cout << std::left << "| "; std::cout.width(N - 1); std::cout << (_student.GetSex() ? "М" : "Ж");  std::cout << '|' << std::endl;
					break;
				case 8:
					std::cout << std::left << "| "; std::cout.width(N - 1); std::cout.precision(2); std::cout << std::fixed << _student.GetAverageMark();  std::cout << "|" << std::endl;
					break;
				default:
					std::cout << std::left << "| "; std::cout.width(N - 1); std::cout << " ";  std::cout << '|' << std::endl;
					break;
				}
			}
			
		}
		DrawDoubleLine(N);
	}

	void DrawMenu(List<std::string>& _subjects) {
		system("cls");
		length = _subjects.Len();
		upNote = subjectDeleteMenu;


		DrawLine(N);
		std::cout.width(N - 1); std::cout << std::left << "|" + upNote; std::cout << '|' << std::endl;
		DrawLine(N);

		for (int i = 0; i < length; i++) {
			if (i == choice) {
				std::cout << std::left << "|";
				std::cout.width(N - 2);
				SetConsoleTextAttribute(console, FOREGROUND_GREEN);
				std::cout << "*" + _subjects[i];
				SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				std::cout << '|' << std::endl;
			}
			else {
				std::cout.width(N - 1);
				std::cout << std::left << "| " + _subjects[i];
				std::cout << '|' << std::endl;
			}
		}
		if (choice == length) {
			std::cout << std::left << "|";
			std::cout.width(N - 2);
			SetConsoleTextAttribute(console, FOREGROUND_GREEN);
			std::cout << std::left << "*" + exit;
			SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			std::cout << '|' << std::endl;
		}
		else {
			std::cout.width(N - 1);
			std::cout << std::left << "| " + exit;
			std::cout << '|' << std::endl;
		}
		DrawLine(N);
	}

	void DrawSession(StudentClass _Student) {
		system("cls");
		length = _Student.GetNumberOfMarks(sessionChoice);

		DrawLine(N);
		std::cout.width(N - 1); std::cout << std::left << "|" + upNote; std::cout << '|' << std::endl;
		DrawLine(N);

		upNote = "Результаты сессии №" + std::to_string(sessionChoice + 1);
		if (choice == 0) {
			std::cout << std::left << "|"; std::cout.width(N - 2);
			SetConsoleTextAttribute(console, FOREGROUND_GREEN);
			std::cout << std::left << "*Добавить новую оценку";
			SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			std::cout << '|' << std::endl;
		}
		else {
			std::cout.width(N - 1);
			std::cout << std::left << "| Добавить новую оценку";
			std::cout << '|' << std::endl;
		}

		for (int i = 1; i < length + 1; i++) {
			int buff = _Student.GetValueMark(sessionChoice, i - 1);
			if (i == choice) {

				std::cout << std::left << "|";
				std::cout.width(N - 2);
				SetConsoleTextAttribute(console, FOREGROUND_GREEN);
				std::cout << "*" + _Student.GetNameMark(sessionChoice, i - 1) + ": " + ((buff >= 2) ? std::to_string(buff) : ((buff == 1) ? "Зачет" : "Незачет"));
				SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				std::cout << '|' << std::endl;
			}
			else {
				std::cout.width(N - 1);
				std::cout << std::left << "| " + _Student.GetNameMark(sessionChoice, i - 1) + ": " + ((buff >= 2) ? std::to_string(buff) : ((buff == 1) ? "Зачет" : "Незачет"));
				std::cout << '|' << std::endl;
			}
		}

		if (choice == length + 1) {
			std::cout << std::left << "|";
			std::cout.width(N - 2);
			SetConsoleTextAttribute(console, FOREGROUND_GREEN);
			std::cout << std::left << "*Удалить оценку";
			SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			std::cout << '|' << std::endl;
		}
		else {
			std::cout.width(N - 1);
			std::cout << std::left << "| Удалить оценку";
			std::cout << '|' << std::endl;
		}

		if (choice == length + 2) {
			std::cout << std::left << "|";
			std::cout.width(N - 2);
			SetConsoleTextAttribute(console, FOREGROUND_GREEN);
			std::cout << std::left << "*" + exit;
			SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			std::cout << '|' << std::endl;
		}
		else {
			std::cout.width(N - 1);
			std::cout << std::left << "| " + exit;
			std::cout << '|' << std::endl;
		}
		DrawLine(N);
	}

	void DrawSessionForDelete(StudentClass _Student) {
		system("cls");
		length = _Student.GetNumberOfMarks(sessionChoice);

		DrawLine(N);
		std::cout.width(N - 1); std::cout << std::left << "|" + upNote; std::cout << '|' << std::endl;
		DrawLine(N);

		upNote = "Выберите оценку для удаления";

		for (int i = 0; i < length; i++) {
			int buff = _Student.GetValueMark(sessionChoice, i);
			if (i == choice) {

				std::cout << std::left << "|";
				std::cout.width(N - 2);
				SetConsoleTextAttribute(console, FOREGROUND_GREEN);
				std::cout << "*" + _Student.GetNameMark(sessionChoice, i) + ": " + ((buff >= 2) ? std::to_string(buff) : ((buff == 1) ? "Зачет" : "Незачет"));
				SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				std::cout << '|' << std::endl;
			}
			else {
				std::cout.width(N - 1);
				std::cout << std::left << "| " + _Student.GetNameMark(sessionChoice, i) + ": " + ((buff >= 2) ? std::to_string(buff) : ((buff == 1) ? "Зачет" : "Незачет"));
				std::cout << '|' << std::endl;
			}
		}

		if (choice == length) {
			std::cout << std::left << "|";
			std::cout.width(N - 2);
			SetConsoleTextAttribute(console, FOREGROUND_GREEN);
			std::cout << std::left << "*" + exit;
			SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			std::cout << '|' << std::endl;
		}
		else {
			std::cout.width(N - 1);
			std::cout << std::left << "| " + exit;
			std::cout << '|' << std::endl;
		}
		DrawLine(N);
	}

	void ExecuteOrder66(List<StudentClass>& _students) {
		system("cls");

		List<StudentClass> students = _students;
		SortByAverageMark(students);
		std::cout << "Успеваемость студентов: " << std::endl;

		DrawLine(119);
		std::cout.width(17);
		std::cout << std::left << "| ФИО";

		std::cout.width(14);
		std::cout << std::left << "| Год рождения";

		std::cout.width(17);
		std::cout << std::left << "| Год поступления";

		std::cout.width(10);
		std::cout << std::left << "| Институт";

		std::cout.width(9);
		std::cout << std::left << "| Кафедра";

		std::cout.width(13);
		std::cout << std::left << "| Группа";

		std::cout.width(19);
		std::cout << std::left << "| Номер зач. книжки";

		std::cout.width(5);
		std::cout << std::left << "| Пол";

		std::cout.width(14);
		std::cout << std::left << "| Средний балл";
		std::cout << '|' << std::endl;

		DrawLine(119);
		for (int i = 0; i < students.Len(); i++) {
			std::cout.width(17);
			std::cout << std::left << "| " + students[i].GetFirstName() + ' ' + students[i].GetSecondName()[0] + '.' + students[i].GetSurName()[0] + '.';

			std::cout.width(14);
			std::cout << std::left << "| " + std::to_string(students[i].GetBirthDate().GetYear());

			std::cout.width(17);
			std::cout << std::left << "| " + std::to_string(students[i].GetAdmissionYear());

			std::cout.width(10);
			std::cout << std::left << "| " + students[i].GetFaculty();

			std::cout.width(9);
			std::cout << std::left << "| " + students[i].GetDepartment();

			std::cout.width(13);
			std::cout << std::left << "| " + students[i].GetGroup();

			std::cout.width(19);
			std::cout << std::left << "| " + students[i].GetAccountBookNumber();

			std::cout.width(5);
			std::cout << std::left << (students[i].GetSex() ? "| М  |" : "| Ж  |");

			std::cout.width(9);
			std::cout << ' ';
			std::cout.precision(2);
			std::cout ;
			std::cout ;
			std::cout << std::left << std::fixed <<students[i].GetAverageMark() << "|" << std::endl;
		}
		DrawLine(119);
		std::cout << "Нажмите любую кнопку для перехода в меню.";
		_getch();
		return;
	}
public:
	ConsoleClass() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
	}

	void Run(List<StudentClass>& _students, List<std::string>& _subjects) {
		while (menu != -1) {
			switch (menu) {
			case 0:
				menuLength = lenOfStartMenu;
				DrawMenu();
				break;
			case 1: case 2:
				menuLength = _students.Len() + 1;
				DrawMenu(_students);
				break;
			case 3:
				menuLength = lenOfRedMenu;
				DrawMenu(_students[studentChoice]);
				break;
			case 4:
				menuLength = lenOfSessionMenu;
				DrawMenu();
				break;
			case 5:
				menuLength = _students[studentChoice].GetNumberOfMarks(sessionChoice) + 3;
				DrawSession(_students[studentChoice]);
				break;
			case 6:
				menuLength = _students[studentChoice].GetNumberOfMarks(sessionChoice) + 1;
				DrawSessionForDelete(_students[studentChoice]);
				break;
			case 7:
				menuLength = _subjects.Len() + 1;
				DrawMenu(_subjects);
				break;
			}
			
			if (menu != -1) {
				action = _getch();
				if (action == DOWN) choice = (choice + 1) % menuLength;
				if (action == UP) choice = (choice - 1 < 0) ? menuLength - 1 : choice - 1;
				if (action == ENTER) {
					switch (menu) {
					case 0:
						switch (choice) {
						case 0:
							menu = 1;
							break;
						case 1:
							AddStudent(_students);
							WriteToFile(_students);
							menu = 0;
							break;
						case 2:
							menu = 2;
							break;
						case 3:
							ExecuteOrder66(_students);
							break;
						case 4:
							WriteToFile(_students);
							WriteSubjToFile(_subjects);
							menu = -1;
							break;
						default:
							menu = 0; 
							break;
						}
						break;
					case 1:
						if (choice == menuLength - 1) {
							menu = 0;
						} else {
							studentChoice = choice;
							menu = 3;
						}
						break;
					case 2:
						if (choice != menuLength - 1) {
							_students.Delete(choice);
							WriteToFile(_students);
						}
						menu = 0;

						break;
					case 3:
						editStudent = _students[studentChoice];
						switch (choice) {
						case 0:
							AddFirstName(&editStudent);
							AddSecondName(&editStudent);
							AddSurName(&editStudent);
							break;
						case 1:
							AddBirthDate(&editStudent);
							break;
						case 2:
							AddAdmissionYear(&editStudent);
							break;
						case 3:
							AddFaculty(&editStudent);
							break;
						case 4:
							AddDepartment(&editStudent);
							break;
						case 5:
							AddGroup(&editStudent);
							break;
						case 6:
							AddAccountBookNumber(&editStudent);
							break;
						case 7:
							ChooseSex(&editStudent);
							break;
						case 8:
							menu = 4;
							break;
						case 9:
							menu = 1;
							break;
						default:
							menu = 0;
						}
						_students.Edit(editStudent, studentChoice);
						WriteToFile(_students);
						break;
					case 4:
						switch (choice) {
						case 0:
							AddSubject(_subjects);
							WriteSubjToFile(_subjects);
							break;
						case 1:
							menu = 7;
							break;
						case 2: case 3: case 4: case 5: case 6:case 7: case 8: case 9: case 10:
							sessionChoice = choice - 2;
							menu = 5;
							break;
						case 11:
							menu = 3;
							break;
						default:
							menu = 0;
							break;
						}
						break;
					case 5:
						editStudent = _students[studentChoice];
						if (choice == 0) {
							AddSessionSubject(&editStudent, _subjects, sessionChoice);
							_students.Edit(editStudent, studentChoice);
							WriteToFile(_students);
						} else if (choice == menuLength - 1) {
							menu = 4;
						} else if (choice == menuLength - 2) {
							menu = 6;
						} else {
							AddMark(&editStudent, sessionChoice, choice-1);
							_students.Edit(editStudent, studentChoice);
							WriteToFile(_students);
						}
						break;
					case 6:
						editStudent = _students[studentChoice];
						if (choice == menuLength - 1) {
							menu = 5;
						} else {
							editStudent.DeleteMark(sessionChoice, choice);
							_students.Edit(editStudent, studentChoice);
							WriteToFile(_students);
							menu = 5;
						}
						break;
					case 7:
						if (choice <= menuLength - 1) {
							DeleteSubject(_subjects, choice, _students);
							WriteSubjToFile(_subjects);
						} 
						menu = 4;
						break;
					}
					choice = 0;
					}
				if (action == ESCAPE) {
					WriteToFile(_students);
					WriteSubjToFile(_subjects);
					break;
				}
				}
			} 
		}
};
