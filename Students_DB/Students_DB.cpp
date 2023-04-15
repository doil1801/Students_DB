#include "ConsoleClass.h"
#include <iostream>
#include <cstdio>
#include <regex>
#include "StudentClass.h"
#include "List.h"

#define DOWN 0x50
#define UP 0x48
#define ENTER 13
#define ESCAPE 27



int main() {
	List<string> SubjNames;
	List<StudentClass> Students;
	ConsoleClass cons;

	cons.Run();
}