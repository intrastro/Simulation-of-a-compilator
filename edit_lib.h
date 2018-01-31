#include <io.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

void replacement (char* &code, int &size_of_file);

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

