#include "ConsoleClass.h"
#include "StudentClass.h"
#include "List.h"

int main() {
	List<std::string> subjectNames;
	List<StudentClass> students;
	ConsoleClass console;

	ReadFromFile(students);
	ReadSubjFromFile(subjectNames);
	WriteToFile(students);
	WriteSubjToFile(subjectNames);
	console.Run(students, subjectNames);
}