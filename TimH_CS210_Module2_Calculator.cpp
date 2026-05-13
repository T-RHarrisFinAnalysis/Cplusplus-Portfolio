/*
Calculator.cpp
Date: May 14th, 2026
Author: Tim Harris (Improved Version)

Features:
- Handles +, -, *, /
- Prevents division by zero
- Validates user input
- Uses double for decimal precision
- Loops until user chooses to exit
*/

#include <iostream>
#include <cctype>   // for toupper
using namespace std;

int main() {
    double op1, op2;
    char operation;
    char answer = 'Y';

    while (toupper(answer) == 'Y') {
        cout << "Enter expression (e.g., 2 + 2): ";

        // Input validation
        if (!(cin >> op1 >> operation >> op2)) {
            cout << "Invalid input format. Please try again.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        // Perform calculation using switch
        switch (operation) {
        case '+':
            cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
            break;
        case '-':
            cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
            break;
        case '*':
            cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
            break;
        case '/':
            if (op2 == 0) {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            else {
                cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
            }
            break;
        default:
            cout << "Invalid operator entered." << endl;
        }

        // Clear any leftover input
        cin.ignore(1000, '\n');

        // Ask user to continue
        cout << "Do you wish to evaluate another expression? (Y/N): ";
        cin >> answer;
        answer = toupper(answer);
    }

    cout << "Program Finished." << endl;
    return 0;
}
