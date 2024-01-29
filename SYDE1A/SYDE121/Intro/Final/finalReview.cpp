#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

void writeVertical(int n);

struct bank {
    string name;
    double balance;
    int age;
};

bank initialize_person(){
    bank person;
    cin >> person.name;
    cin >> person.balance;
    cin >> person.age;
    return person;
}

struct EmployeeRecord {
    double wage_rate;
    int accrued_vacation;
    char status;
};

/*void readShoeRecord(ShoeType& newShoe);
void readShoeRecord(ShoeType& newShoe) {
    string shoe;
    double price;
    cin >> shoe;
    newShoe.style = shoe;
    cin >> price;
    newShoe.price = price;
}*/

/*ShoeType discount(ShoeType oldRecord) {
    ShoeType newShoe;
    newShoe.style = oldRecord.style;
    newShoe.price = newShoe.price - newShoe.price*0.1;
    return newShoe;
}*/

/*struct StockRecord {
    ShoeType shoeInfo;
    Data = arrivalData;

};*/

//15 answer = setPrice, double aPrice and aProfit and .getPrice() because they are public. 
//16. Now all answers are valid after they become public except for hyundai == jaguar because you cannot use == with classes
//10. 23/24 Rewrite constructors as DayOfYear(int month, int day) and DayOfYear(); which overloads the function name DayOfYear

//11.4 friend void subtraction( Money amount1, Money amount2)
//void subtraction(Money amount1, Money amount2 ) 
//Money temp; temp.allcents = amount1.allcents - amount1.allcents; return temp

//11.5 void output(cout)
// void output

//13.1, 13.2, 13.5, 13.7, 13.8
//13.1 sally sally 18 18
//13.2 head->next = sally
//13.3delete head, for 2d array delete[] m[i] (each row) and delete[] m (the entire array)
//13.5 struct Node {
// int data;
// Node *link;
// typdef Node* NodePtr};
//13.7 p1 = p1->next;
//13.8
//discard = p2->next;
//p2->next = discard->next
//Removes the node in the middle (discard)
//14.1 n = 3 hip n = 2 hip n = 1 hurray

//14.2 void recursive(int n) {
//  if (n==0) {
 //   cout << "";
// else { cout << "*"; recursive(n-1)}}

//14.3 void recursive(int n) {
// if (n<10) { cout << n}
// else {. recursive(n/10)}
// cout << (n%10);
//}
//14.4 void recursive(int n) {
//  if (n==1) { cout << 1;}
//  else {
//      recursive(n-1)
//      cout << n;
//}
//14.4 if (n>=1) { Recursive(n-1)) cout << n}
//14.5 if (n>=1) cout << n Recursive(n-1)
//15.8

class Albert {
    public:
        //Default contructor
        Albert();
        Albert(string name);
        Albert(string name, int balance);
        string name;
    private:
        int balance;
};
int main() {
    
}
Albert::Albert(){
    name = "Albert";
    balance = 69;
}

void writeVertical(int n) {
    if (n<10) {
        cout << n << endl;
    } else {
        //Division (rounds down)
        //450/10 = 45 then 4
        writeVertical(n / 10);
        //Remainder of integer division
        //Print 0 then 5 then 4
        cout << (n % 10) << endl;
    }
}

