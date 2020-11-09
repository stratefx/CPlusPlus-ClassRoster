//#pragma once
// Roster.h

// header file guard directs preprocessor to only include file contents once
#ifndef ROSTER__H			// ifndef stands for if-not-defined
#define ROSTER_H

#include <string>
using namespace std;

#include "student.h"
#include "degree.h"

class Roster {
private:

	int craIndex = 0;
public:
	Student* classRosterArray[5];//an array of 5 students of the Student class
	// add() sets the instance variables from part D1 and updates the roster
	// this will build the student using classRosterArray
	// it will build a student and call the constructor
	void add(string studentID, string firstName, string lastName,
		string emailAddress, int age, int daysInCourse1, int daysInCourse2, int
		daysInCourse3, DegreeProgram degreeprogram);

	/* remove() removes students from the roster by student ID. If the student ID does not
	exist, the function prints an error message indicating that the student was not found*/
	void remove(string studentID);

	/*prints a complete tab-separated list of student data in the provided format:
	A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55}
	Degree Program: Security. The printAll() function should loop through all the students in
	classRosterArray and call the print() function for each student*/
	void printAll();

	/*correctly prints a student’s average number of days in the three courses. The student is
	identified by the studentID parameter*/
	void printAverageDaysInCourse(string studentID);

	/*verifies student email addresses and displays all invalid email addresses to the user
	Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ')*/
	void printInvalidEmails();

	/*prints out student information for a degree program specified by an enumerated type.
	This might need to be linked to degree.h somehow*/
	void printByDegreeProgram(DegreeProgram degreeProgram);	//-specified by an enumerated type	

	Roster();
	~Roster();

};


#endif // !ROSTER.H

