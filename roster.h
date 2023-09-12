#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "softwarestudent.h"
#include "networkstudent.h" 
#include "securitystudent.h"

class Roster 
{

private: 
    int lastIdx; //index of last student - how many entries in roster
    int maxRosterSize; // maximum size of roster
    Student** students;

    public:
        
        Roster();
        Roster(int capacity);

	Student* getStudentAt(int index);

	void parseThenAdd(string datarow);

        void printAll();

        void add(string sID, string fn, string ln, string em, int age, int d1, int d2, int d3, DegreeType dt);

        bool remove(string studentID);

        void printByDegree(DegreeType degree);

        void printDays(string studentID);

        void printBadEmails();
};
