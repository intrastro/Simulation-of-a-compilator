#include <io.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <cstdlib>
using namespace std;

void replacement (char* &code, int &size_of_file);

void translate_to_machine (char* &code, char* &mcode, int &size_of_file);

string ret_code (string tmp);



void replacement (char* &code, int &size_of_file)
    {
    for (int i = 0; i <= size_of_file; i++)
        {
        if ((code [i] == '\n') || (code [i] == ' '))
            {
            code [i] = '\0';
            }
        }
    }

void translate_to_machine (char* &code, char* &mcode, int &size_of_file)
    {
    string mcode_string = "";
    int mcode_string_size = 0;
    string tmp = "";
    string t = "";

    for (int i = 0; i <= size_of_file; i++)
        {
        if (code [i] == '\0')
            {
            if (tmp != "")
                {
                t = ret_code (tmp);

                //std::cout << t;

                if (t != "")
                    {
                    mcode_string += t;

                    mcode_string_size++;
                    }
                else
                    {
                    std::cout << '\n' << tmp << '\n';

                    perror ("compilation error");

                    break;
                    }

                t = "";
                tmp = "";
                }

            if ((i > 0) && (code [i - 1] == '\0'))
                {
                ;
                }
            else
                {
                mcode_string += '\0';

                mcode_string_size++;
                }
            }
        else if (code [i] >= '0' && code [i] <= '9')
            {
            mcode_string += code [i];

            mcode_string_size++;
            }
        else
            {
            tmp += code [i];
            }
        }



    mcode = (char*) calloc (mcode_string_size, sizeof (char));

    for (int i = 0; i < mcode_string_size; i++)
        {
        mcode [i] = mcode_string [i];

        std::cout << mcode [i];
        }
    }

string ret_code (string tmp)
    { //TODO :
      //bin search, enum
    string push_string = "push";

    //std::cout << push_string << " " << tmp << '\n';

    if (tmp == push_string)
        {
        return "1";
        }
    else
        {
        return "";
        }
    }
