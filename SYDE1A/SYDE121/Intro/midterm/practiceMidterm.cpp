#include <iostream>
using namespace std;

void question1(){
    double n, guess, new_guess;
    cout << "Give a number" << endl;
    cin >> n;
    cout << "Give a guess of its square root";
    cin >> guess;

    new_guess = guess - 0.5;

    while (guess-new_guess > 0.00001) {
        guess = new_guess;
        new_guess = ((n/guess) + guess)/2;
        cout << n << endl;
        cout << guess << endl;
        cout << new_guess << endl;
    }

    return;
}

void question2(){
    /*#include <iostream>
    using namespace std;
    int volts;                  global int
    long int resistance;        global long int
    double current;             global double
    int main()
    {
    int power;                  local int
    double factor,              local double
    time;                       local time
    . .
    return 0;
    }
    double roi(int mat1, int mat2)
    {
    int count;                  #local int
    double weight;              #local double
    .
    .
    return weight;
    }
    Functionsint step(double first, double last)
    {
    int hours;                  #local int
    double fracpart;            #local double
    .
    .
    return 10 * hours;
    }
    Double func2(double first, double last)
    int a, b, c, o, p;          #local int 
    double r;                   #local double
    double s, t, x;             #local double
    .
    .
    return s * t;
    }*/
    return;
}

void question3(){

}
int main(){
    int question;
    bool run;
    run = true;
    cout << "Which question would you like?" << endl;
    cin >> question;
    
    while (run) {
        if (question == 1) {
            question1();
            run = false;
        } else if (question == 2) {
            question2();
            run = false;
        } else if (question == 3) {
            question3();
            run = false;
        } else {
            cout << "Invalid number try again\n";
            cout << "Which question would you like?" << endl;
            cin >> question;
        }
    }
}