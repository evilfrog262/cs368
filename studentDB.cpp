/*******************************************************************************
Author:        Kristin Cox
CS Login:      kcox

Pair Partner:  Brandon Korf
CS Login:      korf

Course:         CS 368, Spring 2012
Assignment:     Programming Assignment 1 
*******************************************************************************/
#include <iostream>

using namespace std;

    struct Student {
      int studentID; //positive 6-digit integer, not starting with 0
      int credits; //must be greater than or equal to 0
      double GPA; //between 0.0 and 4.0
    };

void addStudent(Student database[], int studentID, int credits, double GPA, int &numStudents);
void deleteStudent(Student database[], int studentID, int &numStudents);    
void updateStudent(Student database[], int studentID, char letterGrade, int credits, int &numStudents);
void print(Student database[], int &numStudents);
bool isValidID(int studentID);
bool isValidCredits(int credits);
bool isValidGPA(double GPA);
bool isValidGrade(char letterGrade);

/**
  * Reads user commands from the console (cin) and processes the student 
  * database accordingly. Each command will be on a separate line.
  */
int main() {
    bool done = false; //keeps track of whether the user wants to quit
    char choice; //stores user input
    int tempID; //positive 6-digit integer, not starting with 0
    int tempCredits; //must be greater than or equal to 0
    double tempGPA; //between 0.0 and 4.0
    char letterGrade; //must be A, B, C, D, or F
    int numStudents = 0; //counter for students in the array
    Student database [5000];

    cout << "Enter your commands at the > prompt:" << endl;
    while (!done) {
        cout << "> ";
        cin >> choice;

        switch (choice) {

            case 'd':  
                cin >> tempID;  // read in the integer ID
		deleteStudent(database, tempID, numStudents);
                break;

            case 'q':  
                done = true;
                cout << "quit" << endl;
                break;
	
	    case 'a':
		//read in integer ID, integer credits, double GPA
	    	cin >> tempID >> tempCredits >> tempGPA; 
		addStudent(database, tempID, tempCredits, tempGPA, numStudents);
		break;

	    case 'u':
		//read in integer ID, char grade, integer credits
	    	cin >> tempID >> letterGrade >> tempCredits;
		updateStudent(database, tempID, letterGrade, tempCredits, numStudents);
		break;

	    case 'p':
		print(database, numStudents);
		break;
  
            default: break;
	
        } // end switch

    } // end while

    return 0;
}

/**
  * Adds a student with the given student ID (ID), number of credits (credits), 
  * and overall GPA (GPA) to the database.
  *
  * @param database: Array of Students
  * @param studentID: integer id of student to add
  * @param credits: integer number of credits added student currently has
  * @param GPA: double GPA of the student to be added
  * @param numStudents: integer number of students in the database
  */
void addStudent(Student database[], int studentID, int credits, double GPA, int &numStudents) {
	//true if student with same ID number is not already in database	
	bool unique = true; 
	//adds student if given parameters are in valid range	
	if (isValidID(studentID) && isValidCredits(credits) && isValidGPA(GPA)) {
		//loops through database checking for Student with same ID		
		for (int i = 0; i < numStudents; i++) {
			//if there is a matching ID the student is already in databse			
			if (studentID == database[i].studentID) {
			unique = false;
			}
		}
		//if not already in database, create student with given info and add		
		if (unique) {
			Student s1;
			s1.studentID = studentID;
			s1.credits = credits;
			s1.GPA = GPA;
			database[numStudents] = s1;
			numStudents++;
		}
		//if already in database, print error message
		else {
			cout << "Student " << studentID << " already exists in the database." << endl;
		}
	}
}

/**
  * Deletes the student with the given student ID (ID) from the database.
  *
  * @param database: Array of Students
  * @param studentID: integer id number of the student to be deleted
  * @param numStudents: integer number of students currently in the database
  */
void deleteStudent(Student database[], int studentID, int &numStudents) {
	//true if student with same ID number is not already in database	
	bool unique = true;
	//holds index of student with matching ID number to be deleted	
	int index;
	//checks if ID number is valid	
	if (isValidID(studentID)) {
		//loops through database looking for student with matching ID		
		for (int i = 0; i < numStudents; i++) { 
			//if found update unique and index			
			if (studentID == database[i].studentID) {
				unique = false;
				index = i;
			}
		}
		//if matching student not found output error		
		if (unique) {
			cout << "error - student " << studentID << " not found" << endl;
		}
		//move Student from last filled spot to index of deleted Student
		else {
			numStudents--;
			database[index] = database[numStudents];
		}
	}
}

/**
  * Updates the student with the given student ID (ID) so that both the total 
  * number of credits and the overall GPA reflect the addition of a letter 
  * grade of grade in a course with N credits. 
  *
  * @param database: Array of Students
  * @param studentID: integer id of student to add
  * @param letterGrade: char representing the grade achieved by the student
  * @param credits: integer number of credits added student currently has
  * @param numStudents: integer number of students in the database
  */
void updateStudent(Student database[], int studentID, char letterGrade, int credits, int &numStudents) {
	//true if student with same ID number is not already in database	
	bool unique = true;
	//holds index of student with matching ID number to be updated	
	int index;
	//holds number of credits student has after updating
	int totalCredits; 
	//holds GPA of student after updating
	double newGPA;
	//checks for valid input
	if (isValidID(studentID) && isValidCredits(credits) && isValidGrade(letterGrade)) {
		//loops through database looking for student with matching ID				
		for (int i = 0; i < numStudents; i++) {
			//if found update unique and index						
			if (studentID == database[i].studentID) {
				unique = false;
				index = i;
			}
		}
		//if no matchng student was found ouput an error message
		if (unique) {
			cout << "error - student " << studentID << " not found" << endl;
		}
		else {
			//calculate new number of credits
			totalCredits = database[index].credits + credits;
			//calculate new GPA based on letter grade achieved
			switch(letterGrade){
				case 'A':
				case 'a':
					newGPA = (database[index].credits * 
					database[index].GPA + credits * 4) / totalCredits;
					break;
				case 'B':
				case 'b':
					newGPA = (database[index].credits * 
					database[index].GPA + credits * 3) / totalCredits;
					break;
				case 'C':
				case 'c':
					newGPA = (database[index].credits * 
					database[index].GPA + credits * 2) / totalCredits;
					break;
				case 'D':
				case 'd':
					newGPA = (database[index].credits * 
					database[index].GPA + credits * 1) / totalCredits;
					break;
				case 'F':
				case 'f':
					newGPA = (database[index].credits * 
					database[index].GPA + credits * 0) / totalCredits;
					break;
				default:break;
			}
		}
		//update the values in the database
		database[index].credits = totalCredits;
		database[index].GPA = newGPA;
	}
}

/**
  * Prints the current contents of the student database. 
  *
  * @param database: Array of Students
  * @param numStudents: integer number of students currently in the database
  */
void print(Student database[], int &numStudents) {
	for (int i = 0; i < numStudents; i++) {
		cout << database[i].studentID << ", " <<database[i].credits << 
		", " << database[i].GPA << endl;
	}
	//print message if the database contains no students
	if (numStudents == 0) {
		cout << "The student database is empty." << endl;
	}
}

/**
  * Checks if studentID is in the valid range. 
  *
  * @param studentID: integer ID number of the given student
  * @return true if valid, false if invalid
  */
bool isValidID(int studentID) {
	bool correct = true;
	if (studentID < 100000 || studentID > 999999) {
		correct = false;
		cout << "The ID number must have six digits and may not start with 0." 
		<< endl;
	}
	return correct;
}

/**
  * Checks if number of credits is in the valid range.
  *
   * @param credits: integer number of credits the student has
  *  @return true if valid, false if invalid
  */
bool isValidCredits(int credits) {
	bool correct = true;
	if (credits < 0) {
		correct = false;
		cout << "The number of credits must be a positive integer." << endl;
	}
	return correct;
}

/**
  * Checks if GPA is in the valid range.
  *
   * @param GPA: double GPA of the student
  *  @return true if valid, false if invalid
  */
bool isValidGPA(double GPA) {
	bool correct = true;
	if(GPA < 0 || GPA > 4) {
		correct = false;
		cout << "The GPA must be a number between 0.0 and 4.0." << endl;
	}
	return correct;
}

/**
  * Checks if letter grade is in the valid range.
  *
   * @param letterGrade: char representing grade achieved
  *  @return true if valid, false if invalid
  */
bool isValidGrade(char letterGrade) {
	bool correct = true;
	if (letterGrade!='A'&&letterGrade!='B'&&letterGrade!='C'&&letterGrade!='D'
		&&letterGrade!='F'&&letterGrade!='a'&&letterGrade!='b'&&letterGrade!='c'
		&&letterGrade!='d'&&letterGrade!='f') {
		correct = false;
		cout << "The grade must be an A,B,C,D, or F." << endl;
	}
	return correct;
}
