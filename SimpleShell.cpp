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

// C declarations
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for POSIX

using namespace std;

int main()
{
	// Print a prompt
	printf("This is the shell start. Enter a command. \n");

	// Read command line, parse, and execute
	while(1)
	{
		stringstream ssObject;
		string input;
		string command;

		getline(cin, input);

		ssObject << input;
		ssObject >> command;

		if(input == "stop")
		{
			break;
		}
		system(input.c_str());

	}
	fflush(stdin);

	cout << "End of Shell." << endl;

	return 0;
}
