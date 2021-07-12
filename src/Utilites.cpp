#include "Utilites.h"

bool askToContinue(std::string_view msg)
{
    char option;

    while(true)
    {
        std::cout << msg;
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(option == 'n') {return false;}
        else if(option == 'y') {return true;}
        else {std::cout << "Wrong answer! Use 'y' to continue or 'n' to leave." << std::endl;}
    }
}