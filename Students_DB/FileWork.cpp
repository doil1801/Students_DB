#include "FileWork.h"

int IntLength(int n) {
	int len = 0;
	while (n > 0) {
		n /= 10;
		len++;
	}
	return len;
}

void WriteToFile(List<StudentClass>& _students) {
	FILE* file;
	std::string name = "Students.txt";
	fopen_s(&file, name.c_str(), "wt");
	fprintf(file, "%d\n", _students.Len());
	for (int i = 0; i < _students.Len(); i++) {
		fprintf(file, "%d:%s ", _students[i].GetFirstName().length(), _students[i].GetFirstName().c_str());
		fprintf(file, "%d:%s ", _students[i].GetSecondName().length(), _students[i].GetSecondName().c_str());
		fprintf(file, "%d:%s ", _students[i].GetSurName().length(), _students[i].GetSurName().c_str());
		fprintf(file, "%d:%d.%d.%d ", IntLength(_students[i].GetBirthDate().GetDay()) + IntLength(_students[i].GetBirthDate().GetMonth()) + IntLength(_students[i].GetBirthDate().GetYear()) + 2, _students[i].GetBirthDate().GetDay(), _students[i].GetBirthDate().GetMonth(), _students[i].GetBirthDate().GetYear());
		fprintf(file, "%d:%d ", IntLength(_students[i].GetAdmissionYear()), _students[i].GetAdmissionYear());
		fprintf(file, "%d:%s ", _students[i].GetFaculty().length(), _students[i].GetFaculty().c_str());
		fprintf(file, "%d:%s ", _students[i].GetDepartment().length(), _students[i].GetDepartment().c_str());
		fprintf(file, "%d:%s ", _students[i].GetGroup().length(), _students[i].GetGroup().c_str());
		fprintf(file, "%d:%s ", _students[i].GetAccountBookNumber().length(), _students[i].GetAccountBookNumber().c_str());
		fprintf(file, "%d:%d ", 1, (int)_students[i].GetSex());
		
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 10; k++) {
				if (_students[i].GetValueMark(j, k) != -1) fprintf(file, "%d:%s:%d ", _students[i].GetNameMark(j, k).length(), _students[i].GetNameMark(j, k).c_str(), _students[i].GetValueMark(j, k));
			}
			if (j != 8) fprintf(file, "$ ");
			else fprintf(file, "\n");
		}
	}

	fclose(file);
	Crypt(name);
}

void ReadFromFile(List<StudentClass>& _students) {
	std::string name = "Students.txt";
	Decrypt(name);

	FILE* file;
	int lenOfDb = 0;
	int lenOfStr = 0;
	char buff = 0;
	int buffInt = 0;
	std::string buffString;

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
		newStudent.SetFaculty(buffString);

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

		newStudent.CalculateAverageMark();
		_students.Append(newStudent);
	}

	fclose(file);
}

void WriteSubjToFile(List<std::string>& _subjects) {
	FILE* file;
	std::string name = "Subjects.txt";

	fopen_s(&file, name.c_str(), "wt");
	fprintf(file, "%d\n", _subjects.Len());

	for (int i = 0; i < _subjects.Len(); i++) {
		fprintf(file, "%d:%s\n", _subjects[i].length(), _subjects[i].c_str());
	}
	fclose(file);

	Crypt(name);
}

void ReadSubjFromFile(List<std::string>& _subjects) {
	FILE* file;
	int numberOfSubjects = 0;
	int lenOfStr = 0;
	std::string buffString;
	char buff = 0;
	std::string name = "Subjects.txt";

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
		_subjects.Append(buffString);
	}
	fclose(file);
}

void Crypt(std::string fileName) {
	srand(time(NULL));
	std::string fileNAME = fileName.substr(0, fileName.find_last_of('.'));
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
	std::string command = "OpenSSL\\bin\\openssl.exe enc -pbkdf2 -aes-256-cbc -salt -in " + fileName + " -out " + fileName + ".enc -pass pass:";
	command += pass;
	system(command.c_str());
	if (remove(fileName.c_str()) != 0) {
		std::cout << "[ERROR] - deleting file" << std::endl;
	}
	std::ofstream file;
	file.open(fileNAME + "_key.txt", std::ios::binary);
	file.write(pass, 64);
	file.close();

	command = "OpenSSL\\bin\\openssl.exe pkeyutl -encrypt -inkey rsa.public -pubin -in " + fileNAME+ "_key.txt -out " + fileNAME + "_key.txt.enc";
	system(command.c_str());
	if (remove((fileNAME + "_key.txt").c_str()) != 0) {
		std::cout << "[ERROR] - deleting file" << std::endl;
	}
}

void Decrypt(std::string fileName) {
	std::string fileNAME = fileName.substr(0, fileName.find_last_of('.'));
	std::string command = "OpenSSL\\bin\\openssl.exe pkeyutl -decrypt -inkey rsa.private -in " + fileNAME + "_key.txt.enc -out key.txt";
		system(command.c_str());
	if (remove((fileNAME + "_key.txt.enc").c_str()) != 0) {
		std::cout << "[ERROR] - deleting file" << std::endl;
	}
	char pass [65];
	std::ifstream file;
	file.open("key.txt", std::ios::binary);
	file.read(pass, 65);
	file.close();
	pass[64] = '\0';
	if (remove("key.txt") != 0) {
		std::cout << "[ERROR] - deleting file" << std::endl;
	}
	command = "OpenSSL\\bin\\openssl.exe enc -pbkdf2 -aes-256-cbc -d -in " + fileName + ".enc -out " + fileName + " -pass pass:";
	command += pass;
	const char* a = command.c_str();
	system(a);
	if (remove((fileName + ".enc").c_str()) != 0) {
		std::cout << "[ERROR] - deleting file" << std::endl;
	}
}