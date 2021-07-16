#ifndef UTILITES_H
#define UTILITES_H

#include <iostream>
#include <string_view>

#include "Calculator.h"

bool getInputItem(std::string_view msg, IsCalculatorInput auto& value)
{
    std::cout << msg;
    std::cin >> value;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(std::cin.fail())
    {
        std::cin.clear();
        getchar();
        return false;
    }

    return true;
}

bool askToContinue(std::string_view msg);

#endif // UTILITES_H