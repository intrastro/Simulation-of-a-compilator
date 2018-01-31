#include <io.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <cstdlib>
using namespace std;

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
    string ret_string = " ";

    //std::cout << push_string << " " << tmp << '\n';

    if (tmp == "push")
        {
        ret_string [0] = '0' + push;

        return ret_string;
        }
    else if (tmp == "pop")
        {
        ret_string [0] = '0' + pop;

        return ret_string;
        }
    else if (tmp == "clear")
        {
        ret_string [0] = '0' + clear;

        return ret_string;
        }
    else if (tmp == "dump")
        {
        ret_string [0] = '0' + dump;

        return ret_string;
        }
    else if (tmp == "in")
        {
        ret_string [0] = '0' + in;

        return ret_string;
        }
    else if (tmp == "out")
        {
        ret_string [0] = '0' + out;

        return ret_string;
        }
    else if (tmp == "dupl")
        {
        ret_string [0] = '0' + dupl;

        return ret_string;
        }
    else if (tmp == "add")
        {
        ret_string [0] = '0' + add;

        return ret_string;
        }
    else if (tmp == "sub")
        {
        ret_string [0] = '0' + sub;

        return ret_string;
        }
    else if (tmp == "mul")
        {
        ret_string [0] = '0' + mul;

        return ret_string;
        }
    else if (tmp == "divis")
        {
        ret_string [0] = '0' + divis;

        return ret_string;
        }
    else if (tmp == "fsin")
        {
        ret_string [0] = '0' + fsin;

        return ret_string;
        }
    else if (tmp == "fcos")
        {
        ret_string [0] = '0' + fcos;

        return ret_string;
        }
    else if (tmp == "fsqrt")
        {
        ret_string [0] = '0' + fsqrt;

        return ret_string;
        }
    else if (tmp == "jmp")
        {
        ret_string [0] = '0' + jmp;

        return ret_string;
        }
    else if (tmp == "je")
        {
        ret_string [0] = '0' + je;

        return ret_string;
        }
    else if (tmp == "jne")
        {
        ret_string [0] = '0' + jne;

        return ret_string;
        }
    else if (tmp == "ja")
        {
        ret_string [0] = '0' + ja;

        return ret_string;
        }
    else if (tmp == "jae")
        {
        ret_string [0] = '0' + jae;

        return ret_string;
        }
    else if (tmp == "jb")
        {
        ret_string [0] = '0' + jb;

        return ret_string;
        }
    else if (tmp == "jbe")
        {
        ret_string [0] = '0' + jbe;

        return ret_string;
        }
    else if (tmp == "jt")
        {
        ret_string [0] = '0' + jt;

        return ret_string;
        }
    else
        {
        return "";
        }
    }


