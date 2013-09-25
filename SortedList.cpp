///////////////////////////////////////////////////////////////////////////////
//                   ALL STUDENTS COMPLETE THESE SECTIONS
// Main Class File:  StudentDB.o
// File:             SortedList.cpp
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
#include "SortedList.h"

using namespace std;

/*
 * SortedList class
 *
 * A SortedList is an ordered collection of Students.  The Students are ordered
 * from lowest numbered student ID to highest numbered student ID.
 */


/**
  * Zero-arg constructor
  */
SortedList::SortedList() {
head = new Listnode;
}

/**
  * If a student with the same ID is not already in the list, inserts the given 
  * student into the list in the appropriate place and returns true.  If there 
  * is already a student in the list with the same ID then the list is not changed 
  * and false is returned.
  *
  * @return boolean: true if student added, false if student already present
  */
bool SortedList::insert(Student *s) {	
	int ID = s->getID();
	int tempID;
	int nextID;
	Listnode *temp;
	temp = head;
	Listnode *L = new Listnode;
	L->student = s;
	if (head->student == NULL) {
		L->next = NULL;
		head = L;
		return true;
	}
	else if (head->student->getID() > ID) {
		L->next = head->next;
		head = L;
		return true;
	}
	while (temp->next != NULL) {
		tempID = temp->student->getID();
		nextID = temp->next->student->getID();
		if (tempID == ID) {
			return false;
		}
		if (tempID < ID && nextID > ID) {
			L->next = temp->next;
			temp->next = L;
			return true;
		}
		temp = temp->next;	
	}
	L->next = NULL;
	temp->next = L;
	return true;	
}

/**
  * Searches the list for a student with the given student ID.  If the
  * student is found, it is returned; if it is not found, NULL is returned.
  *
  * @return Student*: pointer to found student or NULL if not found
  */
Student* SortedList::find(int studentID) {
	Listnode *temp;
	temp = head;
	while(temp != NULL){
		if(temp->student->getID() == studentID){
			return (temp->student);
		}
		temp = temp->next;
	}
	return NULL;
}

/**
  * Searches the list for a student with the given student ID.  If the 
  * student is found, the student is removed from the list and returned;
  * if no student is found with the given ID, NULL is returned.
  * Note that the Student is NOT deleted - it is returned - however,
  * the removed list node should be deleted.
  *
  * @return Student*: pointer to removed student or NULL if not found
  */
Student* SortedList::remove(int studentID) {
	int tempID;
	int nextID;
	Listnode *temp;
	temp = head;
	if(head == NULL){
		return NULL;
	}
	else if(head->student->getID()==studentID)
	{
		Listnode *fakehead;
		fakehead = head;
		Student *retStu = (head->student);
		temp = head->next;
		head = temp;
		delete fakehead;
		return retStu;
	}
	while(temp->next != NULL){
		tempID = temp->student->getID();
		nextID = temp->next->student->getID();
		if(temp->next->student->getID() == studentID){
			
			return (temp->student);
		}
		temp = temp->next;
	}
	return NULL;
}

/**
  * Prints out the list of students to standard output.  The students are
  * printed in order of student ID (from smallest to largest), one per line
  */
void SortedList::print() const {
	Listnode *temp = new Listnode;
	*temp = *head;
	while(temp != NULL) {
		cout << temp->student->getID() << endl;	
		temp = temp->next;
	}
}
