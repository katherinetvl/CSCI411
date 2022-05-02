/*
 * Katherine Le
 * CSCI 411
 * ls Lab
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
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
        // Print a prompt
        printf("Type myls to mimic the ls command. Type quit to exit. \n");
        const int fileNameWidth = 20;
        const int sizeWidth = 5;

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
                        // declare directory pointer
                        DIR *dirPTR;
                        struct dirent *dirP;
                        dirPTR = opendir(".");  // open current directory to get all files and directories
                        if (dirPTR)
                        {
                                struct stat dirStat;
                                while((dirP = readdir(dirPTR)) != NULL)
                                {
                                        stat(dirP->d_name, &dirStat);
                                        // if directory, indicate as directory
                                        if(dirP->d_type == DT_DIR)
                                        {
                                                cout << "DIR ";
                                        }
                                        else
                                        {
                                                cout << "    ";
                                        }
                                        // permissions
                                        if(dirStat.st_mode & S_IRUSR)
                                        {
                                                cout << "r";
                                        }
                                        else
                                        {
                                                cout << "-";
                                        }
                                        if(dirStat.st_mode & S_IWUSR)
                                        {
                                                cout << "w";
                                        }
                                        else
                                        {
                                                cout << "-";
                                        }
                                        if(dirStat.st_mode & S_IXUSR)
                                        {
                                                cout << "x";
                                        }
                                        else
                                        {
                                                cout << "-";
                                        }
                                        if(dirStat.st_mode & S_IRGRP)
                                        {
                                                cout << "r";
                                        }
                                        else
                                        {
                                                cout << "-";
                                        }
                                        if(dirStat.st_mode & S_IWGRP)
                                        {
                                                cout << "w";
                                        }
                                        else
                                        {
                                                cout << "-";
                                        }
                                        if(dirStat.st_mode & S_IXGRP)
                                        {
                                                cout << "x";
                                        }
                                        else
                                        {
                                                cout << "-";
                                        }
                                        if(dirStat.st_mode & S_IROTH)
                                        {
                                                cout << "r";
                                        }
                                        else
                                        {
                                                cout << "-";
                                        }
                                        if(dirStat.st_mode & S_IWOTH)
                                        {
                                                cout << "w";
                                        }
                                        else
                                        {
                                                cout << "-";
                                        }
                                        if(dirStat.st_mode & S_IXOTH)
                                        {
                                                cout << "x";
                                        }
                                        else
                                        {
                                                cout << "-";
                                        }
                                        cout << " ";

                                        // name of directory
                                        cout << right << setw(fileNameWidth) << dirP->d_name << " ";

                                        // file size
                                        cout << "     " << left << setw(sizeWidth) << dirStat.st_size << " ";

                                        // date last modified
                                        cout << ctime(&dirStat.st_mtime);
                                }
                                cout << endl;
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

