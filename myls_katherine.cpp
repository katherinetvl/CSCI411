/* 
 * Katherine Le
 * CSCI 411
 * ls lab
 */

// C declarations
#include <sys/stat.h> //POSIX header
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

// C++ declarations
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

int main()
{
        // Print a prompt
        printf("Type myls to mimic the ls command. Type quit to exit. \n");

        while(1)
        {
                stringstream ssObject;
                string input;
                string command, param;
                getline(cin, input);

                ssObject << input;
                ssObject >> command >> param;

                if(command == "quit")
                {
                        break;
                }
                else if(command == "myls")
                {
                        // printf("Going to parse arguments and output commands \n");

                        // declare pointer to directory name
                        char *dirName;
                        // string cdDir = "cd ";

                        // if parameter given, check if directory and open
                        if(!param.empty())
                        {
                                char *paramPtr = const_cast<char*>(param.c_str());
                                dirName = paramPtr;
                                DIR *potentialDir = opendir(dirName);
                                if(potentialDir)
                                {
                                        // cdDir = cdDir + param;
                                        // cout << "cdDir is: " + cdDir << endl;
                                        chdir(param.c_str());   // open the directory
                                }
                        }

                        // show current directory used
                        printf("Current working directory: %s\n", get_current_dir_name());

                        // list all files:
                        // 1. declare directory pointer
                        DIR *dirPTR;
                        struct dirent *dirP;
                        dirPTR = opendir(".");  // open directory
                        if (dirPTR)
                        {
                                while((dirP = readdir(dirPTR)) != NULL)
                                {
                                        // permissions

                                        // name of directory
                                        cout << dirP->d_name << " ";

                                        // date last modified

                                        cout << endl;
                                }

                                // close directory
                                closedir(dirPTR);
                                break;
                        }
                }
                else
                {
                        break;
                }
        }       // end while loop

        fflush(stdin);

    return 0;
}

