#include <iostream>
#include <string>
using namespace std;

class Car {
    public:
        Car();
        Car(string name, string model, int year);
        void add(Car c2);
        void display();

    private:
        string name;
        string model;
        int year;
};

int main(){
    Car m8("bmw", "m8", 2022);
    Car m5("bmw", "m5", 2000);
    m8.display();
    m8.add(m5);
    m8.display();

};

Car::Car(){
    name = "";
    model = "";
    year = 0;
};

Car::Car(string n, string m, int y){
    name = n;
    model = m;
    year = y;
};

void Car::add(Car c2){
    year = year + c2.year;
}

void Car::display(){
    cout << "Name: " << name << "\n";
    cout << "Model: " << model << "\n";
    cout << "Year: " << year << "\n";
}