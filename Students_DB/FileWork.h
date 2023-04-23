#pragma once
#include "List.h"
#include "StudentClass.h"
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>

#define DOWN 80
#define UP 72
#define ENTER 13
#define ESCAPE 27

int IntLeng(int n);

void WriteToFile(List<StudentClass>& _Students);

void ReadFromFile(List<StudentClass>& _Students);

void WriteSubjToFile(List<string>& _Subjects);

void ReadSubjFromFile(List<string>& _Subjects);

void Crypt(string filename);

void Decrypt(string filename);