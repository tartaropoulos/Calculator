#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>

enum class CalculatorOperators : char
{
    OPERATOR_ADDITION        = '+',
    OPERATOR_SUBSTRACTION    = '-',
    OPERATOR_MULTIPLICATION  = '*',
    OPRATOR_DIVISION         = '/',
};

template<typename T>
concept IsCalculatorInput = (std::is_arithmetic_v<T> || std::same_as<T, CalculatorOperators>) &&
                            // Do exist another way to separate characters and bool from integral types?
                            !std::same_as<T, bool> &&
                            !std::same_as<T, char> &&
                            !std::same_as<T, signed char> &&
                            !std::same_as<T, unsigned char> &&
                            !std::same_as<T, wchar_t> &&
                            !std::same_as<T, char8_t> &&
                            !std::same_as<T, char16_t> &&
                            !std::same_as<T, char32_t>;

template<typename T>
concept IsCalculatorInputWithoutOperators = IsCalculatorInput<T> && !std::same_as<T, CalculatorOperators>;

class Calculator
{
public:
    template <IsCalculatorInputWithoutOperators T1, IsCalculatorInputWithoutOperators T2>
    std::common_type_t<T1, T2> calculate(T1 leftOperand, CalculatorOperators op, T2 rightOperand)
    {
        switch(op)
        {
            case CalculatorOperators::OPERATOR_ADDITION:        return leftOperand + rightOperand;
            case CalculatorOperators::OPERATOR_SUBSTRACTION:    return leftOperand - rightOperand;
            case CalculatorOperators::OPERATOR_MULTIPLICATION:  return leftOperand * rightOperand;
            case CalculatorOperators::OPRATOR_DIVISION:         return leftOperand / rightOperand;
            default:                                            return 0;
        }
    }
};

std::istream& operator>>(std::istream& is, CalculatorOperators& op);

#endif // CALCULATOR_H