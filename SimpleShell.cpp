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
	// Delete old file history
	ofstream shellOutput;
	string oldFile = "ShellResults.txt";
	shellOutput.open(oldFile);
	if(shellOutput)
	{
		string rmFile = "rm " + oldFile;
		system(rmFile.c_str());
		shellOutput.close();
	}

	// Print a prompt
	printf("This is the shell start. Enter a command. \n");

	// Read command line, parse, and execute
	while(1)
	{
		stringstream ssObject;
		string input;
		string command, command2;
		string history = " >> ShellResults.txt";

		getline(cin, input);

		ssObject << input;
		ssObject >> command >> command2;

		// cout << "This is input " << input << endl;
		// cout << "This is command " << command << endl;
		// cout << "This is command2 " << command2 << endl;

		if(command == "quit")
		{
			break;
		}
		else if(command == "myprocess") // myprocess
		{
			string newCommand = "pidof " + command2 + history; 
			system(newCommand.c_str());
		}
		else if(command == "allprocesses") // allprocesses
		{
			command = "ps" + history;
			system(command.c_str());
		}
		else if(command == "chgd") // chgd <directory>
		{
			command = "cd " + command2 + history;
			system(command.c_str());
		}
		else if(command == "clr") // clr
		{
			if(!command2.empty())
			{
				command = "clear " + command2 + history;
			}
			else
			{
				command = "clear" + history;
			}
			system(command.c_str());
		}
		else if(command == "dir") // dir
		{
			command = "ls -al" + command2 +  history;
			system(command.c_str());
		}
		else if(command == "environ") // environ
		{
			command = "env" + history;
			system(command.c_str());
		}
		else if(command == "help") // help
		{
			if(!command2.empty())
			{
				command = "man " + command2 + history;
			}
			else
			{
				command = "man" + history;
			}
			system(command.c_str());
		}
		else if(command == "repeat") // echo
		{
			char command3;
			ssObject >> command3;
			if(command3 == '>')
			{
				string fileName;
				ssObject >> fileName;
				command = "echo " + command2 + " " + command3 + " " + fileName;
				system(command.c_str());
			}
			else
			{
				command = "echo " + command2 + history;
				system(command.c_str());
			}
		}
		else
		{
			string inputToFile = input + history;
			system(inputToFile.c_str());
		}

	}
	fflush(stdin);

	cout << "End of Shell. Shell History: " << endl;
	string showFile = "cat ShellResults.txt";
	system(showFile.c_str());

	return 0;
}
