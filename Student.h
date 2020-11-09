//#pragma once
// Student.h

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <sstream>
#include <istream>
using namespace std;

#include "degree.h"

class Student {
public:
	const string studentData[5];
	void Print() const;

	// Setters
	void SetStudentID(string studID);
	void SetFirstName(string fName);
	void SetLastName(string lName);
	void SetEmailAddress(string email);
	void SetAge(int ageInYears);
	void SetDaysInCourse(int daysArray[]);
	void SetDegreeProgram(DegreeProgram degree);

	// Getters
	string	GetStudentID()		const;
	string	GetFirstName()		const;
	string	GetLastName()		const;
	string	GetEmailAddress()	const;
	int		GetAge()			const;
	int* GetDaysInCourse()	const;
	DegreeProgram GetDegreeProgram() const;

	// Constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse[], DegreeProgram degreeprogram);

	// Destructor
	~Student();

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int	   age;
	static const int dayArraySize = 3;
	int* daysInCourse;
	DegreeProgram degree;
};


/*
1.  Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
•  student ID
•  first name
•   last name
•  email address
•  age
•  array of number of days to complete each course
•  degree program

2.  Create each of the following functions in the Student class:
a.  an accessor (i.e., getter) for each instance variable from part D1
b.  a mutator (i.e., setter) for each instance variable from part D1
c.  All external access and changes to any instance variables of the Student class must be done
	using accessor and mutator functions.
d.  constructor using all of the input parameters provided in the table
e.  print() to print specific student data
*/

#endif // !STUDENT_H