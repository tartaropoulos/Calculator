#ifndef UTILITES_H
#define UTILITES_H

#include "Calculator.h"

#include <concepts>
#include <iostream>
#include <string_view>

template<typename T>
// concept IsCalculatorInput = std::integral<T> || std::floating_point<T> || std::same_as<T, Calculator::Operators>;
concept IsCalculatorInput = (!std::same_as<T, char> && !std::same_as<T, bool> && std::integral<T>) || 
                              std::floating_point<T> || 
                              std::same_as<T, Calculator::Operators>;

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