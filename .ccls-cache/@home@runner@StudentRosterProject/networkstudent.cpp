#include <iostream>
#include "networkstudent.h"

using std::cout;

NetworkStudent::NetworkStudent():Student()
{

    degreeType = NETWORK;

}


NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeType degree):Student(studentID, firstName, lastName, emailAddress, age, days)

{

    degreeType = NETWORK;

}


DegreeType NetworkStudent::getDegreeType()

{

    return NETWORK;

}


void NetworkStudent::print()

{

    this->Student::print(); //call print from student class where it is only a virtual method.
    cout << "NETWORK" << "\n";

}



NetworkStudent::~NetworkStudent()
{

    Student::~Student();

}



