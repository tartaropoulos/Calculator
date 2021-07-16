#ifndef UTILITES_H
#define UTILITES_H

#include <concepts>
#include <iostream>
#include <string_view>

#include "Calculator.h"

template<typename T>
concept IsCalculatorInput = (std::is_arithmetic_v<T> || std::same_as<T, Calculator::Operators>) &&
                            // Do exist another way to separate characters and bool from integral types?
                            !std::same_as<T, bool> &&
                            !std::same_as<T, char> &&
                            !std::same_as<T, signed char> &&
                            !std::same_as<T, unsigned char> &&
                            !std::same_as<T, wchar_t> &&
                            !std::same_as<T, char8_t> &&
                            !std::same_as<T, char16_t> &&
                            !std::same_as<T, char32_t>;

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