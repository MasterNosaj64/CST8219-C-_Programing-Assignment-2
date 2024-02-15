/************************************************************************************************************
Filename: Animation.cpp
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
List of source files: Animation.cpp, Frame.cpp, AnimationManager.cpp
Purpose: All the logic for manipulating frames
************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"
using namespace std;

/************************************************************************************************************
Function name: Animation
Purpose: Edits the frames in the Animation
In parameters: None
Out parameters: None
Version: 3.0
Author: Jason Waid
*************************************************************************************************************/
void Animation::EditFrame() {

	char tempFrameName[64];//temp space for taking input for frameName
	double duration = 0; //holds duration temporarily for the frame
	int frameCounter = 0; //counts frames
	int index = 0; //holds index

	cout << "Edit a Frame in the Animation" << endl;

	//checks if frames are present first
	if (frames.empty() == false) {
		
		//this logic counts the frames by incrementing the frameCounter for every iteration
		for (Frame& i : frames) {
			frameCounter++;
		}

		cout << "There are " << frameCounter << " Frame(s) in the list. Please specify the index (<=" << frameCounter - 1 << ") to edit at : ";
		cin >> index;

		//ensures the user doesn't go out of bounds
		if ((index >= 0) && (index <= frameCounter - 1))
		{
			frameCounter = 0;//resets frameCounter so that it may be resued

			for (Frame& i : frames) {
				
				if (frameCounter == index) {//once we've iterated to the correct frame (determined by index) logic will apply
					
					cout << "The name and duration of this Frame are " << i << ". What do you wish to replace them with?" << endl;
					cin >> tempFrameName;
					cin >> duration;

					//extra space for null terminating byte taken care of in constructor
					Frame frameEdit(tempFrameName, duration);

					i.operator=(frameEdit);

					cout << "Frame #" << index << " edit completed" << endl;
					break;
				}

				frameCounter++;
			}
		}
		else
		{
			cout << "ERROR: Invalid input" << endl;
		}
	}
	else
	{
		cout << "This are no Frames in the Animation" << endl;
	}
}
void Animation::DeleteFrame() {
	//checks if any frames are present fist
	if (frames.empty() == false) {

		frames.pop_front();
		cout << "First Frame deleted" << endl;
	}
	else
	{
		cout << "This are no Frames in the Animation" << endl;
	}
}
/************************************************************************************************************
Function name: operator>>
Purpose: Overloads the >> operation when entering data for frames
In parameters: istream&, Animation&
Out parameters: istream&
Version: 1.0
Author: Jason Waid
*************************************************************************************************************/
istream& operator>>(istream& input, Animation& animation) {
	char tempFrameName[64];
	double duration = 0;

	cout << "Insert a Frame in the Animation" << endl;
	cout << "Please enter the Frame frameName: ";
	input >> tempFrameName;

	cout << "Please enter the Frame duration: ";
	input >> duration;
	//new object is created
	//extra space for null terminating byte is taken care of inside constructor
	Frame newFrame(tempFrameName, duration);
	
	//added to front of list
	animation.frames.push_front(newFrame);

	cout << "Frame " << tempFrameName << " added at the front of frames" << endl;

	return input;
}
/************************************************************************************************************
Function name: operator<<
Purpose: Overloads the << operation when outputing data for frames
In parameters: ostream&, Animation&
Out parameters: ostream&
Version: 1.0
Author: Jason Waid
*************************************************************************************************************/
ostream& operator<<(ostream& output, Animation& animation) {
	int counter = 0;
	cout << "\tAnimation name is " << animation.animationName << endl;
	cout << "\tReport the Animation" << endl;
	//checks if frames are present first
	if (animation.frames.empty() == false) {
		//loops through all the frames
		for (Frame& i : animation.frames) {
			cout << "\tFrame " << counter++ << ": " << i;
		}
	}
	else
	{
		cout << "\tNo frames in the Animation" << endl;
	}
	return output;
}