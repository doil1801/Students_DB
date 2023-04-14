#pragma once
#include "List.h"
#include <windows.h>
#include "StudentClass.h"
#include <conio.h>
#include <stdio.h>
#include <iostream>

const int n = 66;

class ConsoleClass {
private:
	HANDLE cs = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string StartMenu = "������� ����";
	const int lenOfStartMenu = 6;
	std::string fieldsOfStartMenu[6] = {
		"���������� ������ ��������� (������� ��� �������� ������)",
		"�������� ������ � ����� ��������",
		"������� ������ � ��������",
		"��������� ��",
		"��������� ������� 66",
		"�����"
	};

	const int lenOfStudentProfile = 8;
	std::string studentProfile[8] = {
		"���: ",
		"���� ��������: ",
		"��� �����������: ",
		"��������: ",
		"�������: ",
		"������: ",
		"����� �������� ������: ",
		"���: ",
	};

	const int lenOfRedMenu = 10;
	std::string RedMenu = "���� �������������� ���������";
	std::string fieldsOfRedMenu[10] = {
		"��������(��������) ���",
		"��������(��������) ���� ��������",
		"��������(��������) ��� �����������",
		"��������(��������) ��������",
		"��������(��������) �������",
		"��������(��������) ������",
		"��������(��������) ����� �������� ������",
		"��������(��������) ���",
		"��������(��������) ������",
		"�����"
	};

	void DrawLine() const{
		std::cout.width(n); std::cout.fill('-'); std::cout << "-" << endl;
		std::cout.fill(' ');
	}

	int leng = 0;
	std::string* fieldsOfMenu = NULL;
	std::string UpNote = "";
	int status = 0;
	int type = 0;
public:
	ConsoleClass() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
	}
	void DrawMenu(int _status, int _type){
		system("cls");
		status = _status;
		type = _type;
		if (_type == 0) {
			leng = lenOfStartMenu;
			fieldsOfMenu = fieldsOfStartMenu;
			UpNote = StartMenu;
		}
		else if (_type == 1) {
			leng = lenOfRedMenu;
			fieldsOfMenu = fieldsOfRedMenu;
			UpNote = RedMenu;
		}
		
		DrawLine();
		std::cout.width(n-1); std::cout << left << "|" + UpNote; std::cout << '|' << endl;
		DrawLine();
		for (int i = 0; i < leng; i++) {
			if (i == _status) {
				std::cout << left << "|"; std::cout.width(n - 2); SetConsoleTextAttribute(cs, FOREGROUND_GREEN); std::cout << "*" + fieldsOfMenu[i]; SetConsoleTextAttribute(cs, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); std::cout << '|' << endl;
			} else {
				std::cout.width(n - 1); std::cout << left << "| " + fieldsOfMenu[i]; std::cout << '|' << endl;
			}
		}
		DrawLine();
	}

	int GetLeng(){
		return leng;
	}

	int GetType(){
		return type;
	}

	void DrawMenu(int status, int type, List<StudentClass>* listPtr){
		
	}
};