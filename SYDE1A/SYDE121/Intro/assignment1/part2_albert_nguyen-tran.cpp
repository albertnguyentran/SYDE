//Assignment #1 Part 1
//STUDENT NUMBER: 21006431
//NAME: Albert Nguyen-Tran 
//DATE: Sept 18, 2022

#include <iostream>
#include <string>

using namespace std;

int main(){
    //Initialize Farenheit and Celsius (centigrade) variables
    float f;
    float c;

    //Ask for Farenheit
    cout << "What Farenheit?\n";
    cin >> f;

    //Calculate Celsius
    c = (f - 32)/(1.8);

    //Output the Farenheit to Celsius conversion
    cout << "\n" << f << " Farenheit is equal to " << c << " Celsius";
    
}
