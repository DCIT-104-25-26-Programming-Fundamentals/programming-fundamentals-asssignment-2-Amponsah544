// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

double find_sum(const double arr[], int n) {
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

double find_avg(const double arr[], int n) {
    double total = find_sum(arr, n);
    return total / n;
}

double find_max(const double arr[], int n) {
    double max_num = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }
    return max_num;
}

double find_min(const double arr[], int n) {
    double min_num = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_num) {
            min_num = arr[i];
        }
    }
    return min_num;
}

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: Please enter a positive number." << endl;
        return 0;
    }

    if (n > MAX_SIZE) {
        cout << "Error: Maximum allowed capacity is " << MAX_SIZE << "." << endl;
        return 0;
    }

    double arr[MAX_SIZE];

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> arr[i];
    }

    double sum_val = find_sum(arr, n);
    double avg_val = find_avg(arr, n);
    double max_val = find_max(arr, n);
    double min_val = find_min(arr, n);

    cout << endl;
    cout << "Results:" << endl;
    cout << "Sum:     " << sum_val << endl;
    cout << "Average: " << avg_val << endl;
    cout << "Maximum: " << max_val << endl;
    cout << "Minimum: " << min_val << endl;

    return 0;
}