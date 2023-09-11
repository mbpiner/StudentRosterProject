#pragma once
#include <string>
#include "student.h"

class NetworkStudent : public Student
{

public:
    NetworkStudent();
    NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeType degree);

    DegreeType getDegreeType();
    void print();

    ~NetworkStudent();



};