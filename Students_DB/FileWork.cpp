#include "FileWork.h"

void AddStudent(List<StudentClass>& _Students) {
	system("cls");
	string s;
	int n;
	StudentClass newStudent;

	while (true) {
		cout << "Введите фамилию студента" << endl;
		getline(cin, s);
		system("cls");
		if (newStudent.SetFirstName(s) == 0) break;
		else {
			switch (newStudent.SetFirstName(s)) {
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

	while (true) {
		cout << "Введите имя студента" << endl;
		getline(cin, s);
		system("cls");
		if (newStudent.SetSecondName(s) == 0) break;
		else {
			switch (newStudent.SetSecondName(s)) {
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

	while (true) {
		cout << "Введите отчество студента" << endl;
		getline(cin, s);
		system("cls");
		if (newStudent.SetSurName(s) == 0) break;
		else {
			switch (newStudent.SetSurName(s)) {
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

	while (true) {
		cout << "Введите дату рождения в формате дд.мм.гггг" << endl;
		getline(cin, s);
		system("cls");
		if (newStudent.SetBirthDate(s)) break;
		else {
			cout << "Ошибка ввода даты" << endl;
		}
	}

	while (true) {
		cout << "Введите год поступления" << endl;
		getline(cin, s);
		system("cls");
		if (newStudent.SetAdmissionYear(s) == 0) break;
		else {
			switch (newStudent.SetAdmissionYear(s)) {
			case 1:
				cout << "Ошибка. Введененое значение должно содержать только цифры" << endl;
				break;
			case 2:
				cout << "Ошибка. Введененое значение некорректно" << endl;
				break;
			}
			cin.clear();
			cin.ignore();
		}
	}

	while (true) {
		cout << "Введите факультет" << endl;
		getline(cin, s);
		newStudent.SetFuculty(s);
		system("cls");
		if (newStudent.SetFuculty(s) == 0) break;
		else {
			switch (newStudent.SetFuculty(s)) {
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

	while (true) {
		cout << "Введите кафедру в формате АА-0" << endl;
		getline(cin, s);
		newStudent.SetDepartment(s);
		system("cls");
		if (newStudent.SetDepartment(s)) break;
		else {
			cout << "Ошибка. Введененое значение не соответствует формату" << endl;
		}
	}

	while (true) {
		cout << "Введите группу в формате АААА-00-00" << endl;
		getline(cin, s);
		newStudent.SetGroup(s);
		system("cls");
		if (newStudent.SetGroup(s)) break;
		else {
			cout << "Ошибка. Введененое значение не соответствует формату" << endl;
		}
	}

	while (true) {
		cout << "Введите номер студенческого билета в формате 00А0000" << endl;
		getline(cin, s);
		newStudent.SetAccountBookNumber(s);
		system("cls");
		if (newStudent.SetAccountBookNumber(s)) break;
		else {
			cout << "Ошибка. Введененое значение не соответствует формату" << endl;
		}
	}

	cout << "Выберете пол. 1 - м, 0 - ж" << endl;
	cin >> n;
	newStudent.SetSex(n);
	cin.clear();
	cin.ignore();
	_Students.Append(newStudent);
}

int IntLeng(int n) {
	int len = 0;
	while (n > 0) {
		n /= 10;
		len++;
	}
	return len;
}

void WriteToFile(List<StudentClass>& _Students) {
	FILE* file;
	string name = "Students.txt";
	fopen_s(&file, name.c_str(), "wt");
	fprintf(file, "%d\n", _Students.Len());
	for (int i = 0; i < _Students.Len(); i++) {
		fprintf(file, "%d:%s ", _Students.Get(i).GetFirstName().length(), _Students.Get(i).GetFirstName().c_str());
		fprintf(file, "%d:%s ", _Students.Get(i).GetSecondName().length(), _Students.Get(i).GetSecondName().c_str());
		fprintf(file, "%d:%s ", _Students.Get(i).GetSurName().length(), _Students.Get(i).GetSurName().c_str());
		fprintf(file, "%d:%d.%d.%d ", IntLeng(_Students.Get(i).GetBirthDate().GetDay()) + IntLeng(_Students.Get(i).GetBirthDate().GetMonth()) + IntLeng(_Students.Get(i).GetBirthDate().GetYear()) + 2, _Students.Get(i).GetBirthDate().GetDay(), _Students.Get(i).GetBirthDate().GetMonth(), _Students.Get(i).GetBirthDate().GetYear());
		fprintf(file, "%d:%d ", IntLeng(_Students.Get(i).GetAdmissionYear()), _Students.Get(i).GetAdmissionYear());
		fprintf(file, "%d:%s ", _Students.Get(i).GetFuculty().length(), _Students.Get(i).GetFuculty().c_str());
		fprintf(file, "%d:%s ", _Students.Get(i).GetDepartment().length(), _Students.Get(i).GetDepartment().c_str());
		fprintf(file, "%d:%s ", _Students.Get(i).GetGroup().length(), _Students.Get(i).GetGroup().c_str());
		fprintf(file, "%d:%s ", _Students.Get(i).GetAccountBookNumber().length(), _Students.Get(i).GetAccountBookNumber().c_str());
		fprintf(file, "%d:%d\n", 1, (int)_Students.Get(i).GetSex());
	}

	fclose(file);
	Crypt(name);
}

void ReadFromFile(List<StudentClass>& _Students) {
	string name = "Students.txt";
	Decrypt(name);

	FILE* file;
	int lenOfDb = 0;
	int lenOfStr = 0;
	char buff = 0;
	int buffInt = 0;
	string buffString;


	fopen_s(&file, name.c_str(), "rt");
	fscanf_s(file, "%d\n", &lenOfDb);
	for (int i = 0; i < lenOfDb; i++) {
		StudentClass newStudent;

		buffString = "";
		fscanf_s(file, "%d:", &lenOfStr);
		for (int j = 0; j < lenOfStr; j++) {
			buff = getc(file);
			buffString += buff;
		}
		getc(file);
		newStudent.SetFirstName(buffString);

		buffString = "";
		fscanf_s(file, "%d:", &lenOfStr);
		for (int j = 0; j < lenOfStr; j++) {
			buff = getc(file);
			buffString += buff;
		}
		getc(file);
		newStudent.SetSecondName(buffString);

		buffString = "";
		fscanf_s(file, "%d:", &lenOfStr);
		for (int j = 0; j < lenOfStr; j++) {
			buff = getc(file);
			buffString += buff;
		}
		getc(file);
		newStudent.SetSurName(buffString);

		buffString = "";
		fscanf_s(file, "%d:", &lenOfStr);
		for (int j = 0; j < lenOfStr; j++) {
			buff = getc(file);
			buffString += buff;
		}
		getc(file);
		newStudent.SetBirthDate(buffString);

		buffString = "";
		fscanf_s(file, "%d:", &lenOfStr);
		for (int j = 0; j < lenOfStr; j++) {
			buff = getc(file);
			buffString += buff;
		}
		getc(file);
		newStudent.SetAdmissionYear(buffString);

		buffString = "";
		fscanf_s(file, "%d:", &lenOfStr);
		for (int j = 0; j < lenOfStr; j++) {
			buff = getc(file);
			buffString += buff;
		}
		getc(file);
		newStudent.SetFuculty(buffString);

		buffString = "";
		fscanf_s(file, "%d:", &lenOfStr);
		for (int j = 0; j < lenOfStr; j++) {
			buff = getc(file);
			buffString += buff;
		}
		getc(file);
		newStudent.SetDepartment(buffString);

		buffString = "";
		fscanf_s(file, "%d:", &lenOfStr);
		for (int j = 0; j < lenOfStr; j++) {
			buff = getc(file);
			buffString += buff;
		}
		getc(file);
		newStudent.SetGroup(buffString);

		buffString = "";
		fscanf_s(file, "%d:", &lenOfStr);
		for (int j = 0; j < lenOfStr; j++) {
			buff = getc(file);
			buffString += buff;
		}
		getc(file);
		newStudent.SetAccountBookNumber(buffString);

		fscanf_s(file, "%d:%d", &lenOfStr, &buffInt);
		newStudent.SetSex(buffInt);

		_Students.Append(newStudent);
	}

	fclose(file);
}

void WriteSubjToFile(List<string>& _Subjects) {
	FILE* file;

	fopen_s(&file, "Subjects.txt", "wt");
	fprintf(file, "%d\n", _Subjects.Len());

	for (int i = 0; i < _Subjects.Len(); i++) {
		fprintf(file, "%d:%s\n", _Subjects.Get(i).length(), _Subjects.Get(i).c_str());
	}
	fclose(file);
}

void ReadSubjFromFile(List<string>& _Subjects) {
	FILE* file;
	int numberOfSubjects = 0;
	int lenOfStr = 0;
	string buffString;
	char buff = 0;

	fopen_s(&file, "Subjects.txt", "rt");
	fscanf_s(file, "%d\n", &numberOfSubjects);
	for (int i = 0; i < numberOfSubjects; i++) {
		buffString = "";
		fscanf_s(file, "%d:", &lenOfStr);
		for (int i = 0; i < lenOfStr; i++) {
			buff = getc(file);
			buffString += buff;
		}
		_Subjects.Append(buffString);
	}
	fclose(file);
}

void Crypt(string filename) {
	srand(time(NULL));
	string fileNAME = filename.substr(0, filename.find_last_of('.'));
	char pass[64];
	for (int i = 0; i < 64; ++i) {
		switch (rand() % 3) {
		case 0:
			pass[i] = rand() % 10 + '0';
			break;
		case 1:
			pass[i] = rand() % 26 + 'A';
			break;
		case 2:
			pass[i] = rand() % 26 + 'a';
		}
	}
	string command = "OpenSSL\\bin\\openssl.exe enc -aes-256-cbc -salt -in " + filename + " -out " + filename + ".enc -pass pass:";
	command += pass;
	system(command.c_str());
	if (remove(filename.c_str()) != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	ofstream file;
	file.open(fileNAME + "_key.txt", ios::binary);
	file.write(pass, 65);
	file.close();

	command = "OpenSSL\\bin\\openssl.exe pkeyutl -encrypt -inkey rsa.public -pubin -in " + fileNAME+ "_key.txt -out " + fileNAME + "_key.txt.enc";
	system(command.c_str());
	if (remove((fileNAME + "_key.txt").c_str()) != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	system("cls");
}

void Decrypt(string filename) {
	string fileNAME = filename.substr(0, filename.find_last_of('.'));
	string command = "OpenSSL\\bin\\openssl.exe pkeyutl -decrypt -inkey rsa.private -in " + fileNAME + "_key.txt.enc -out key.txt";
		system(command.c_str());
	if (remove((fileNAME + "_key.txt.enc").c_str()) != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	char pass [64];
	ifstream file;
	file.open("key.txt", ios::binary);
	file.read(pass, 65);
	file.close();
	if (remove("key.txt") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	command = "OpenSSL\\bin\\openssl.exe enc -aes-256-cbc -d -in " + filename + ".enc -out " + filename + " -pass pass:";
		command += pass;
	system(command.c_str());
	if (remove((filename + ".enc").c_str()) != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}

}