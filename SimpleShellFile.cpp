/*
* Katherine Le
* CSCI 411
* Lab: Simple Shell
*/

// C++ declarations
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>

// C declarations
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for POSIX

using namespace std;

int main()
{
	// Print a prompt
	printf("This is the shell start. Running .txt file. \n");

	// Read file, parse, and execute
	ifstream shellInput;
	shellInput.open("inputFile.txt");
	if (!shellInput)
	{
		cout << "Error with file opening." << endl;
	}

	while(shellInput)
	{
		stringstream ssObject;
		string input;
		string command;

		getline(shellInput, input);

		ssObject << input;
		ssObject >> command;
		
		cout << "The command: " + command << endl; 
		system(input.c_str());

	}
	shellInput.close();

	cout << "End of Shell." << endl;

	return 0;
}
