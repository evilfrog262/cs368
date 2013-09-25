///////////////////////////////////////////////////////////////////////////////
//                   ALL STUDENTS COMPLETE THESE SECTIONS
// Main Class File:  StudentDB.o
// File:             Student.cpp
// Semester:         Fall 2012
//
// Author:           Kristin Cox
// CS Login:         kcox
// Lecturer's Name:  Beck Hasti
//
//                   PAIR PROGRAMMERS COMPLETE THIS SECTION
// Pair Partner:     Brandon Korf
// CS Login:         korf
// Lecturer's Name:  Beck Hasti
//
//////////////////////////// 80 columns wide //////////////////////////////////

#include <iostream>
#include "Student.h"

using namespace std;

/**
  * The Student class is used to represent individual students.  Each student
  * object contains a student ID, total number of credits, and overall GPA
  *
  * @author Kristin Cox and Brandon Korf
  */

/**
  * Default (0-arg) constructor
  */
Student::Student() {
studentID = 0;
credits = 0;
GPA = 0;
}

/**
  * Constructs a student with the given ID, 0 credits, and 0.0 GPA
  */
Student::Student(int ID) {
studentID = ID;
credits = 0;
GPA = 0;
}

/**
  * Constructs a student with the given ID, number of credits, and GPA
  */
Student::Student(int ID, int cr, double grPtAv) {
studentID = ID;
credits = cr;
GPA = grPtAv;
}

/**
  * Returns the student ID
  *
  * @return int studentID: six digit ID number of student
  */
int Student::getID() const {
	return studentID;
}

/**
  * Returns the number of credits
  *
  * @return int credits: number of credits student has
  */
int Student::getCredits() const {
	return credits;
}

/**
  * Returns the GPA
  *
  * @return double GPA: student's GPA (0.0 - 4.0)
  */
double Student::getGPA() const {
	return GPA;
}

/**
  * Updates the total credits and overall GPA to take into account the
  * additions of the given letter grade in a course with the given number
  * of credits. 
  *
  * @param char grade: represents the letter grade achieved (A - F)
  * @param int cr: represents the number of credits gained
  */
void Student::update(char grade, int cr) {
	
//calculate new GPA based on letter grade achieved
	switch(grade){
		case 'A':
		case 'a':
			GPA = (credits * GPA) + (cr * 4) / (credits + cr);
			break;
		case 'B':
		case 'b':
			GPA = (credits * GPA) + (cr * 3) / (credits + cr);
			break;
		case 'C':
		case 'c':
			GPA = (credits * GPA) + (cr * 2) / (credits + cr);
			break;
		case 'D':
		case 'd':
			GPA = (credits * GPA) + (cr * 1) / (credits + cr);
			break;
		case 'F':
		case 'f':
			GPA = (credits * GPA) + (cr * 0) / (credits + cr);
			break;
		default:break;
	}
	//calculate new number of credits
	credits += cr; 
}

// Prints out the student to standard output in the format:
    //   ID,credits,GPA
    // Note: the end-of-line is NOT printed after the student information 
void Student::print() const {
	cout << studentID << "," << credits << "," << GPA;
}

