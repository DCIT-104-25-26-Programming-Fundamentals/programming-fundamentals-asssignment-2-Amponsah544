// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

void printFibonacciTerms() {
    int count;
    cout << "How many terms? ";
    
    if (!(cin >> count) || count <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error: Please enter a positive integer." << endl;
        return;
    }

    cout << "Fibonacci sequence: ";

    long long first = 0;
    long long second = 1;

    for (int i = 1; i <= count; i++) {
        if (i == 1) {
            cout << first << " ";
            continue;
        }
        if (i == 2) {
            cout << second << " ";
            continue;
        }

        long long nextTerm = first + second;
        cout << nextTerm << " ";

        first = second;
        second = nextTerm;
    }
    cout << endl;
}

void checkFibonacciNumber() {
    long long number;
    cout << "Enter a number to check: ";

    if (!(cin >> number) || number < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error: Please enter a non-negative integer." << endl;
        return;
    }

    long long first = 0;
    long long second = 1;

    if (number == 0 || number == 1) {
        cout << number << " is a Fibonacci number." << endl;
        return;
    }

    long long nextTerm = first + second;
    while (nextTerm < number) {
        first = second;
        second = nextTerm;
        nextTerm = first + second;
    }

    if (nextTerm == number) {
        cout << number << " is a Fibonacci number." << endl;
    } else {
        cout << number << " is NOT a Fibonacci number." << endl;
    }
}

int main() {
    cout << "--- PART A ---" << endl;
    printFibonacciTerms();

    cout << endl;

    cout << "--- PART B ---" << endl;
    checkFibonacciNumber();

    return 0;
}