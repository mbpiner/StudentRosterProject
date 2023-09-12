#include "roster.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cerr;
using std::cout;

Roster::Roster() {
  this->maxRosterSize = 0;
  this->lastIdx = -1;
  this->students = nullptr;
}

Roster::Roster(int maxRosterSize) {
  this->maxRosterSize = maxRosterSize;
  this->lastIdx = -1; // empty
  this->students = new Student *[maxRosterSize];
}

int main() {

  int numStudents = 5;

  const string studentData[5] = {
      "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,James,Smith,jsmith1@sdf.com,24,5,10,15,SOFTWARE"};

  // Add students to classRoster

  Roster *rost = new Roster(numStudents);

  for (int i = 0; i < numStudents; i++) {

    rost->parseThenAdd(studentData[i]);
  }

  rost->printAll();
  rost->remove("A5");
  rost->printAll();
  rost->printBadEmails();
  rost->printDays("A2");
  rost->printByDegree(SOFTWARE);

} // end main

bool Roster::remove(string studentID) {

  bool studentExists = false;

  for (int i = 0; i <= lastIdx; i++) {

    if (this->students[i]->getStudentID() == studentID) {
      studentExists = true;
      cout << "Deleting student with ID " << studentID << "\n";
      delete this->students[i];
      this->students[i] = this->students[lastIdx];
      lastIdx--;
    }
  }
  return studentExists;
}

void Roster::printDays(string studentID) {

  bool studentExists = false;

  for (int i = 0; i <= lastIdx; i++) {

    if (this->students[i]->getStudentID() == studentID) {
      studentExists = true;
      int *days = students[i]->getDays();
      int averageDays = (days[0] + days[1] + days[2]) / 3;
      cout << "Average days for student " << studentID << " is " << averageDays
           << "."
           << "\n";
    }
  }
  if (!studentExists)
    cout << "Student doesn't exist!\n";
}

Student *Roster::getStudentAt(int index) { return students[index]; }

void Roster::printByDegree(DegreeType degree) {

  cout << "Printing information of all students in "
       << degreeTypeStrings[degree] << " degree program."
       << "\n";

  for (int i = 0; i <= lastIdx; i++) {

    if (this->students[i]->getDegreeType() == degree)
      this->students[i]->print();
  }
}

void Roster::printBadEmails() {

  cout << "Displaying invalid emails: "
       << "\n";
  for (int i = 0; i < 5; i++) {

    string email = "";
    email = (*students[i]).getEmailAddress();

    if (email.find('@') == std::string::npos ||
        email.find(' ') != std::string::npos ||
        email.find('.') == std::string::npos) {
      cout << (*students[i]).getEmailAddress() << '\n';
    }
  }
}

void Roster::parseThenAdd(string row) {
  if (lastIdx < maxRosterSize) {
    lastIdx++;
    DegreeType degreeType;

    // check string denoting degree so it can be set

    if (row.back() == 'Y') {
      degreeType = DegreeType::SECURITY;
    }

    if (row.back() == 'E') {
      degreeType = DegreeType::SOFTWARE;
    }

    if (row.back() == 'K') {
      degreeType = DegreeType::NETWORK;
    }

    /*else
    {
            cout << row.back() << "\n";
            cerr << "INVALID DEGREETYPE, EXITING!\n";
            exit(-1);
    }*/

    int rhs = row.find(",");
    string id = row.substr(0, rhs);

    int lhs = rhs + 1;

    rhs = row.find(",", lhs);
    string fName = row.substr(lhs, rhs - lhs);
    //

    lhs = rhs + 1;

    rhs = row.find(",", lhs);
    string lName = row.substr(lhs, rhs - lhs);
    //

    lhs = rhs + 1;

    rhs = row.find(",", lhs);
    string email = row.substr(lhs, rhs - lhs);
    //

    lhs = rhs + 1;

    rhs = row.find(",", lhs);
    int age = stoi(row.substr(lhs, rhs - lhs));
    //

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int d1 = stoi(row.substr(lhs, rhs - lhs));
    //

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int d2 = stoi(row.substr(lhs, rhs - lhs));
    //

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int d3 = stoi(row.substr(lhs, rhs - lhs));

    add(id, fName, lName, email, age, d1, d2, d3, degreeType);

  } else {

    cerr << "ERROR, ROSTER HAS EXCEEDED CAPACITY.\n EXITING!";
    exit(-1);
  }
}

void Roster::add(string idInput, string fnInput, string lnInput,
                 string emailInput, int ageInput, int days1, int days2,
                 int days3, DegreeType degreeInput) {

  int daysIn[3] = {days1, days2, days3};

  if (degreeInput == DegreeType::SOFTWARE) {
    students[lastIdx] = new SoftwareStudent(
        idInput, fnInput, lnInput, emailInput, ageInput, daysIn, degreeInput);
  }

  if (degreeInput == DegreeType::NETWORK) {
    students[lastIdx] = new NetworkStudent(
        idInput, fnInput, lnInput, emailInput, ageInput, daysIn, degreeInput);
  }

  if (degreeInput == DegreeType::SECURITY) {
    students[lastIdx] = new SecurityStudent(
        idInput, fnInput, lnInput, emailInput, ageInput, daysIn, degreeInput);
  }
}

void Roster::printAll() {

  cout << "Roster:";
  cout << "\n";

  for (int i = 0; i <= this->lastIdx; i++) {
    // for(int i = 0; i < 5; i++){

    (this->students)[i]->print();
  }

  cout << '\n';
}
