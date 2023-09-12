Scripting and Programming Applications Project

-----
This is a class project for the Scripting and Programming - Applications in WGU's CS program. There is no GUI.

I did this project long ago - it was one of the very first courses when I started my degree.

I learned more low-level programming basics with C++ like pointers, along with object-oriented concepts like classes (and their instantiated objects), inheritance from main classes to sub-classes, constructors, destructors, accessors (getters), and mutators (setters).

In particular I learned how object-oriented programming helped keep data organized together and worked especially well when you have a fixed set of operations and over time we can add new things by creating new classes implementing existing methods and leaving the classes we already have as they are.

The goal of this project is to create a class roster using C++.

There is a base Student class with the following variables:

Student ID, First Name, Last Name, Email, Age, Array of # of days to complete per course, Degree Types (as described in degree.h - security, network, and software)

There are three subclasses of student which inherit from the Student class: Security, Network, and Software.

There are functions:

Accessor (i.e. getter) for each instance variable, Mutator (i.e. setter) for each instance variable, Constructor (using all parameters provided in the table)
Virtual print() function to print specific student data, Destructor, and Virtual getDegreeProgram() function

The roster loops through the students, prints selected information as requested, and allows removal of specified student records.
It also performs a limited type of input validation (nowadays I would use a basic regex or something).
