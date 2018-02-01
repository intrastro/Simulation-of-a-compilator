#include "load_lib.h"
#include "edit_lib2.h"
using namespace std;


int main()
    {
    char filename [] = "code.txt";
    char filename2 [] = "compiled_code.txt";
    char* code = nullptr;
    char* mcode = nullptr;
    int size_of_file = 0;
    int size_of_file_compiled = 0;

    write_end (filename);
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

    std::cout << "_______________________" << std::endl;

    translate_to_machine (code, mcode, size_of_file, size_of_file_compiled);

    //std::cout << mcode;

    std::cout << '\n';

    load_to_file (filename2, mcode, size_of_file_compiled);

    getch();
    }

