//SYDE 121 Assignment 7
//Albert Nguyen-Tran
//21006431
//Nov 18, 2022
#include <iostream>
#include <string>

using namespace std;

class Rational {
    public:
        //Initialize variables, numerator as the first and denominator as the second
        int numerator;
        int denominator;
        
        //Default constructor
        Rational();
        //Constructor with one variable, sets numerator to numerator and denominator to 1 (for example 6 is equal to 6/1)
        Rational(int numerator);
        //Constructor where both varibles are inputted
        Rational(int numerator, int denominator);
        //Add, subtract, multiply and divide methods (performs operation on existing object with new object, for example a.add(b) adds b to a)
        void add(Rational r2);
        void subtract(Rational r2);
        void multiply(Rational r2);
        void divide(Rational r2);
        //Display constructor
        void display( );
};

int main(){
    int n1, d1, n2, d2;
    cout << "Input the numerator of the first fraction \n";
    cin >> n1;
    cout << "Input the denominator of the first fraction, put a 1 if it is an integer \n";
    cin >> d1;
    cout << "Input the numerator of the second fraction \n";
    cin >> n2;
    cout << "Input the denominator of the second fraction, put a 1 if it is an integer \n";
    cin >> d2;

    Rational Fraction_One(n1, d1);
    Rational Fraction_Two(n2, d2);

    Fraction_One.add(Fraction_Two);
    Fraction_One.subtract(Fraction_Two);
    Fraction_One.multiply(Fraction_Two);
    Fraction_One.divide(Fraction_Two);

    return 0;
}


//Default constructor, set numerator to n and denominator to 1 (for example 6 is equal to 6/1)
Rational::Rational(int n){
    numerator = n;
    denominator = 1;
}

//Constructor when both numerator and denomiantor are inputted
Rational::Rational(int n, int d){
    numerator = n;
    denominator = d;
}

//Add method: Formula given is a/b + c/d = (a*d + b*c) / (b*d)
void Rational::add(Rational r2){
    cout << "\nAddtion: \n";
    cout << "Numerator: " << (numerator*r2.denominator + denominator*r2.numerator) << " \n";
    cout << "Denominator: " << (denominator*r2.denominator) << " \n";
}

//Subtract method: Formula given is a/b - c/d = (a*d - b*c) / (b*d)
void Rational::subtract(Rational r2){
    cout << "\nSubtraction: \n";
    cout << "Numerator: " << (numerator*r2.denominator - denominator*r2.numerator) << " \n";
    cout << "Denominator: " << (denominator*r2.denominator) << " \n";
}

//Multiply method: Formula given is (a/b) * (c/d) = (a*c) / (b*d)
void Rational::multiply(Rational r2){
    cout << "\nMultiplication: \n";
    cout << "Numerator: " << (numerator*r2.numerator) << " \n";
    cout << "Denominator: " << (denominator*r2.denominator) << " \n";
}

//Divide method: Formula given is (a/b) / (c/d) = (a*d) / (c*b)
void Rational::divide(Rational r2){
    cout << "\nDivision: \n";
    cout << "Numerator: " << (numerator*r2.denominator) << " \n";
    cout << "Denominator: " << (r2.numerator*denominator) << " \n";
}

//Display constructor
void Rational::display(){
    cout << "Numerator: \n" << numerator << "\n";
    cout << "Denominator: " << denominator << "\n";
}



