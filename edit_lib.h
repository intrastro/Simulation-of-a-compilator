#include <io.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <cstdlib>
using namespace std;

const char LABEL_CHAR = '-';
const char FUNCTION_CHAR = '0';


enum codes
   {
   push,
   pop,
   clear,
   dump,
   in,
   out,
   dupl,
   add,
   sub,
   mul,
   divis,
   fsin,
   fcos,
   fsqrt,
   jmp,
   je,
   jne,
   ja,
   jae,
   jb,
   jbe,
   jt
   };

struct dictionary_cell
    {
    string name;

    int num_string;

    dictionary_cell* link_back;

    dictionary_cell* link_front;
    };
typedef dictionary_cell *Pdictionary_cell;

void replacement (char* &code, int &size_of_file);

void translate_to_machine (char* &code, char* &mcode, int &size_of_file, int &size_of_file_compiled);

void dictionary_create (char* &code, int &size_of_file, Pdictionary_cell Header);

string ret_code (string tmp, Pdictionary_cell Header);



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

void translate_to_machine (char* &code, char* &mcode, int &size_of_file, int &size_of_file_compiled)
    {
    Pdictionary_cell Header_cell = new dictionary_cell;

    Header_cell -> link_back = nullptr;
    Header_cell -> link_front = nullptr;
    Header_cell -> name = "";
    Header_cell -> num_string = 0;

    dictionary_create (code, size_of_file, Header_cell);

    string mcode_string = "";
    int mcode_string_size = 0;
    string tmp = "";
    string t = "";

    for (int i = 0; i <= size_of_file && code [i] != EOF; i++)
        {
        if (code [i] == '\0')
            {
            if (tmp != "")
                {
                t = ret_code (tmp, Header_cell);

                //std::cout << t;

                if (t != "")
                    {
                    mcode_string += t;

                    mcode_string_size++;
                    }
                else
                    {
                    std::cout << '\n' << tmp << '\n';

                    perror ("compilation error. Check functions. Must be:");

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



    mcode = (char*) calloc (mcode_string_size, sizeof (int));

    for (int i = 0; i < mcode_string_size; i++)
        {
        mcode [i] = mcode_string [i];

        //std::cout << mcode [i];

        std::cout << " " << int (mcode [i]) << " ";
        }

    size_of_file_compiled = mcode_string_size;
    }

string ret_code (string tmp, Pdictionary_cell Header)
    { //TODO :
      //bin search, enum
    string ret_string = " ";

    //std::cout << push_string << " " << tmp << '\n';

    if (tmp == "push")
        {
        ret_string [0] = FUNCTION_CHAR + push;

        return ret_string;
        }
    else if (tmp == "pop")
        {
        ret_string [0] = FUNCTION_CHAR + pop;

        return ret_string;
        }
    else if (tmp == "clear")
        {
        ret_string [0] = FUNCTION_CHAR + clear;

        return ret_string;
        }
    else if (tmp == "dump")
        {
        ret_string [0] = FUNCTION_CHAR + dump;

        return ret_string;
        }
    else if (tmp == "in")
        {
        ret_string [0] = FUNCTION_CHAR + in;

        return ret_string;
        }
    else if (tmp == "out")
        {
        ret_string [0] = FUNCTION_CHAR + out;

        return ret_string;
        }
    else if (tmp == "dupl")
        {
        ret_string [0] = FUNCTION_CHAR + dupl;

        return ret_string;
        }
    else if (tmp == "add")
        {
        ret_string [0] = FUNCTION_CHAR + add;

        return ret_string;
        }
    else if (tmp == "sub")
        {
        ret_string [0] = FUNCTION_CHAR + sub;

        return ret_string;
        }
    else if (tmp == "mul")
        {
        ret_string [0] = FUNCTION_CHAR + mul;

        return ret_string;
        }
    else if (tmp == "divis")
        {
        ret_string [0] = FUNCTION_CHAR + divis;

        return ret_string;
        }
    else if (tmp == "fsin")
        {
        ret_string [0] = FUNCTION_CHAR + fsin;

        return ret_string;
        }
    else if (tmp == "fcos")
        {
        ret_string [0] = FUNCTION_CHAR + fcos;

        return ret_string;
        }
    else if (tmp == "fsqrt")
        {
        ret_string [0] = FUNCTION_CHAR + fsqrt;

        return ret_string;
        }
    else if (tmp == "jmp")
        {
        ret_string [0] = FUNCTION_CHAR + jmp;

        return ret_string;
        }
    else if (tmp == "je")
        {
        ret_string [0] = FUNCTION_CHAR + je;

        return ret_string;
        }
    else if (tmp == "jne")
        {
        ret_string [0] = FUNCTION_CHAR + jne;

        return ret_string;
        }
    else if (tmp == "ja")
        {
        ret_string [0] = FUNCTION_CHAR + ja;

        return ret_string;
        }
    else if (tmp == "jae")
        {
        ret_string [0] = FUNCTION_CHAR + jae;

        return ret_string;
        }
    else if (tmp == "jb")
        {
        ret_string [0] = FUNCTION_CHAR + jb;

        return ret_string;
        }
    else if (tmp == "jbe")
        {
        ret_string [0] = FUNCTION_CHAR + jbe;

        return ret_string;
        }
    else if (tmp == "jt")
        {
        ret_string [0] = FUNCTION_CHAR + jt;

        return ret_string;
        }
    else //dictionary search
        {
        int help_tmp = -1;

        for (Pdictionary_cell p = Header; p != nullptr; p = p -> link_front)
            {
            if (p -> name == tmp)
                {
                help_tmp = p -> num_string;

                break;
                }
            }

        if (help_tmp != -1)
            {
            ret_string [0] = LABEL_CHAR + help_tmp;

            return ret_string;
            }
        else
            {
            return "";
            }
        }
    }

void dictionary_create (char* &code, int &size_of_file, Pdictionary_cell Header)
    {
    Pdictionary_cell p = Header;


    string tmp = "";
    string t = "";
    int q_strings = 0;

    for (int i = 0; i <= size_of_file && code [i] != EOF; i++)
        {
        if (code [i] == '\0')
            {
            if (tmp != "" && tmp.size () >= 1 && tmp [tmp.size () - 1] == ':')
                {
                q_strings++;

                t = ret_code (tmp, Header);

                //std::cout << t;

                if (t == "")
                    {
                    //add a cell

                    p -> link_front = new dictionary_cell;
                    p -> link_front -> link_back = p;
                    p -> link_front -> link_front = nullptr;
                    p -> link_front -> name = tmp;
                    p -> link_front -> num_string = q_strings; //?? q_strings?
                    p = p -> link_front;
                    }


                t = "";
                tmp = "";
                }
            }
        else if (!(code [i] >= '0' && code [i] <= '9'))
            {
            tmp += code [i];
            }
        }

    }



