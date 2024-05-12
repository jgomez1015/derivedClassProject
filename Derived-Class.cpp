// Derived-Class.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cstring>
using namespace std;

// Person class Definition //
class Person {
protected:  // A derived class can access protected data
    char Name[20];
public:
    Person (const char* n)
    {
        // choose the version of strcpy for your compiler
        // comment out the other version
//      strcpy_s(Name, n);  // for Microsoft
        strcpy  (Name, n);  // for everywhere except Microsoft
    }
    virtual void print() const
    {
        cout << "Person:  " << Name << endl;
    }
};

// Student class Definition //
class Student : public Person  {
private:
    int    units;
public:
    // Student constructor gets name from Person class
    Student (const char* n, int u) : Person ( n)
    {
        units = u;
    }
    virtual void print() const
    {
        cout << "Student: " << Name << "  Units: " << units << endl;
    }
};

// Teacher class Definition //
class Teacher : public Person  {
	private:
		int    numberOfStudents;
		int	   numberOfClasses;
	public:
        // Teacher constructor gets 'name' from the Person class
		Teacher (const char* n, int s, int c) : Person ( n)
		{
			numberOfStudents = s;
			numberOfClasses = c;
		}
		virtual void print() const
		{
			cout << "Teacher: " << Name 
				<< "  Students: " << numberOfStudents 
				<< "  Classes: " << numberOfClasses << endl;
		}
};
