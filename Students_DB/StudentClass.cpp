#include "StudentClass.h"


int NameCheck(string namestring) {
	for (int i = 0; i < namestring.length(); i++) {
		if (namestring[i] == ' ') return 1;																					  //�������� �� �������
		if (((namestring[i] >= 65) && (namestring[i] <= 90)) || ((namestring[i] >= 97) && (namestring[i] <= 122))) return 2;  //�������� �� ����������� �������
		if ((namestring[i] >= 48) && (namestring[i] <= 57)) return 3;														  //�������� �� ����� 
		if (!((namestring[i] >= -64) && (namestring[i] <= -1) || (namestring[i] != -88) || (namestring[i] <= -72))) return 4; //�������� �� ��� ���������
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
		cout << "������� ������� ��������:" << endl;
		getline(cin, s);
		system("cls");
		switch (newStudent->SetFirstName(s)) {
		case 0:
			return;
		case 1:
			cout << "������. ���������� �������� �� ������ ��������� ��������" << endl;
			break;
		case 2:
			cout << "������. ���������� �������� �� ������ ��������� ����������� ����" << endl;
			break;
		case 3:
			cout << "������. ���������� �������� �� ������ ��������� ����" << endl;
			break;
		case 4:
			cout << "������. ���������� �������� �� ������ ��������� ����.��������" << endl;
			break;
		}
	}
}

void AddSecondName(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "������� ��� ��������:" << endl;
		getline(cin, s);
		system("cls");
		switch (newStudent->SetSecondName(s)) {
		case 0:
			return;
		case 1:
			cout << "������. ���������� �������� �� ������ ��������� ��������" << endl;
			break;
		case 2:
			cout << "������. ���������� �������� �� ������ ��������� ����������� ����" << endl;
			break;
		case 3:
			cout << "������. ���������� �������� �� ������ ��������� ����" << endl;
			break;
		case 4:
			cout << "������. ���������� �������� �� ������ ��������� ����.��������" << endl;
			break;
		}
		
	}
}

void AddSurName(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "������� �������� ��������:" << endl;
		getline(cin, s);
		system("cls");
		switch (newStudent->SetSurName(s)) {
		case 0: return;
		case 1:
			cout << "������. ���������� �������� �� ������ ��������� ��������" << endl;
			break;
		case 2:
			cout << "������. ���������� �������� �� ������ ��������� ����������� ����" << endl;
			break;
		case 3:
			cout << "������. ���������� �������� �� ������ ��������� ����" << endl;
			break;
		case 4:
			cout << "������. ���������� �������� �� ������ ��������� ����.��������" << endl;
			break;
		}
	}
}

void AddBirthDate(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "������� ���� �������� � ������� ��.��.����:" << endl;
		getline(cin, s);
		system("cls");
		if (newStudent->SetBirthDate(s)) break;
		else {
			cout << "������ ����� ����" << endl;
		}
	}
}

void AddAdmissionYear(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "������� ��� �����������:" << endl;
		getline(cin, s);
		system("cls");
		switch (newStudent->SetAdmissionYear(s)) {
		case 0:
			return;
		case 1:
			cout << "������. ���������� �������� ������ ��������� ������ �����" << endl;
			break;
		case 2:
			cout << "������. ��������� �������� �����������" << endl;
			break;
			
		}
	}
}

void AddFaculty(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "������� ���������:" << endl;
		getline(cin, s);
		system("cls");
		switch (newStudent->SetFuculty(s)) {
		case 0:
			return;
		case 1:
			cout << "������. ���������� �������� �� ������ ��������� ��������" << endl;
			break;
		case 2:
			cout << "������. ���������� �������� �� ������ ��������� ����������� ����" << endl;
			break;
		case 3:
			cout << "������. ���������� �������� �� ������ ��������� ����" << endl;
			break;
		case 4:
			cout << "������. ���������� �������� �� ������ ��������� ����.��������" << endl;
			break;
		}
	}
}

void AddDepartment(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "������� ������� � ������� ��-0 ��� ��-00:" << endl;
		getline(cin, s);
		system("cls");
		if (newStudent->SetDepartment(s)) break;
		else {
			cout << "������. ���������� �������� �� ������������� �������" << endl;
		}
	}
}

void AddGroup(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "������� ������ � ������� ����-00-00:" << endl;
		getline(cin, s);
		system("cls");
		if (newStudent->SetGroup(s)) break;
		else {
			cout << "������. ���������� �������� �� ������������� �������" << endl;
		}
	}
}

void AddAccountBookNumber(StudentClass* newStudent) {
	string s;
	system("cls");

	while (true) {
		cout << "������� ����� ������������� ������ � ������� 00�0000:" << endl;
		getline(cin, s);
		system("cls");
		if (newStudent->SetAccountBookNumber(s)) break;
		else {
			cout << "������. ���������� �������� �� ������������� �������" << endl;
		}
	}
}

void ChooseSex(StudentClass* newStudent) {
	HANDLE cs = GetStdHandle(STD_OUTPUT_HANDLE);
	int Choice = 0;
	char action;
	string fieldsOfMenu[2] = { "�������", "�������" };

	system("cls");
	while (true) {
		cout << "�������� ���:" << endl;
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
		cout << "������� �������� ������ ��������:" << endl;
		getline(cin, s);
		system("cls");
		switch (NameCheck(s)){
		case 0: case 1:
			if (UniqueSubjectCheck(_SubjectNames, s)) {
				_SubjectNames.Append(s);
				return;
			} else {
				cout << "������. ��������� �������� �� ���������" << endl;
			}
			break;
		case 2:
			cout << "������. ��������� �������� �� ������ ��������� ����������� ����" << endl;
			break;
		case 3:
			cout << "������. ��������� �������� �� ������ ��������� ����" << endl;
			break;
		case 4:
			cout << "������. ��������� �������� �� ������ ��������� ����.��������" << endl;
			break;
		}
	}
}
