#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student 
{
public:

    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[]);

//Getters

string getStudentID();
string getFirstName();
string getLastName();
string getEmailAddress();
int getAge();
int* getDays();
virtual DegreeType getDegreeType() = 0; //virtual (can't instantiate)



//Setters

void setStudentID(string studentID);
void setFirstName(string firstName);
void setLastName(string lastName);
void setEmailAddress(string emailAddress);
void setAge(int age);
void setDays(int days[]); 
virtual void print() = 0;
virtual ~Student();

protected:
    DegreeType degreeType;
    int age;
    int days[3];
    string studentID, firstName, lastName, emailAddress;
};
