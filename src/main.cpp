#include "Calculator.h"
#include "Utilites.h"

#include <algorithm>

int main()
{
    Calculator calculator;
    while(true)
    {
        double leftOperand;
        bool resultLeft{getInputItem("Enter a number for left operand: ", leftOperand)};

        Calculator::Operators op;
        bool resultOperator{getInputItem("Enter an operator (+, -, *, /): ", op)};

        double rightOperand;
        bool resultRight{getInputItem("Enter a number for right operand: ", rightOperand)};

        if(!(resultLeft && resultOperator && resultRight))
        {
            std::string msg{"Error input!\nDo you want to try again? (y/n): "};
            if(!askToContinue(msg)) return 0;

            system("cls");
            continue;
        }

        std::cout << "Result: " << calculator.calculate(leftOperand, op, rightOperand) << std::endl;

        std::string msg{"Do you want to continue? (y/n): "};
        if(!askToContinue(msg)) return 0;

        system("cls");
    }
}