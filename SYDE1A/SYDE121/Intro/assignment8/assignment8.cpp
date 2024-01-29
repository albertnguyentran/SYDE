//SYDE 121 Assignment 8
//Nov 25, 2022
//Albert Nguyen-Tran
//21006431
#include <iostream>
#include <string>
using namespace std;

class Data {
    public:
        void set_distance(int d);
        void set_times(int i, double t);
        void display();
        void statistics( );


   
    private:
        double time[5]; //array of time in second
        int distance; //distance in meter
        double min, max, average;
};

int main() {
    Data Runner;
    int distance;
    double one, two, three, four, five;

    //Ask runner for a distance
    cout << "What is the event distance: ";
    cin >> distance;

    //Ask runner for 5 best times
    cout << "\nNow enter five of your best times in that event";
    cout << "\nTime 1: ";
    cin >> one;
    cout << "\nTime 2: ";
    cin >> two;
    cout << "\nTime 3: ";
    cin >> three;
    cout << "\nTime 4: ";
    cin >> four;
    cout << "\nTime 5: ";
    cin >> five;

    //Set distance to the variable distance
    Runner.set_distance(distance);

    //Set all five times accordingly into the time array
    Runner.set_times(0, one);
    Runner.set_times(1, two);
    Runner.set_times(2, three);
    Runner.set_times(3, four);
    Runner.set_times(4, five);

    //Calculate statistics
    Runner.statistics();

    //Display all five times, following by the worst, the best and the average
    Runner.display();


}
void Data::set_distance(int d) {
    distance = d;
}

void Data::set_times(int i, double t) {
    time[i] = t;    
}

void Data::statistics(){
    double sum;
    sum = 0;
    min = time[0];
    max = time[0];

    for(int i = 0; i < 5; i++) {
        if (time[i] < min) {
            min = time[i];
        }
        if (time[i] > max) {
            max = time[i];
        }
        sum += time[i];
    }
    average = sum/5;
}

void Data::display() {
    cout << "Here is your best 5 times for \n";
    cout << distance << " meter \n";

    for(int i = 0; i < 5; i++) {
        cout << "Time " << i << " is: " << time[i] << endl;
    }

    cout << "Worst time is: " << min << endl;
    cout << "Best time is: " << max << endl;
    cout << "Average time is: " << average << endl;
}
