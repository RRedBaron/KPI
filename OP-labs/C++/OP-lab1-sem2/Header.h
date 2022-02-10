#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void CreateFileWithSimilarRows(string filename, const int& rows1, const int& rows2, int& count);
void CreateTextFile(string filename, int& rows);
void PrintFile(string filename);