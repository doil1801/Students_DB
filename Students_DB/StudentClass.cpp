#include "StudentClass.h"


int NameCheck(string namestring) {
	for (int i = 0; i < namestring.length(); i++) {
		if (namestring[i] == ' ') return 1;																					  //проверка на пробелы
		if (((namestring[i] >= 65) && (namestring[i] <= 90)) || ((namestring[i] >= 97) && (namestring[i] <= 122))) return 2;  //проверка на иностранные символы
		if ((namestring[i] >= 48) && (namestring[i] <= 57)) return 3;														  //проверка на числа 
		if (!((namestring[i] >= -64) && (namestring[i] <= -1) || (namestring[i] != -88) || (namestring[i] <= -72))) return 4; //проверка на все остальное
	}
	return 0;
}

bool UniqueSubjectCheck(List<string>& _SubjectNames, string _Subject) {
	for (int i = 0; i < _SubjectNames.Len(); i++) {
		if (_SubjectNames.Get(i) == _Subject) return false;
	}
	return true;
}

void AddFirstName(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "Введите фамилию студента:" << endl;
		getline(cin, s);
		system("cls");
		switch (newStudent->SetFirstName(s)) {
		case 0:
			return;
		case 1:
			cout << "Ошибка. Введененое значение не должно содержать пробелов" << endl;
			break;
		case 2:
			cout << "Ошибка. Введененое значение не должно содержать иностранных букв" << endl;
			break;
		case 3:
			cout << "Ошибка. Введененое значение не должно содержать цифр" << endl;
			break;
		case 4:
			cout << "Ошибка. Введененое значение не должно содержать спец.символов" << endl;
			break;
		}
	}
}

void AddSecondName(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "Введите имя студента:" << endl;
		getline(cin, s);
		system("cls");
		switch (newStudent->SetSecondName(s)) {
		case 0:
			return;
		case 1:
			cout << "Ошибка. Введененое значение не должно содержать пробелов" << endl;
			break;
		case 2:
			cout << "Ошибка. Введененое значение не должно содержать иностранных букв" << endl;
			break;
		case 3:
			cout << "Ошибка. Введененое значение не должно содержать цифр" << endl;
			break;
		case 4:
			cout << "Ошибка. Введененое значение не должно содержать спец.символов" << endl;
			break;
		}
		
	}
}

void AddSurName(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "Введите отчество студента:" << endl;
		getline(cin, s);
		system("cls");
		switch (newStudent->SetSurName(s)) {
		case 0: return;
		case 1:
			cout << "Ошибка. Введененое значение не должно содержать пробелов" << endl;
			break;
		case 2:
			cout << "Ошибка. Введененое значение не должно содержать иностранных букв" << endl;
			break;
		case 3:
			cout << "Ошибка. Введененое значение не должно содержать цифр" << endl;
			break;
		case 4:
			cout << "Ошибка. Введененое значение не должно содержать спец.символов" << endl;
			break;
		}
	}
}

void AddBirthDate(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "Введите дату рождения в формате дд.мм.гггг:" << endl;
		getline(cin, s);
		system("cls");
		if (newStudent->SetBirthDate(s)) break;
		else {
			cout << "Ошибка ввода даты" << endl;
		}
	}
}

void AddAdmissionYear(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "Введите год поступления:" << endl;
		getline(cin, s);
		system("cls");
		switch (newStudent->SetAdmissionYear(s)) {
		case 0:
			return;
		case 1:
			cout << "Ошибка. Введененое значение должно содержать только цифры" << endl;
			break;
		case 2:
			cout << "Ошибка. Введенное значение некорректно" << endl;
			break;
			
		}
	}
}

void AddFaculty(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "Введите факультет:" << endl;
		getline(cin, s);
		system("cls");
		switch (newStudent->SetFuculty(s)) {
		case 0:
			return;
		case 1:
			cout << "Ошибка. Введененое значение не должно содержать пробелов" << endl;
			break;
		case 2:
			cout << "Ошибка. Введененое значение не должно содержать иностранных букв" << endl;
			break;
		case 3:
			cout << "Ошибка. Введененое значение не должно содержать цифр" << endl;
			break;
		case 4:
			cout << "Ошибка. Введененое значение не должно содержать спец.символов" << endl;
			break;
		}
	}
}

void AddDepartment(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "Введите кафедру в формате АА-0 или АА-00:" << endl;
		getline(cin, s);
		system("cls");
		if (newStudent->SetDepartment(s)) break;
		else {
			cout << "Ошибка. Введененое значение не соответствует формату" << endl;
		}
	}
}

void AddGroup(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "Введите группу в формате АААА-00-00:" << endl;
		getline(cin, s);
		system("cls");
		if (newStudent->SetGroup(s)) break;
		else {
			cout << "Ошибка. Введененое значение не соответствует формату" << endl;
		}
	}
}

void AddAccountBookNumber(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "Введите номер студенческого билета в формате 00А0000:" << endl;
		getline(cin, s);
		system("cls");
		if (newStudent->SetAccountBookNumber(s)) break;
		else {
			cout << "Ошибка. Введененое значение не соответствует формату" << endl;
		}
	}
}

void ChooseSex(StudentClass* newStudent) {
	HANDLE cs = GetStdHandle(STD_OUTPUT_HANDLE);
	int Choice = 0;
	char action;
	string fieldsOfMenu[2] = { "Женский", "Мужской" };

	system("cls");
	while (true) {
		cout << "Выберете пол:" << endl;
		for (int i = 0; i < 2; i++) {
			if (i == Choice) {
				SetConsoleTextAttribute(cs, FOREGROUND_GREEN); cout << "*" + fieldsOfMenu[i] << endl; SetConsoleTextAttribute(cs, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
			else {
				cout << fieldsOfMenu[i] << endl;
			}
		}
		action = _getch();
		system("cls");
		if (action == DOWN) Choice = (Choice + 1) % 2;
		if (action == UP) Choice = (Choice - 1 < 0) ? 2 - 1 : Choice - 1;
		if (action == ENTER) {
			newStudent->SetSex(Choice);
			break;
		}
	}
}

void AddStudent(List<StudentClass>& _Students) {
	system("cls");
	StudentClass newStudent;

	AddFirstName(&newStudent);

	AddSecondName(&newStudent);

	AddSurName(&newStudent);

	AddBirthDate(&newStudent);

	AddAdmissionYear(&newStudent);

	AddFaculty(&newStudent);

	AddDepartment(&newStudent);

	AddGroup(&newStudent);

	AddAccountBookNumber(&newStudent);

	ChooseSex(&newStudent);

	_Students.Append(newStudent);
}

void AddSubject(List<string>& _SubjectNames) {
	string s;
	system("cls");

	while (true) {
		cout << "Введите название нового предмета:" << endl;
		getline(cin, s);
		system("cls");
		switch (NameCheck(s)){
		case 0: case 1:
			if (UniqueSubjectCheck(_SubjectNames, s)) {
				_SubjectNames.Append(s);
				return;
			} else {
				cout << "Ошибка. Введенное значение не уникально" << endl;
			}
			break;
		case 2:
			cout << "Ошибка. Введенное значение не должно содержать иностранных букв" << endl;
			break;
		case 3:
			cout << "Ошибка. Введенное значение не должно содержать цифр" << endl;
			break;
		case 4:
			cout << "Ошибка. Введенное значение не должно содержать спец.символов" << endl;
			break;
		}
	}
}
