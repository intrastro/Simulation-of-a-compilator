#include "load_lib.h"
#include "edit_lib.h"
using namespace std;


int main()
    {
    char filename [] = "code.txt";
    char* code = nullptr;
    int size_of_file = 0;

    if (load_from_file (filename, code, size_of_file))
        {
        std::cout << code << std::endl;
        }
    else
        {
        perror ("unknown error");

        return -1;
        }

    std::cout << "_______________________" << std::endl;

    replacement (code, size_of_file);

    std::cout << code << std::endl;



    getch();
    }

