// Roster.cpp

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "roster.h"
#include "student.h"


Roster::Roster() {

}

Roster::~Roster() {
	for (int i = 0; i < craIndex; i++) {
		delete classRosterArray[i];
	}
}

// add() sets the instance variables from part D1 and updates the roster
void Roster::add(string studentID, string firstName, string lastName,
	string emailAddress, int age, int daysInCourse1, int daysInCourse2, int
	daysInCourse3, DegreeProgram degreeprogram) {

	int dArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[craIndex] = new Student(studentID, firstName, lastName, emailAddress, age, dArray, degreeprogram);
	++craIndex;

}

/* remove() removes students from the roster by student ID. If the student ID does not
exist, the function prints an error message indicating that the student was not found*/
void Roster::remove(string studentID) {

	bool removed = false;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			if (classRosterArray[i]->GetStudentID() == studentID) {
				cout << "Removing " << studentID << "." << endl;
				classRosterArray[i] = nullptr;
				removed = true;
			}
		}
	}

	if (!removed) {
		cout << "Removing " << studentID << " again." << endl;
		cout << "The student with the ID: " << studentID << " was not found." << endl;
	}


}


/*prints a complete tab-separated list of student data in the provided format:
A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55}
Degree Program: Security. The printAll() function should loop through all the students in
classRosterArray and call the print() function for each student*/
void Roster::printAll() {

	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Print();
		}
	}
	cout << endl;
}


/*correctly prints a student’s average number of days in the three courses. The student is
identified by the studentID parameter*/
void Roster::printAverageDaysInCourse(string studentID) {

	for (int i = 0; i < 5; ++i) {
		int* d;
		d = classRosterArray[i]->GetDaysInCourse();
		if (classRosterArray[i]->GetStudentID() == studentID) {
			cout << "Student ID:	" << classRosterArray[i]->GetStudentID() << ", averages	";
			cout << ((d[0] + d[1] + d[2]) / 3) << " days in a course." << endl;
		}
	}
}


/*verifies student email addresses and displays all invalid email addresses to the user
Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ')*/
void Roster::printInvalidEmails() {

	cout << "Displaying invalid emails:" << endl << endl;
	for (int i = 0; i < 5; ++i) {
		string emailAd = classRosterArray[i]->GetEmailAddress();
		if (emailAd.find_first_of(" ") < emailAd.length()) {
			cout << classRosterArray[i]->GetEmailAddress() << endl;
		}
		else if (!(emailAd.find_first_of(".") < emailAd.length())) {
			cout << classRosterArray[i]->GetEmailAddress() << endl;
		}
		else if (!(emailAd.find_first_of("@") < emailAd.length())) {
			cout << classRosterArray[i]->GetEmailAddress() << endl;
		}
	}
	cout << endl;
}

/*prints out student information for a degree program specified by an enumerated type.
This might need to be linked to degree.h somehow*/
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	cout << "Showing students in degree program: " << degreeProgramString[degreeProgram] << endl << endl;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->Print();
		}
	} cout << endl;
}