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
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

using namespace std;

void HiMomFunction()
{
    int pip1[2];        // file descriptor for pipe 
    // pip1[0] is for reading
    // pip1[1] is for writing 
    if(pipe(pip1) == -1)
    {
        printf("Pipe failed to open \n");
        exit(1);
    }
    
    pid_t pID = fork(); // creating a new child process
    
    if(pID < 0)
    {
        perror("Failed to fork \n");
        exit(1);
    }
    else if(pID == 0)
        // child process
    {
        close(pip1[0]);     // child is not reading from pipe
        char passedString[10] = "Hi mom!";
        write(pip1[1], &passedString, 10);  // write to pipe
        close(pip1[1]);     // close write side of pipe
        exit(0);
    }
    else
    {
        waitpid(pID, nullptr, 0);
        close(pip1[1]);     // parent is not writing to pipe
        
        char getPassedString[10];
        read(pip1[0], &getPassedString, 10);
        close(pip1[0]);
        
        printf("From child process: %s\n", getPassedString);
    }
}

void signalHandler(int signum)
{
    string signalCaught = "";
    string command = "";
    string history = " >> ShellResults.txt";
    
    if(signum == SIGINT)
    {
        signalCaught = "Caught the SIGINT signal";
        cout << signalCaught << endl;
    }
    else        
    {
        signalCaught = "Caught the signal number " + signum;
        cout << signalCaught << endl;
    }
    command = "echo " + signalCaught + history;
    system(command.c_str());

    cout << "End of Shell. Shell History: " << endl;
    string showFile = "cat ShellResults.txt";
    system(showFile.c_str());  
        
    exit(signum);
}

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

    // Register signal handler through signal() function
    signal(SIGINT, signalHandler);
    
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
        else if(command == "hiMom")
        {
            command = "echo hiMom command implementation" + history;
            system(command.c_str());
            HiMomFunction();
        }
		else
		{
			string inputToFile = input + history;
			system(inputToFile.c_str());
		}
        sleep(1);
	}
	fflush(stdin);

	cout << "End of Shell. Shell History: " << endl;
	string showFile = "cat ShellResults.txt";
	system(showFile.c_str());

	return 0;
}