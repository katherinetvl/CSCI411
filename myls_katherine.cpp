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
#include <sys/types.h>

// C++ declarations
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

int main()
{
        // Print a prompt
        printf("Type myls to mimic the ls command. Ty>

        while(1)
        {
                stringstream ssObject;
                string input;
                string command, arg1, arg2, arg3;
                getline(cin, input);

                ssObject << input;
                ssObject >> command >> arg1 >> arg2 >>

                if(command == "quit")
                {
                        break;
                }
                else if(command == "myls")
                {
                        printf("Going to parse arguments and output commands \n");

                        // declare pointer to directory name
                        string dirName;

                        // no directory name given
                        if(param.empty())
                        {
                                // use current direct>
                                // continue onto files

                                DIR *dirPTR;
                                struct dirent *dirP;
                                dirPTR = opendir(".");
                                if (dirPTR)
                                {
                                        while((dirP = readdir(dirPTR)) != NULL)
                                        {
                                                cout << dirP->d_name << endl;
                                        }
                                        // close directory
                                        closedir(dirPTR);
                                }
                        }
                        else
                        {
                                // check that dirName exists
                                // state that it is directory
//                              DIR *opendir(dirName);
                                cout << "Directory Name was given." << endl;
                        }
                        // list all files
                }
                else
                {
                        break;
                }
        }

        fflush(stdin);

    return 0;
}
