#include <iostream>
#include "softwarestudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent():Student()
{

    degreeType = SOFTWARE;

}


SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeType degree):Student(studentID, firstName, lastName, emailAddress, age, days)

{

    degreeType = SOFTWARE;


}


DegreeType SoftwareStudent::getDegreeType()

{

    return degreeType;

}


void SoftwareStudent::print()

{

    this->Student::print(); //call print from student class where it is only a virtual method.
    cout << "SOFTWARE" << "\n";

}



SoftwareStudent::~SoftwareStudent()
{

    Student::~Student();

}



