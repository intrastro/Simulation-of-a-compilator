#include <io.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

int file_size(char filename []);
bool load_from_file (char filename [], char* &code, int &size_of_file);
bool load_to_file (char filename [], char* &code, int &size_of_file);

int file_size(char filename [])
    {
    int size_of_file = 0;
    char tmp = '\0';

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

    //std::cout << size_of_file;

    return (size_of_file - 1);
    }

bool load_from_file (char filename [], char* &code, int &size_of_file)
    {
    int i = 0;
    char tmp = '\0';

    size_of_file = file_size (filename);
    if (size_of_file == -1) return false;

    code = (char*) calloc (size_of_file, sizeof (char));

    FILE *file_from = fopen(filename, "r");

    i = 0;

    while (tmp != EOF)
        {
        tmp = fgetc(file_from);

        code [i] = tmp;

        i++;
        }

    fclose (file_from);

    return true;
    }

bool load_to_file (char filename [], char* &code, int &size_of_file)
    {
    FILE *file_to = fopen(filename, "a + w");

    if (file_to == NULL)
        {
        perror ("error: no file");

        return false;
        }

    for (int i = 0; i < size_of_file; i++)
        {
        std::cout << " " << int (code [i]) << " ";

        fputc (code [i], file_to);
        }

    //fputc (EOF, file_to);

    fclose (file_to);

    return true;
    }
