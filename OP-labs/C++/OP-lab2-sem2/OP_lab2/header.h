#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void CreateNewFile(const char* FName1, const char* FName2);
void CreateFile(const char* FName);
void PrintFile(const char* FName);
vector<string> split(string line, char sep = ' ');