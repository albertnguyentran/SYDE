/* A grocery store sells many cases of soft drink everyday. In each case, there are 12
bottles and the store profits 20 cents per bottle. We want to compute the profit that the
store has every day of selling soft drink. We also want to know the profit for selling
soft drink in a year. Assume a year is 365 days.
1) Problem Definition:
Compute the profit that a store has in one day for selling soft drink?
Compute the profit that a store has in one year for selling soft drink?
This program is so computationally extensive, that we want to write a C++ program to
solve it on a computer! At least we will assume it is for now. */

#include <iostream>
using namespace std;

int main() {
    // profit per case = 12 * 0.2 = $2.4

    float cases;
    float profit;

    cin >> cases;

    profit = cases*2.4;

    cout << profit;

}