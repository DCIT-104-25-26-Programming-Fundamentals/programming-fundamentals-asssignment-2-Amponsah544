// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void showMenu() {
    cout << endl;
    cout << "============================" << endl;
    cout << "      SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

double add_num(double f_num, double s_num) {
    return f_num + s_num;
}

double sub_num(double f_num, double s_num) {
    return f_num - s_num;
}

double mul_num(double f_num, double s_num) {
    return f_num * s_num;
}

void div_num(double f_num, double s_num) {
    if (s_num == 0) {
        cout << "Error: Cannot divide by zero." << endl;
    } else {
        double res = f_num / s_num;
        cout << "Result: " << f_num << " / " << s_num << " = " 
             << fixed << setprecision(2) << res << endl;
    }
}

void mod_num(int f_num, int s_num) {
    if (s_num == 0) {
        cout << "Error: Cannot divide by zero." << endl;
    } else {
        int res = f_num % s_num;
        cout << "Result: " << f_num << " % " << s_num << " = " << res << endl;
    }
}

double pow_num(double b_num, double e_num) {
    return pow(b_num, e_num);
}

int main() {
    int choice = 0;

    while (choice != 7) {
        showMenu();
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            double f_num, s_num;
            cout << "Enter first number : ";
            cin >> f_num;
            cout << "Enter second number: ";
            cin >> s_num;

            if (choice == 1) {
                double res = add_num(f_num, s_num);
                cout << "Result: " << f_num << " + " << s_num << " = " 
                     << fixed << setprecision(2) << res << endl;
            } 
            else if (choice == 2) {
                double res = sub_num(f_num, s_num);
                cout << "Result: " << f_num << " - " << s_num << " = " 
                     << fixed << setprecision(2) << res << endl;
            } 
            else if (choice == 3) {
                double res = mul_num(f_num, s_num);
                cout << "Result: " << f_num << " * " << s_num << " = " 
                     << fixed << setprecision(2) << res << endl;
            } 
            else if (choice == 4) {
                div_num(f_num, s_num);
            } 
            else if (choice == 5) {
                mod_num((int)f_num, (int)s_num);
            } 
            else if (choice == 6) {
                double res = pow_num(f_num, s_num);
                cout << "Result: " << f_num << " ^ " << s_num << " = " 
                     << fixed << setprecision(2) << res << endl;
            }
        } 
        else if (choice == 7) {
            cout << "Goodbye!" << endl;
        } 
        else {
            cout << "Error: Invalid choice. Please select a number between 1 and 7." << endl;
        }
    }

    return 0;
}