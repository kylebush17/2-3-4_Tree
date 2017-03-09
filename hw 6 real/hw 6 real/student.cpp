#include "student.h"
#include <iostream>

using namespace std;
Student::Student()
{
	student_id = 1;
	student_name = "john doe";
}
Student::Student(int Id, string name)
{
	student_id = Id;
	student_name = name;
}
void Student::setID(int ID)
{
	student_id = ID;
}
void Student::setName(string name)
{
	student_name = name;
}
int Student::getID()
{
	return student_id;
}
string Student::getName()
{
	return student_name;
}