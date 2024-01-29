//SYDE 121 - Assignment 2 Albert Nguyen-Tran Sep 27, 2022
//Part 2

#include <iostream>
#include <string>

using namespace std;

int main(){

    //Create variables
    int sum1, sum2;

    sum1 = 0;

    //Method 1: Using a for loop

    for (int i = 0; i <= 100; i++){
        if (i % 2 != 0) {
            sum1 += i;
        }
    }

    //Output answer using first method
    cout << "Sum using first method: " << sum1;

    //Method 2: Using formula
    //n = # of integers to be added, in this case its the amount of odd numbers from 1-100 which is 50
    //a = starting number which is 1
    //d = difference between numbers which is 2
    //sum formula = (n/2) * (2 * a + (n - 1) *  d)

    //Output answer using second method
    sum2 = (50/2) * (2 * 1 + (50 - 1) * 2);
    cout << "\n\nSum using second method: " << sum2;
}