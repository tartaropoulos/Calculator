#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>

class Calculator
{
public:
    enum class Operators : char
    {
        OPERATOR_ADDITION        = '+',
        OPERATOR_SUBSTRACTION    = '-',
        OPERATOR_MULTIPLICATION  = '*',
        OPRATOR_DIVISION         = '/',
    };

    template <typename T1, typename T2>
    std::common_type_t<T1, T2> calculate(T1 leftOperand, Operators op, T2 rightOperand)
    {
        switch(op)
        {
            case Operators::OPERATOR_ADDITION:        return leftOperand + rightOperand;
            case Operators::OPERATOR_SUBSTRACTION:    return leftOperand - rightOperand;
            case Operators::OPERATOR_MULTIPLICATION:  return leftOperand * rightOperand;
            case Operators::OPRATOR_DIVISION:         return leftOperand / rightOperand;
            default:                                  return 0;
        }
    }

};

std::istream& operator>>(std::istream& is, Calculator::Operators& op);

#endif // CALCULATOR_H