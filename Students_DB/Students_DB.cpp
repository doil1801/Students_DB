#include "ConsoleClass.h"
#include <iostream>
#include <cstdio>
#include <regex>
#include "StudentClass.h"
#include "List.h"

int main() {
	List<string> SubjNames;
	List<StudentClass> Students;
	ConsoleClass cons;

//	AddStudent(Students);
//	WriteToFile(Students);
	ReadFromFile(Students);
	_getch();
}