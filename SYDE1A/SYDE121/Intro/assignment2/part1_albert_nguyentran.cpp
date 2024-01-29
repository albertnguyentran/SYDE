//SYDE 121 - Assignment 2 Albert Nguyen-Tran Sep 27, 2022
//Part 1
#include <iostream>
#include <string>

using namespace std;

int main() {

    //Ask the user for a number n
    // Double is float
    // Int is by default mapped to 32bits (4 bytes)
    // Long maps top int64, 64 bits (8 bytes)
    double n;
    double guess, last_guess, r;
    cout << "Enter a number:\n";
    cin >> n;

    //Babylonian fomrula
    guess = n/2 + 1;
    last_guess = guess;
    r = n/guess;
    guess = (guess+r)/2;

    //While loop until within 0.05%
    while (((last_guess - guess) / guess) > 0.05) {
        last_guess = guess;
        r = n/guess;
        guess = (guess+r)/2;

        cout << "\nLAST GUESS: " << last_guess <<  " GUESS: " << guess; 
    }

    //Print final guess
    cout << "\n\n";
    cout << "Based on the square root: " << n << " the final guess is: " << guess << " when the last guess is: " << last_guess;
}