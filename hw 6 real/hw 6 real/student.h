#include <iostream>

using namespace std;

class Student
{
public:
	Student();
	Student(int Id, string name);
	void setID(int ID);
	void setName(string name);
	int getID();
	string getName();
private:
	string student_name;
	int student_id;
};