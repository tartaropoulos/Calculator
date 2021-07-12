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

    // double calculate(double leftOperand, Operators op, double rightOperand);

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

    // template <typename T1, typename T2>
    // auto calculate(T1 leftOperand, Operators op, T2 rightOperand) -> std::common_type_t<T1, T2>
    // {
    //     std::common_type_t<T1, T2> result{};
    //     switch(op)
    //     {
    //         case Operators::OPERATOR_ADDITION:        result = leftOperand + rightOperand;
    //                                                 break;
    //         case Operators::OPERATOR_SUBSTRACTION:    result = leftOperand - rightOperand;
    //                                                 break;
    //         case Operators::OPERATOR_MULTIPLICATION:  result = leftOperand * rightOperand;
    //                                                 break;
    //         case Operators::OPRATOR_DIVISION:         result = leftOperand / rightOperand;
    //         default:                                  break;
    //     }

    //     return result;
    // }
};

std::istream& operator>>(std::istream& is, Calculator::Operators& op);

#endif // CALCULATOR_H