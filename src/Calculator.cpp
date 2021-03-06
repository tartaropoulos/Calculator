#include "Calculator.h"

#include <algorithm>
#include <array>

std::istream& operator>>(std::istream& is, CalculatorOperators& op)
{
    if(char temp; is >> temp)
    {
        std::array validOperators{'+', '-', '*', '/'};
        auto result{std::find(validOperators.begin(), validOperators.end(), temp)};

        if(result == validOperators.end())
        {
            is.setstate(std::ios_base::failbit);
            return is;
        }

        op = static_cast<CalculatorOperators>(temp);
    }

    return is;
}