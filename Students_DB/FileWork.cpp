#include "FileWork.h"

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
		fprintf(file, "%d:%d ", 1, (int)_Students.Get(i).GetSex());

		
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 10; k++) {
				if (_Students.Get(i).GetValueMark(j, k) != -1) fprintf(file, "%d:%s:%d ", _Students.Get(i).GetNameMark(j, k).length(), _Students.Get(i).GetNameMark(j, k).c_str(), _Students.Get(i).GetValueMark(j, k));
			}
			if (j != 8) fprintf(file, "$ ");
			else fprintf(file, "\n");
		}
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

		fgetc(file);

		int semester = 0;
		int numberOfMark = 0;
		int buffMark;

		while (true) {
			buffString = "";

			buff = getc(file);
			if (buff == '\n') break;
			else if (buff == '$') {
				semester++;
				numberOfMark = 0;
			}
			else if (buff <= '9' && buff >= '0') {
				fseek(file, -1, SEEK_CUR);
				fscanf_s(file, "%d:", &lenOfStr);
				for (int j = 0; j < lenOfStr; j++) {
					buffString += getc(file);
				}
				fscanf_s(file, ":%d", &buffMark);
				newStudent.SetValueMark(semester, numberOfMark, buffMark);
				newStudent.SetNameMark(semester, numberOfMark, buffString);
				numberOfMark++;
			}
		}

		_Students.Append(newStudent);
	}

	fclose(file);
}

void WriteSubjToFile(List<string>& _Subjects) {
	FILE* file;
	string name = "Subjects.txt";

	fopen_s(&file, name.c_str(), "wt");
	fprintf(file, "%d\n", _Subjects.Len());

	for (int i = 0; i < _Subjects.Len(); i++) {
		fprintf(file, "%d:%s\n", _Subjects.Get(i).length(), _Subjects.Get(i).c_str());
	}
	fclose(file);

	Crypt(name);
}

void ReadSubjFromFile(List<string>& _Subjects) {
	FILE* file;
	int numberOfSubjects = 0;
	int lenOfStr = 0;
	string buffString;
	char buff = 0;
	string name = "Subjects.txt";

	Decrypt(name);
	fopen_s(&file, name.c_str(), "rt");
	fscanf_s(file, "%d\n", &numberOfSubjects);
	for (int i = 0; i < numberOfSubjects; i++) {
		buffString = "";
		fscanf_s(file, "%d:", &lenOfStr);
		for (int j = 0; j < lenOfStr; j++) {
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
	char pass[65];
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
	pass[64] = '\0';
	string command = "OpenSSL\\bin\\openssl.exe enc -pbkdf2 -aes-256-cbc -salt -in " + filename + " -out " + filename + ".enc -pass pass:";
	command += pass;
	system(command.c_str());
	if (remove(filename.c_str()) != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	ofstream file;
	file.open(fileNAME + "_key.txt", ios::binary);
	file.write(pass, 64);
	file.close();

	command = "OpenSSL\\bin\\openssl.exe pkeyutl -encrypt -inkey rsa.public -pubin -in " + fileNAME+ "_key.txt -out " + fileNAME + "_key.txt.enc";
	system(command.c_str());
	if (remove((fileNAME + "_key.txt").c_str()) != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
}

void Decrypt(string filename) {
	string fileNAME = filename.substr(0, filename.find_last_of('.'));
	string command = "OpenSSL\\bin\\openssl.exe pkeyutl -decrypt -inkey rsa.private -in " + fileNAME + "_key.txt.enc -out key.txt";
		system(command.c_str());
	if (remove((fileNAME + "_key.txt.enc").c_str()) != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	char pass [65];
	ifstream file;
	file.open("key.txt", ios::binary);
	file.read(pass, 65);
	file.close();
	pass[64] = '\0';
	if (remove("key.txt") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	command = "OpenSSL\\bin\\openssl.exe enc -pbkdf2 -aes-256-cbc -d -in " + filename + ".enc -out " + filename + " -pass pass:";
	command += pass;
	const char* a = command.c_str();
	system(a);
	if (remove((filename + ".enc").c_str()) != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
}