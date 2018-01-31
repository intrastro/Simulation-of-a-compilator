#include <io.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

int file_size(char filename [])
    {
    int size_of_file = 0;
    char tmp = '-';

    FILE *file_from = fopen(filename, "r");

    if (file_from == NULL)
        {
        perror ("error: no file");

        return -1;
        }

    while (tmp != EOF)
        {
        tmp = fgetc(file_from);
        size_of_file++;
        }
    fclose (file_from);

    return (size_of_file - 1);
    }

bool load_from_file (char filename [], char* &code, int &size_of_file)
    {
    size_of_file = file_size (filename);
    if (size_of_file == -1) return false;

    code = (char*) calloc (size_of_file, sizeof (char));

    FILE *file_from = fopen(filename, "r");

    fgets(code, (size_of_file + 1), file_from);

    fclose (file_from);

    return true;
    }

bool load_to_file (char filename [], char* &code, int &size_of_file)
    {
    FILE *file_to = fopen(filename, "r");

    if (file_to == NULL)
        {
        perror ("error: no file");

        return false;
        }

    fputs(code, file_to);

    fclose (file_to);

    return true;
    }

int main()
    {
    char filename [] = "code.txt";
    char* code = nullptr;
    int size_of_file = 0;

    if (load_from_file (filename, code, size_of_file))
        {
        std::cout << code;
        }

    getch();
    }



