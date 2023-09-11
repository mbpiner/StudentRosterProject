#include <iostream>
#include <iomanip>
#include "student.h"
using std::cout;
using std::left;
using std::setw;


Student::Student()
{

    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i<3; i++){this->days[i] = 0;};



}



Student::Student(string id, string fName, string lName, string email, int age, int days[])
{

    this->studentID = id;
    this->firstName = fName;
    this->lastName = lName;
    this->emailAddress = email;
    this->age = age;
    for (int i = 0; i<3; i++){this->days[i] = days[i];};



}

//Getters
    int Student::getAge() { return age; }
    string Student::getStudentID() { return studentID; }
    string Student::getFirstName() { return firstName; }
    string Student::getLastName() { return lastName; }
    string Student::getEmailAddress() { return emailAddress; }
		int * Student::getDays(){return days;}



//Setters




	void Student::setAge(int age) { this->age = age; }
	void Student::setStudentID(string studentID) { this->studentID = studentID; }
	void Student::setFirstName(string firstName) { this->firstName = firstName; }
	void Student::setLastName(string lastName) { this->lastName = lastName; }
	void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
  void Student::setDays(int days[]) { for (int i = 0; i<3; i++)this->days[i] = days[i]; }


//methods


void Student::print()
{

cout << left << setw(5) << studentID;
cout << left << setw(15) << firstName;
cout << left << setw(10) << lastName;
cout << left << setw(25) << emailAddress;
cout << left << setw(20) << age;
cout << left << setw(10) << days[0];
cout << left << setw(10) << days[1];
cout << left << setw(10) << days[2];


}



Student::~Student(){

}