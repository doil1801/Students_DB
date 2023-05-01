#include "StudentClass.h"
#include <windows.h>
#include <conio.h>




int NameCheck(std::string _nameString) {
	for (int i = 0; i < _nameString.length(); i++) {
		if (_nameString[i] == ' ') return 1;																					  //проверка на пробелы
		if (((_nameString[i] >= 65) && (_nameString[i] <= 90)) || ((_nameString[i] >= 97) && (_nameString[i] <= 122))) return 2;  //проверка на иностранные символы
		if ((_nameString[i] >= 48) && (_nameString[i] <= 57)) return 3;														  //проверка на числа 
		if (!((_nameString[i] >= -64) && (_nameString[i] <= -1) || (_nameString[i] != -88) || (_nameString[i] <= -72))) return 4; //проверка на все остальное
	}
	return 0;
}

bool UniqueSubjectCheck(List<std::string>& _subjectNames, std::string _subject) {
	for (int i = 0; i < _subjectNames.Len(); i++) {
		if (_subjectNames[i] == _subject) return false;
	}
	return true;
}

void AddFirstName(StudentClass* _student) {
	std::string s;
	system("cls");

	while (true) {
		std::cout << "Введите фамилию студента:" << std::endl;
		getline(std::cin, s);
		system("cls");
		switch (_student->SetFirstName(s)) {
		case 0:
			return;
		case 1:
			std::cout << "Ошибка. Введененое значение не должно содержать пробелов" << std::endl;
			break;
		case 2:
			std::cout << "Ошибка. Введененое значение не должно содержать иностранных букв" << std::endl;
			break;
		case 3:
			std::cout << "Ошибка. Введененое значение не должно содержать цифр" << std::endl;
			break;
		case 4:
			std::cout << "Ошибка. Введененое значение не должно содержать спец.символов" << std::endl;
			break;
		}
	}
}

void AddSecondName(StudentClass* _student) {
	std::string s;
	system("cls");

	while (true) {
		std::cout << "Введите имя студента:" << std::endl;
		getline(std::cin, s);
		system("cls");
		switch (_student->SetSecondName(s)) {
		case 0:
			return;
		case 1:
			std::cout << "Ошибка. Введененое значение не должно содержать пробелов" << std::endl;
			break;
		case 2:
			std::cout << "Ошибка. Введененое значение не должно содержать иностранных букв" << std::endl;
			break;
		case 3:
			std::cout << "Ошибка. Введененое значение не должно содержать цифр" << std::endl;
			break;
		case 4:
			std::cout << "Ошибка. Введененое значение не должно содержать спец.символов" << std::endl;
			break;
		}
		
	}
}

void AddSurName(StudentClass* _student) {
	std::string s;
	system("cls");

	while (true) {
		std::cout << "Введите отчество студента:" << std::endl;
		getline(std::cin, s);
		system("cls");
		switch (_student->SetSurName(s)) {
		case 0: return;
		case 1:
			std::cout << "Ошибка. Введененое значение не должно содержать пробелов" << std::endl;
			break;
		case 2:
			std::cout << "Ошибка. Введененое значение не должно содержать иностранных букв" << std::endl;
			break;
		case 3:
			std::cout << "Ошибка. Введененое значение не должно содержать цифр" << std::endl;
			break;
		case 4:
			std::cout << "Ошибка. Введененое значение не должно содержать спец.символов" << std::endl;
			break;
		}
	}
}

void AddBirthDate(StudentClass* _student) {
	std::string s;
	system("cls");

	while (true) {
		std::cout << "Введите дату рождения в формате дд.мм.гггг:" << std::endl;
		getline(std::cin, s);
		system("cls");
		if (_student->SetBirthDate(s)) break;
		else {
			std::cout << "Ошибка ввода даты" << std::endl;
		}
	}
}

void AddAdmissionYear(StudentClass* _student) {
	std::string s;
	system("cls");

	while (true) {
		std::cout << "Введите год поступления:" << std::endl;
		getline(std::cin, s);
		system("cls");
		switch (_student->SetAdmissionYear(s)) {
		case 0:
			return;
		case 1:
			std::cout << "Ошибка. Введененое значение должно содержать только цифры" << std::endl;
			break;
		case 2:
			std::cout << "Ошибка. Введенное значение некорректно" << std::endl;
			break;
			
		}
	}
}

void AddFaculty(StudentClass* _student) {
	std::string s;
	system("cls");

	while (true) {
		std::cout << "Введите факультет:" << std::endl;
		getline(std::cin, s);
		system("cls");
		switch (_student->SetFaculty(s)) {
		case 0:
			return;
		case 1:
			std::cout << "Ошибка. Введененое значение не должно содержать пробелов" << std::endl;
			break;
		case 2:
			std::cout << "Ошибка. Введененое значение не должно содержать иностранных букв" << std::endl;
			break;
		case 3:
			std::cout << "Ошибка. Введененое значение не должно содержать цифр" << std::endl;
			break;
		case 4:
			std::cout << "Ошибка. Введененое значение не должно содержать спец.символов" << std::endl;
			break;
		}
	}
}

void AddDepartment(StudentClass* _student) {
	std::string s;
	system("cls");

	while (true) {
		std::cout << "Введите кафедру в формате АА-0 или АА-00:" << std::endl;
		getline(std::cin, s);
		system("cls");
		if (_student->SetDepartment(s)) break;
		else {
			std::cout << "Ошибка. Введененое значение не соответствует формату" << std::endl;
		}
	}
}

void AddGroup(StudentClass* _student) {
	std::string s;
	system("cls");

	while (true) {
		std::cout << "Введите группу в формате АААА-00-00:" << std::endl;
		getline(std::cin, s);
		system("cls");
		if (_student->SetGroup(s)) break;
		else {
			std::cout << "Ошибка. Введененое значение не соответствует формату" << std::endl;
		}
	}
}

void AddAccountBookNumber(StudentClass* _student) {
	std::string s;
	system("cls");

	while (true) {
		std::cout << "Введите номер студенческого билета в формате 00А0000:" << std::endl;
		getline(std::cin, s);
		system("cls");
		if (_student->SetAccountBookNumber(s)) break;
		else {
			std::cout << "Ошибка. Введененое значение не соответствует формату" << std::endl;
		}
	}
}

void ChooseSex(StudentClass* _student) {
	HANDLE cs = GetStdHandle(STD_OUTPUT_HANDLE);
	int Choice = 0;
	char action;
	std::string fieldsOfMenu[2] = { "Женский", "Мужской" };

	system("cls");
	while (true) {
		std::cout << "Выберите пол:" << std::endl;
		for (int i = 0; i < 2; i++) {
			if (i == Choice) {
				SetConsoleTextAttribute(cs, FOREGROUND_GREEN); std::cout << "*" + fieldsOfMenu[i] << std::endl; SetConsoleTextAttribute(cs, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
			else {
				std::cout << fieldsOfMenu[i] << std::endl;
			}
		}
		action = _getch();
		system("cls");
		if (action == DOWN) Choice = (Choice + 1) % 2;
		if (action == UP) Choice = (Choice - 1 < 0) ? 2 - 1 : Choice - 1;
		if (action == ENTER) {
			_student->SetSex(Choice);
			break;
		}
	}
}

void AddStudent(List<StudentClass>& _students) {
	system("cls");

	StudentClass student;

	AddFirstName(&student);

	AddSecondName(&student);

	AddSurName(&student);

	AddBirthDate(&student);

	AddAdmissionYear(&student);

	AddFaculty(&student);

	AddDepartment(&student);

	AddGroup(&student);

	AddAccountBookNumber(&student);

	ChooseSex(&student);

	_students.Append(student);
}

void AddSubject(List<std::string>& _subjects) {
	std::string s;
	system("cls");

	while (true) {
		std::cout << "Введите название нового предмета:" << std::endl;
		getline(std::cin, s);
		system("cls");
		switch (NameCheck(s)){
		case 0: case 1:
			if (UniqueSubjectCheck(_subjects, s)) {
				_subjects.Append(s);
				return;
			} else {
				std::cout << "Ошибка. Введенное значение не уникально" << std::endl;
			}
			break;
		case 2:
			std::cout << "Ошибка. Введенное значение не должно содержать иностранных букв" << std::endl;
			break;
		case 3:
			std::cout << "Ошибка. Введенное значение не должно содержать цифр" << std::endl;
			break;
		case 4:
			std::cout << "Ошибка. Введенное значение не должно содержать спец.символов" << std::endl;
			break;
		}
	}
}

bool IsSubjectInSession (StudentClass* student,  std::string _subject, int _semester) {
	for (int i = 0; i < 10; i++) {
		if (student->GetNameMark(_semester, i) == _subject) return true;
	}
	return false;
}

void AddSessionSubject(StudentClass* student, List<std::string>& _subjectNames, int _semester) {
	HANDLE cs = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice = 0;
	int numberOfSubject = 0;
	char action;
	std::string exit = "Выход";
	List<std::string> _NewSubjects;

	system("cls");
	for (int i = 0; i < _subjectNames.Len(); i++) {
		if (!(IsSubjectInSession(student, _subjectNames[i], _semester))) _NewSubjects.Append(_subjectNames[i]);
	}

	if (_NewSubjects.Len() == 0) {
		std::cout << "Все предметы уже были добавлены. Нажмите любую клавишу для продолжения.";
		_getch();
		return;
	}

	if (student->GetNumberOfMarks(_semester) == 10) {
		std::cout << "Введено максимальное количество предметов. Нажмите любую клавишу для продолжения.";
		_getch();
		return;
	}

	while (true) {
		std::cout << "Выберите предмет:" << std::endl;
		for (int i = 0; i < _NewSubjects.Len(); i++) {
			if (i == choice) {
				SetConsoleTextAttribute(cs, FOREGROUND_GREEN); std::cout << "*" + _NewSubjects[i] << std::endl; SetConsoleTextAttribute(cs, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
			else {
				std::cout << _NewSubjects[i] << std::endl;
			}
		}

		action = _getch();
		system("cls");
		if (action == DOWN) choice = (choice + 1) % _NewSubjects.Len();
		if (action == UP) choice = (choice - 1 < 0) ? _NewSubjects.Len() - 1 : choice - 1;
		if (action == ENTER) {
			numberOfSubject = student->AddNameMark(_semester, _NewSubjects[choice]);
			AddMark(student, _semester, numberOfSubject);
			break;
		}
	}
	
}

void AddMark(StudentClass* student, int _semester, int _numberOfMark) {
	HANDLE cs = GetStdHandle(STD_OUTPUT_HANDLE);
	int Choice = 0;
	char action;
	const std::string fieldsOfMenu[6] = { "Незачет", "Зачет", "2 - Неудовлетворительно", "3 - Удовлетворительно", "4 - Хорошо", "5 - Отлично" };
	const int lenOfMenu = 6;

	system("cls");
	while (true) {
		std::cout << "Выберите оценку:" << std::endl;
		for (int i = 0; i < lenOfMenu; i++) {
			if (i == Choice) {
				SetConsoleTextAttribute(cs, FOREGROUND_GREEN); std::cout << "*" + fieldsOfMenu[i] << std::endl; SetConsoleTextAttribute(cs, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
			else {
				std::cout << fieldsOfMenu[i] << std::endl;
			}
		}
		action = _getch();
		system("cls");
		if (action == DOWN) Choice = (Choice + 1) % lenOfMenu;
		if (action == UP) Choice = (Choice - 1 < 0) ? lenOfMenu - 1 : Choice - 1;
		if (action == ENTER) {
			student->SetValueMark(_semester, _numberOfMark, Choice);
			break;
		}
	}
}

void DeleteSubject(List<std::string>& _subjects, int _numberOfSubject, List<StudentClass>& _students) {
	std::string subjectName = _subjects[_numberOfSubject];

	system("cls");

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice = 0;
	std::string fieldsOfMenu[2] = { "Да", "Нет" };

	while (true) {
		std::cout << "Вы уверены, что хотите удалить данный предмет?" << std::endl << "Данный предмет удалится у следующих студентов: " << std::endl;
		for (int i = 0; i < _students.Len(); i++) {
			bool flag = false;
			bool semesters[9] = { false, false, false, false, false, false, false, false, false };

			for (int j = 0; j < 9; j++) {
				for (int k = 0; k < 10; k++) {
					if (_students[i].GetNameMark(j, k) == subjectName) {
						flag = true;
						semesters[j] = true;
						break;
					}
				}
			}
			if (flag) {
				std::cout << _students[i].GetFirstName() << ' ' << _students[i].GetSecondName() << ' ' << _students[i].GetSurName() << " в семестрах: ";
				for (int j = 0; j < 9; j++) {
					if (semesters[j]) std::cout << j + 1 << ' ';
				}
				std::cout << std::endl;
			}
			
		}

		for (int i = 0; i < 2; i++) {
			if (i == choice) {
				SetConsoleTextAttribute(console, FOREGROUND_GREEN); std::cout << "*" + fieldsOfMenu[i] << std::endl; SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
			else {
				std::cout << fieldsOfMenu[i] << std::endl;
			}
		}

		char action = _getch();
		system("cls");
		if (action == DOWN) choice = (choice + 1) % 2;
		if (action == UP) choice = (choice - 1 < 0) ? 2 - 1 : choice - 1;
		if (action == ENTER) {
			if (choice == 1) return;
			break;
		}
	}

	_subjects.Delete(_numberOfSubject);

	for (int i = 0; i < _students.Len(); i++) {
		StudentClass editStudent = _students[i];

		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 10; k++) {
				if (editStudent.GetNameMark(j, k) == subjectName) {
					editStudent.DeleteMark(j, k);
				}
			}
		}

		_students.Edit(editStudent, i);
	}
}

void SortByAverageMark(List<StudentClass>& _students) {
	for (int i = 0; i < _students.Len() - 1; i++) {
		for (int j = 0; j < _students.Len() - i - 1; j++) {
			if (_students[j].GetAverageMark() < _students[j+1].GetAverageMark()) {
				_students.Swap(j, j + 1);
			}
		}
	}
}

