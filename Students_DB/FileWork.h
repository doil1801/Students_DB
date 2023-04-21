#pragma once
#include "List.h"
#include "StudentClass.h"
#include <string>
#include <fstream>

void AddStudent(List<StudentClass>& _Students);

int IntLeng(int n);

void WriteToFile(List<StudentClass>& _Students);

void ReadFromFile(List<StudentClass>& _Students);

void WriteSubjToFile(List<string>& _Subjects);

void ReadSubjFromFile(List<string>& _Subjects);

void Crypt(string filename);

void Decrypt(string filename);