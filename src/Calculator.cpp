#include "Calculator.h"

#include <algorithm>
#include <array>

std::istream& operator>>(std::istream& is, Calculator::Operators& op)
{
    char temp;
    if(is >> temp)
    {
        std::array validOperators{'+', '-', '*', '/'};
        auto result{std::find(validOperators.begin(), validOperators.end(), temp)};

        if(result == validOperators.end())
        {
            is.setstate(std::ios_base::failbit);
            return is;
        }

        op = static_cast<Calculator::Operators>(temp);
    }

    return is;
}