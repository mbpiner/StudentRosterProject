#include <iostream>
#include "securitystudent.h"
using std::cout;

SecurityStudent::SecurityStudent():Student()
{

    degreeType = SECURITY;

}


SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeType degree):Student(studentID, firstName, lastName, emailAddress, age, days)

{

    degreeType = SECURITY;

}


DegreeType SecurityStudent::getDegreeType()

{

    return SECURITY;

}


void SecurityStudent::print()

{

    this->Student::print(); //call print from student class where it is only a virtual method.
    cout << "SECURITY" << "\n";

}



SecurityStudent::~SecurityStudent()
{

    Student::~Student();

}



