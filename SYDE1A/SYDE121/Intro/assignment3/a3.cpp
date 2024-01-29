#include <iostream>
using namespace std;

double test(double v1);
double test2(double v1, double v2);

int main(){
    double a, b, c, d;
    cin >> a >> b;
    c = test(a);
    d = test2(a, b);
    cout << c << d;
};

double test(double v1)
{
    return v1 += 5;
};

double test2(double v1, double v2)
{
    return v1*v2;
};