#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
	
using namespace std;

struct Branch {
	int number;
	Branch* left;
	Branch* right;
};

void AddElement(Branch*&, int);
void print_tree(Branch* root);
void pr_obh(Branch* branch, vector <int> &base);
bool is_element_in_vector(int elem, vector <int> base);