#pragma once
#include "List.h"
#include <windows.h>
#include "StudentClass.h"
#include <conio.h>
#include <stdio.h>
#include <iostream>
using namespace std;

const int n = 66;

class ConsoleClass {
private:
	HANDLE cs = GetStdHandle(STD_OUTPUT_HANDLE);
	string StartMenu = "Главное меню";
	string fieldsOfStartMenu[6] = {
		"Посмотреть список студентов (удалить или изменить данные)",
		"Добавить данные о студенте",
		"Удалить данные о студенте",
		"Сохранить БД",
		"Выполнить вариант 66",
		"Выход"
	};

	void DrawLine() const{
		cout.width(n); cout.fill('-'); cout << "-" << endl;
		cout.fill(' ');
	}
public:
	ConsoleClass() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
	}
	void DrawMenu(int status, int type){
		int leng = 6;
		string* fieldsOfMenu = fieldsOfStartMenu;
		string UpNote = StartMenu;
		system("cls");
		DrawLine();
		cout.width(n-1); cout << left << "|" + UpNote; cout << '|' << endl;
		DrawLine();
		for (int i = 0; i < leng; i++) {
			if (i == status) {
				cout << left << "|"; cout.width(n - 2); SetConsoleTextAttribute(cs, FOREGROUND_GREEN); cout << "*" + fieldsOfMenu[i]; SetConsoleTextAttribute(cs, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); cout << '|' << endl;
			} else {
				cout.width(n - 1); cout << left << "| " + fieldsOfMenu[i]; cout << '|' << endl;
			}
		}
		DrawLine();
	}

	void DrawMenu(int status, int type, List<StudentClass>* listPtr){
		
	}
};