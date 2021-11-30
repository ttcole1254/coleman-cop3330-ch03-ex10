/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Tyler Coleman
 */

/*
* Write a program that takes an operation followed by two operands and outputs the result. For example:
* + 100 3.14
* * 4 5
* Read the operation into a string called operation and use an if-statement to figure out which operation the user wants,
* for example, if (operation=="+"). Read the operands into variables of type double. Implement this for operations
* called +, –, *, /, plus, minus, mul, and div with their obvious meanings.
*/

#include "std_lib_facilities.h"	

int main()
{
    try {
        // Init vars
        string op;
        double var1 = 0;
        double var2 = 0;
        cout << "Enter an operation (+, -, *, /, plus, minus, mul, or div) and two operands, all separated by one space: ";
        // Set while loop to match the expected input order
        while (cin >> op >> var1 >> var2) {
            //Reset answer between runs
            double ans = 0;
            if (op == "+" || op == "plus") ans = var1 + var2;
            else if (op == "-" || op == "minus") ans = var1 - var2;
            else if (op == "*" || op == "mul") ans = var1 * var2;
            else if (op == "/" || op == "div") {
                if (var2 == 0) error("Error, cannot divide by 0, please try again.");
                ans = var1 / var2;
            }
            else error("Error, please use a valid operator (+, -, *, /, plus, minus, mul, or div)");
            cout << "Answer: " << var1 << " " << op << " " << var2 << " = " << ans << "\n";
            cout << "Enter an operation (+, -, *, /, plus, minus, mul, or div) and two operands, all separated by one space: ";
        }
        cout << "Something is wrong with the input, please try again.";
    } catch (runtime_error e) {
        cout << e.what() << "\n";
    }
}