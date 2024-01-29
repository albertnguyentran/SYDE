#include <iostream>
#include <string>
using namespace std;

int main() {
    enum Month{JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, A};

    int my_birthday_month = 11;
    if (my_birthday_month == A) {
        cout << "My birthday is in December.";
    } else {
        cout << "My birthday is NOT in December."; //PRINTS THIS, only == A when int = 12
    }
}

