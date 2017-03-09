#include "Tree_234.h"
#include <iostream>
using namespace std;
Tree::Tree()
{
	mRoot = NULL;
	

}
void Tree::Insert(Student*s)
{
	int ID = s->getID();
	bool inserted = false;
	if( mRoot == NULL)//check to see if the root, and tree, are empty
	{
		mRoot = new Node(s);//allocate memory for a root node
		inserted = true;
	}
	Node *Cur = mRoot;
	while(inserted == false)//while the item has not been inserted
	{
		Node * prev = mRoot;
		if(Cur->A  && Cur->B && Cur->C )//check to see if the node has 3 values
		{
			if(is_in_node(Cur,ID) == false)
			{
				split(Cur,prev);//preemptive split the current node
			}
			else
			{
				inserted = true;
			}
		}
		else if(Cur->L != NULL||Cur->M1 != NULL||Cur->M2 != NULL || Cur -> R != NULL)//check to see if Node has any children (any pointer is not equal to null means a pointer)
		{
			if(is_in_node(Cur,ID) == false)
			{
				if(s->getID()<Cur->A->getID())//if value is less than A, branch left
				{
					prev = Cur;
					Cur = Cur->L;
				}
				else if(Cur->B != NULL)//b in use
				{
					if(s->getID()<Cur->B->getID())//if value less than B, branch M1
					{
						prev = Cur;
						Cur = Cur->M1;
					}
					else
					{
						if(Cur->C != NULL)// c in use
						{
							if(s->getID()<Cur->C->getID())//if value less than C, branch M2
							{
								prev = Cur;
								Cur = Cur->M2;
							}
							else //if value greater than C, branch right
							{
								prev = Cur;
								Cur = Cur->R;
							}
						}
						else//if c is not in use and value is greater than b, branch M2
						{
							prev = Cur;
							Cur = Cur->M2;
						}
					}
				}
			
		
				else//if b is not in use and value is greater than A, branch m1
				{
					prev = Cur;
					Cur = Cur->M1;
				}
			}
			else
			{
				inserted = true;
			}
		}
		else if(Cur->L == NULL&& Cur->M1 == NULL&&Cur->M2 == NULL &&Cur -> R == NULL)//check to see if no children (leaf node)
		{	
			if(is_in_node(Cur, ID) == false)
			{
				if(Cur->B == NULL)//b not in use and a in use
				{
					if(s->getID()<Cur->A->getID())//value less than A
					{
						Cur->B = Cur->A;
						Cur->A = s;
					}
					else//Value greter than A
					{
						Cur->B = s;
					}
				}
				else//b in use
				{
					if(s->getID()<Cur->B->getID())//Value less than B
					{
						if(s->getID()>Cur->A->getID())//Value greater than A
						{
							Cur->C = Cur->B;
							Cur->B = s;
						}
						else//value less than A
						{
							Cur->C = Cur->B;
							Cur->B = Cur->A;
							Cur->A = s;
						}
					}
					else//value greater than B
					{
						Cur->C = s;
					}
				}

				
			}
			inserted = true;
		}
	}

}
void Tree::split(Node * Cur, Node * prev)
{
	Node * newL = new Node(Cur->A);
	Node * newR = new Node(Cur->C);
	Node * newprevR = prev->M2;
	Node * prevM1 = prev->M1;
	newR->L = Cur->M2;
	newL->L = Cur->L;
	newR->M1 = Cur->R;
	newL->M1 = Cur->M1;
	Cur->L = newL;
	Cur->M1 = newR;
	Cur->R = Cur->M2 = NULL;
	Cur->A = Cur->B;
	Cur->B = Cur->C = NULL;
	int curID = Cur->A->getID();
	if (prev->A->getID() != curID)
	{
		if (prev->A&&prev->B&&prev->C)//if previous is full
		{
			*prev = *Cur;
		}
		else
		{
			if (prev->B == NULL)
			{
				if (curID<prev->A->getID())//if inserted into the A position of parent
				{
					prev->B = prev->A;
					prev->A = Cur->A;
					prev->L = Cur->L;
					prev->M1 = Cur->M1;
				}
				else//if inserted into B position of parent
				{
					prev->B = Cur->A;
					prev->M1 = Cur->L;
					prev->M2 = Cur->M1;
				}
			}
			else//parent b in use
			{
				if (curID< prev->B->getID())
				{
					if (curID >prev->A->getID())//insert into B position
					{
						prev->C = prev->B;
						prev->B = Cur->A;
						prev->M1 = Cur->L;
						prev->M2 = Cur->M1;
						prev->R = newprevR;
					}
					else//insert into A position in parent
					{
						prev->C = prev->B;
						prev->B = prev->A;
						prev->A = Cur->A;
						prev->L = Cur->L;
						prev->M1 = Cur->M1;
					}
				}
				else//insert into c position of parent
				{
					prev->C = Cur->A;
					prev->R = Cur->M1;
					prev->M2 = Cur->L;
				}
			}
			*Cur = *prev;
		}
	}


}

int Tree::countLevels(Node * root)
{
	int levels;
	if(root == NULL)
	{
		levels = 0;
	}
	else
	{
		levels = 1;
		while(root != NULL)
		{
			if(root->L ||root->M1||root->M2 ||root->R)
			{
				levels ++;
				if(root->L)
				{
					root = root->L;
				}
				else if(root->M1)
				{
					root = root->M1;
				}
				else if(root->M2)
				{
					root = root->M2;
				}
				else if(root->R)
				{
					root = root->R;
				}
			}
			else
			{
				break;
			}
		
		
		}
	}
	
	return levels;
}
bool Tree:: is_in_node(Node * cur, int ID)
{
	bool is_in = false;
	if(cur->A->getID() == ID)
		is_in = true;
	else if(cur->B && cur->B->getID() == ID)
		is_in = true;
	else if(cur->C&&cur->C->getID() == ID)
		is_in = true;

	return is_in;
}
bool Tree:: is_leaf(Node*cur)
{
	bool leaf;
	if(cur->L == NULL&& cur->M1 == NULL&&cur->M2 == NULL &&cur -> R == NULL)
		leaf = true;
	else
		leaf = false;

	return leaf;
}
Tree::Node*Tree::getroot()
{
	return mRoot;
}
void Tree::display_in_order(Node * root)
{

	
	if(root == NULL){}
	
	else
	{
			if(root->L != NULL)
			{
				display_in_order(root->L);
				print_node(root);
			}
			if(root->R != NULL)
			{
				display_in_order(root->R);
				print_node(root);
			}
			
			if(root->M2 != NULL)
			{
				display_in_order(root->M2);
				print_node(root);
			}
			if(root->M1!=NULL)
			{
				display_in_order(root->M1);
				print_node(root);
			}
		
		
	
		
	}
		
}
void Tree::print_node(Node * node)
{
	cout<<node->A->getName()<<","<<node->A->getID()<<";";
	if(node->B)
	{
		cout<<node->B->getName()<<","<<node->B->getID()<<";";
	}
	if(node->C)
	{
		cout<<node->C->getName()<<","<<node->C->getID()<<";";
	}
}
string Tree::get_name(int id, Node * root)
{
	
	if(root == NULL)
	{
		cout<<"(student not found)"<<endl;
	}
	else
	{
		if(root->L != NULL)
		{
			get_name(id,root->L);
		}
		if(root->R != NULL)
		{
			get_name(id,root->R);
		}
		if(root->A)
		{
			if(root->A->getID() == id)
			{
				cout<<root->A->getName()<<endl;
			}
		}
		if(root->B)
		{
			if(root->B->getID() == id)
			{
				cout<<root->B->getName()<<endl;
			}
		}
		if(root->C)
		{
			if(root->C->getID() == id)
			{
				cout<<root->C->getName()<<endl;
			}
		}
		if(root->M1!=NULL)
		{
			get_name(id,root->M1);
		}
		if(root->M2 != NULL)
		{
			get_name(id,root->M2);
		}
	}
	return "hello";
}
bool Tree::count_values_in_node(int id, Node*root)
{
	static bool found = false;
	if(root == NULL)
	{
		cout<<-1<<endl;
	}
	else
	{

		if(root->L != NULL)
		{
			count_values_in_node(id,root->L);
		}
		if(root->R != NULL)
		{
			count_values_in_node(id,root->R);
		}
	if(root->A)
		{
			if(root->A->getID() == id)
			{
			
				if(root->B)
				{
					if(root->C)
					{
						
						cout<<3<<endl;
				
					}
					else
					{
						cout<<2<<endl;
						
					}
				
				}
				else
				{
					cout<<1<<endl;
					
				}
				found = true;
			}

		}
		

		if(root->B)
		{
			if(root->B->getID() == id)
			{
				
				if(root->C)
				{
					cout<<3<<endl;

				}
				else
				{
					cout<<2<<endl;

				}
				found = true;
			}
	
		}
		
		if(root->C)
		{
			if(root->C->getID() == id)
			{
	
				cout<<3<<endl;
				found = true;
			}
			
		
		}
	
		if(root->M1!=NULL)
		{
			count_values_in_node(id,root->M1);
		}
		if(root->M2 != NULL)
		{
			count_values_in_node(id,root->M2);
		}
	
	}
	return found;
}
int Tree::get_level(int id, Node * root)
{
	cout<<"not implemented"<<endl;
	return 0;
}
	
	
