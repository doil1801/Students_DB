#include <fstream>
#include "ConsoleClass.h"
#include "StudentClass.h"
#include "List.h"
#include <conio.h>
using namespace std;

#define DOWN 0x50
#define UP 0x48
#define ENTER 13
#define ESCAPE 27

void prog() {
	
}

int main() {
	List<string> SubjNames;
	List<StudentClass> f;
	ConsoleClass cons;
	int state = 0;
	int action = 0;
	int n = 6;
	int type = 0;


	while (true) {
		cons.DrawMenu(state, type);
		action = _getch();
		if (action == DOWN) state = (state + 1) % n;
		if (action == UP) state = (state - 1 < 0) ? n - 1 : state - 1;
		if (action == ENTER) {
			if (state == n - 1) break;
		}
	}
}

