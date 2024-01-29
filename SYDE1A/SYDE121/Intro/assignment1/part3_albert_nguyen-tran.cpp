//Assignment #1 Part 3
//STUDENT NUMBER: 21006431
//NAME: Albert Nguyen-Tran 
//DATE: Sept 18, 2022

#include <iostream>
#include <string>

using namespace std;

int main(){

    //Initialize num variable
    float num;

    //Ask the user to input num
    cout << "One try\n\n\n";
    cout << "Please enter a positive number less than 10\n";
    cin >> num;

    //While the num is less than 5 or greater than 5, 
    //Give the user another try to input another number
    //If the number they input is greater or equal to 5 and less than 10, the while loop stops
    while (num < 5 || num > 10) {
        cout << "The number you entered is not in the range\n";
        cout << "Another try\n";

        cout << "\nPlease enter a positive number less than 10\n";
        cin >> num;
    }

    //Once out of the while loop, the user is told that the number they inputted is in the range
    cout << "The number you entered is in the range";
}
