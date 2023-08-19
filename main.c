//####################################################################################################
//# Project: Simple Calculator
//# Author: Jose Rey
//# Date Created: 2023-19-03
//# Description: Simple Calculator using C
//####################################################################################################
//# Github : https://github.com/joserey-alfante
//####################################################################################################
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Function to perform arithmetic operations
double performOperation(double num1, char operator, double num2) {
    switch (operator) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num2 != 0 ? num1 / num2 : (printf("Error: Division by zero.\n"), 0);
        default: printf("Invalid operator: %c\n", operator); return 0;
    }
}

int main() {
    char input[100];
    printf("Enter numbers and operators: ");
    fgets(input, sizeof(input), stdin);

    double result = 0, currentNumber = 0;
    char currentOperator = '+';
    bool readingNumber = true;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i]) || input[i] == '.') {
            currentNumber = readingNumber ? currentNumber * 10 + (input[i] - '0') : (printf("Invalid input.\n"), 1);
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            result = performOperation(result, currentOperator, currentNumber);
            currentOperator = input[i];
            currentNumber = 0;
            readingNumber = true;
        } else if (isspace(input[i])) {
            continue;
        } else {
            printf("Invalid input.\n");
            return 1;
        }
    }

    result = performOperation(result, currentOperator, currentNumber);

    printf("Output: %.2lf\n", result);

    return 0;
}
