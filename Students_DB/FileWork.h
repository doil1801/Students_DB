#pragma once
#include "List.h"
#include "StudentClass.h"
#include <string>
#include <fstream>

#define DOWN 80
#define UP 72
#define ENTER 13
#define ESCAPE 27

void WriteToFile(List<StudentClass>& _students);

void ReadFromFile(List<StudentClass>& _students);

void WriteSubjToFile(List<std::string>& _subjects);

void ReadSubjFromFile(List<std::string>& _subjects);

void Crypt(std::string fileName);

void Decrypt(std::string fileName);