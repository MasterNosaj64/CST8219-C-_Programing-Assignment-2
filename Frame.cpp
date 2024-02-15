/************************************************************************************************************
Filename: Frame.cpp
Version: 1.0
Author: Jason Waid
Student Number: 040912687
Course Name: C++
Course Code: CST8219
Lab Section: 303
Assignment Number: 2
Assignment Name: Animation Project in C
Due Date: 2019/09/11
Submission Date: 2019/09/11
Professor's Name: Mohamed Abouseif
List of source files: Animation.cpp, Frame.cpp, AnimationManager.coo
Purpose: All the logic for initializing, alloacting, deallocting and editing memory exists in this file
************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;
#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"


/************************************************************************************************************
Function name: Frame - Constructor
Purpose: Initializes a frame object
In parameters: char pointer, double
Out parameters: None
Version: 3.0
Author: Jason Waid
*************************************************************************************************************/
Frame::Frame(char* frameName, double duration) {
	
	this->frameName = new char[strlen(frameName) + 1];
	strcpy(this->frameName, frameName);
	this->duration = duration;

}

/***********************************************
Function Name: Frame - Copy Constructor
Purpose: copy constructor to initialize other Frame members object
Function In parameters: Frame&
Function Out parameters: None
Version: 1.0
Student Name: Jason Waid
***********************************************/
Frame::Frame(const Frame& oldFrame) {
	
	this->frameName = new char[strlen(oldFrame.frameName) + 1];
	strcpy(this->frameName, oldFrame.frameName);
	this->duration = oldFrame.duration;
}

/************************************************************************************************************
Function name: ~Frame - Deconstructor
Purpose: Deletes all memory allocated for the frame
In parameters: None
Out parameters: None
Version: 2.0
Author: Jason Waid
*************************************************************************************************************/
Frame::~Frame() {
	if(this->frameName)
	delete this->frameName;

}
/************************************************************************************************************
Function name: operator=
Purpose: Overloads = operator when updating frame data members
In parameters: Frame&
Out parameters: Pointer to a frame
Version: 1.0
Author: Jason Waid
*************************************************************************************************************/
Frame& Frame::operator=(const Frame& frame) {

	//delete old frame name first
	delete this->frameName;

	this->frameName = new char[strlen(frame.frameName)+1];
	strcpy(this->frameName, frame.frameName);
	duration = frame.duration;

	return *(this);
}

/************************************************************************************************************
Function name: operator<<
Purpose: Overloads << operator when printing frame data members
In parameters: ostream&, Frame& 
Out parameters: ostream&
Version: 1.0
Author: Jason Waid
*************************************************************************************************************/
ostream& operator<<(ostream& output, Frame& frame) {

	output << "frameName = " << frame.frameName << "; duration = " << frame.duration << endl;

	return output;
}



