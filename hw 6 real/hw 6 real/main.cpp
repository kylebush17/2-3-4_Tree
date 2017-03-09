#include "Tree_234.h"
#include "command.h"

#include <iostream>

using namespace std;

int main(void)
{
	Tree T;

	string cmd, start;

	cout << "Kyle Bush, 11426823\n";
	while (1<2)
	{
		cmd = readline();//gets command
		if (cmd == "quit()")
		{
			cout << "Done\n";
			exit(0);
		}
		else
		{

			stringstream ss(cmd);
			getline(ss, start, '(');

			if (start == "add")// add to the list
			{
				string command, c2;
				getline(ss, command, ',');

				getline(ss, c2, ')');
				int id = atoi(c2.c_str());
				Student * s = new Student(id, command);
				T.Insert(s);

				cin.clear();
			}
			else if (start == "countValuesInNode")//count values in node
			{
				string command;
				getline(ss, command, ')');
				int id = atoi(command.c_str());
				bool success = false;
				success = T.count_values_in_node(id, T.getroot());
				if (success == false)
				{
					cout << -1 << endl;
				}
			}
			else if (start == "displayInOrder")
			{
				T.display_in_order(T.getroot());
				cout << endl;
			}
			else if (start == "countLevels")
			{
				int levels = 0;
				levels = T.countLevels(T.getroot());
				cout << levels << endl;
			}
			else if (start == "getName")
			{
				string command;
				getline(ss, command, ')');
				int id = atoi(command.c_str());
				T.get_name(id, T.getroot());
			}
			else if (start == "getLevel")
			{
				cout << "not implemented" << endl;
			}

		}
	}
}