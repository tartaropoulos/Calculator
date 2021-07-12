#include "Calculator.h"

#include <algorithm>
#include <array>

// double Calculator::calculate(double leftOperand, Operators op, double rightOperand)
// {
//     double result{.0};
//     switch(op)
//     {
//         case Operators::OPERATOR_ADDITION:        result = leftOperand + rightOperand;
//                                                   break;
//         case Operators::OPERATOR_SUBSTRACTION:    result = leftOperand - rightOperand;
//                                                   break;
//         case Operators::OPERATOR_MULTIPLICATION:  result = leftOperand * rightOperand;
//                                                   break;
//         case Operators::OPRATOR_DIVISION:         result = leftOperand / rightOperand;
//         default:                                  break;
//     }

//     return result;
// }

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