//SYDE 121 - Assignment 2 Albert Nguyen-Tran Sep 27, 2022
//Part 3

#include <iostream>
#include <string>

using namespace std;

int main() {

    int a, b, sum;

    //Ask the user to input two non-zero positive integers
    cout << "Enter a positive non-zero integer a: ";
    cin >> a;

    cout << "\n\nEnter a positive non-zero integer b: ";
    cin >> b;

    sum = a + b;

    //Print sum if both values are even
    if (a % 2 == 0 && b % 2 == 0) {
        cout << "\n\nBoth a and b are even, therefore print the sum: ";
        cout << "\nSum = " << sum;
    }

    //Print first number if only one value is even
    else if (a % 2 == 0 || b % 2 == 0) {
        cout << "\nOnly one of a and b are even, therefore print the first number: ";
        cout << "\nFirst number = " << a;

    //Print the second number if none are even
    } else {
        cout << "\nNeither a or b are even, therefore print the second number: ";
        cout << "\nSecond number = " << b;
    }

}