#include "ConsoleClass.h"
#include "StudentClass.h"
#include "List.h"

int main() {
	List<string> SubjectNames;
	List<StudentClass> Students;
	ConsoleClass cons;

	ReadFromFile(Students);
	cons.Run(Students, SubjectNames);

}