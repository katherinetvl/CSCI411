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
                        printf("Hi. Going to parse arg.");
                }
                else
                {
                        break;
                }
        }

        fflush(stdin);

    return 0;
}
