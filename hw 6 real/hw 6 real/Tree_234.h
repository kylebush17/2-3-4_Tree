#ifndef TREE_2_3_4
#define TREE_2_3_4
#include <iostream>
#include <string>
#include "student.h"

using namespace std;
class Tree
{
public:
	Tree();
	struct Node
	{
		Student *A, *B, *C;
		struct Node * L, *M1, *M2, *R;
		Node(Student *s)
		{
			A = new Student(s->getID(),s->getName());
			B = C = NULL;
			L = M1 = M2 = R = NULL;

		}
	};
	void Insert(Student * s);
	void split(Node * Cur, Node * prev);
	int countLevels(Node * root);
	bool is_in_node(Node * cur, int ID);
	bool is_leaf(Node*cur);
	struct Node * getroot();
	void display_in_order(Node * root);
	void print_node(Node * node);
	string get_name(int id, Node * root);
	bool count_values_in_node(int id, Node * root);
	int get_level(int id, Node * root);
private:
	Node * mRoot;
	
};


#endif