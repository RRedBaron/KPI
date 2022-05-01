#include "tree.h"

void AddElement(Branch*& branch, int number) {
	if (!branch)
	{
		branch = new Branch;
		branch->number = number;
		branch->left = 0;
		branch->right = 0;
		return;
	}
	else
	{
		if (number < branch->number) {
			AddElement(branch->left, number);
		}
		else if (number >= branch->number) {
			AddElement(branch->right, number);
		}
	}
}

int levels(Branch* root) {
	if (root == NULL) return 0;
	return max(levels(root->left), levels(root->right)) + 1;
}

void print_tree(Branch* root, int space) {
	if (root == NULL) return;
	print_tree(root->right, ++space);
	for (int i = 1; i < space; i++) {
		cout << '\t';
	}
	cout << root->number << endl;
	print_tree(root->left, space);
}

void print_tree(Branch* root) {
	cout << "#########################\n";
	int l = levels(root);
	for (int i = 0; i < l; i++) cout << i << '\t';
	cout << endl;
	for (int i = 0; i < l; i++) cout << "|\t";
	cout << endl << endl;
	print_tree(root, 0);
	cout << "#########################\n";
}

void pr_obh(Branch* branch, vector <int> &base)
{
	if (branch == NULL) return;
	if (!is_element_in_vector(branch->number, base)) {
		base.push_back(branch->number);
	}
	pr_obh(branch->left, base);   
	pr_obh(branch->right, base); 
}

bool is_element_in_vector(int elem, vector <int> base) {
	return (find(base.begin(), base.end(), elem) == base.end() ? false : true);
}