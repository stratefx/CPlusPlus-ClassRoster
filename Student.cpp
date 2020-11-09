// Student.cpp
#include <iostream>
#include <sstream>
#include <string>
#include <istream>
using namespace std;
#include "Student.h"
#include "roster.h"


// Constructor
Student::Student(string studID, string fName, string lName, string email, int howOld,
	int daysInCourse[], DegreeProgram degreeprogram)
{
	studentID = studID;
	firstName = fName;
	lastName = lName;
	emailAddress = email;
	age = howOld;
	this->daysInCourse = new int[dayArraySize];
	for (int i = 0; i < dayArraySize; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
	degree = degreeprogram;
}

// Setters - section 8.4 in zyBook
void Student::SetStudentID(string studID) {
	studentID = studID;
}
void Student::SetFirstName(string fName) {
	firstName = fName;
}
void Student::SetLastName(string lName) {
	lastName = lName;
}
void Student::SetEmailAddress(string email) {
	emailAddress = email;
}
void Student::SetAge(int ageInYears) {
	age = ageInYears;
}
void Student::SetDaysInCourse(int daysArray[]) {
	daysInCourse = new int[dayArraySize];
}

void Student::SetDegreeProgram(DegreeProgram degree) {
	this->degree = degree;
}


// Getters - section 8.4 in zyBook
string Student::GetStudentID()	 const {
	return studentID;
}

string Student::GetFirstName()	const {
	return firstName;
}

string Student::GetLastName()	const {
	return lastName;
}

string Student::GetEmailAddress()	const {
	return emailAddress;
}

int Student::GetAge() const {
	return age;
}
int* Student::GetDaysInCourse()	const {
	return daysInCourse;
}

DegreeProgram Student::GetDegreeProgram() const {
	return degree;
}


// Print function called by printAll() in Roster class
void Student::Print() const {

	cout << studentID << "	";
	cout << "First Name: " << firstName << "	";
	cout << "Last Name: " << lastName << "	";
	cout << "Age: " << age << "	";
	cout << "daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}" << "	";
	cout << "Degree Program: " << degreeProgramString[degree];
	cout << endl;
}

Student::~Student() {
	delete[] daysInCourse;
}
