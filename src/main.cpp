#include "Calculator.h"
#include "Utilites.h"

int main()
{
    Calculator calculator;
    while(true)
    {
        double leftOperand;
        bool resultLeft{getInputItem("Enter a number for left operand: ", leftOperand)};

        CalculatorOperators op;
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

        double result{calculator.calculate(leftOperand, op, rightOperand)};

        if( result ==  std::numeric_limits<double>::infinity() || 
            result == -std::numeric_limits<double>::infinity() )
            std::cout << "Division by zero" << std::endl;
        else
            std::cout << "Result: " << result << std::endl;

        std::string msg{"Do you want to continue? (y/n): "};
        if(!askToContinue(msg)) return 0;

        system("cls");
    }
}