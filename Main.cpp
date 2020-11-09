#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "degree.h"
#include "student.h"
#include "roster.h"

int main() {


	// studentData Table input string
	const int numStudents = 5;
	const string studentData[numStudents] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Mike,Bliss,mbliss3@wgu.edu,36,22,34,45,SOFTWARE" };


	//--Top output
	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "Student ID: 001136448" << endl;
	cout << "Name: Mike Bliss" << endl << endl << endl;

	Roster classRoster;

	for (int i = 0; i < numStudents; i++) {
		/* First, grab a raw data string, second is to parse it, third is to call add and give it the results of the parse
		** once finished, classRoster will be populated and ready to use*/

		string s = studentData[i]; // this grabs the student to use, or in other words, one line of the string studentData

		// parse student ID
		int comma = s.find(",");// parse begins and ends here - put tokens in temporary variable instead of using mutators
		string sID = s.substr(0, comma);

		// parse first name
		int parsedData = comma + 1;
		comma = s.find(",", parsedData);
		string fN = s.substr(parsedData, comma - parsedData);

		// parse last name
		parsedData = comma + 1;
		comma = s.find(",", parsedData);
		string lN = s.substr(parsedData, comma - parsedData);

		// parse email address
		parsedData = comma + 1;
		comma = s.find(",", parsedData);
		string e = s.substr(parsedData, comma - parsedData);

		// parse age
		parsedData = comma + 1;
		comma = s.find(",", parsedData);
		int a = stoi(s.substr(parsedData, comma - parsedData));

		// parse days in course 1
		parsedData = comma + 1;
		comma = s.find(",", parsedData);
		int d1 = stoi(s.substr(parsedData, comma - parsedData));

		// parse days in course 2
		parsedData = comma + 1;
		comma = s.find(",", parsedData);
		int d2 = stoi(s.substr(parsedData, comma - parsedData));

		// parse days in course 3
		parsedData = comma + 1;
		comma = s.find(",", parsedData);
		int d3 = stoi(s.substr(parsedData, comma - parsedData));

		// parse degree program
		parsedData = comma + 1;
		comma = s.find(",", parsedData);
		string deg = s.substr(parsedData, comma - 1);
		DegreeProgram degree;
		if (deg == "SECURITY") {
			degree = SECURITY;
		}
		else if (deg == "NETWORK") {
			degree = NETWORK;
		}
		else if (deg == "SOFTWARE") {
			degree = SOFTWARE;
		}

		// Populate classRoster using add()
		classRoster.add(sID, fN, lN, e, a, d1, d2, d3, degree); //pass in temp variables that are parsed into add()
	}

	cout << "Displaying all students:" << endl;
	classRoster.printAll();
	classRoster.printInvalidEmails();

	for (int i = 0; i < 5; ++i) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
	}

	cout << endl;

	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");


	return 0;
}