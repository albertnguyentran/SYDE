//SYDE 121
//Albert Nguyen-Tran
//21006431
//Dec 7 2022

#include <cstring>
#include <iostream>
using namespace std;

struct Node {
   string c;
   struct Node *next;
};

struct Node* top = NULL;

void pop() {
    if(top==NULL) {
        cout << "Ending" << endl;
    }
    else {
        cout<< top->c <<endl;
        top = top->next;
    }
}

void push(char value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->c = value;
    newNode->next = top;
    top = newNode;
}


int main() {
    int n;
    cout<<"Enter the length of the word: "<< "\n";
    cin>>n;
    cout<<"Now enter each letter individually, one by one" << "\n";

    char c;
    for(int i=0; i<n; i++){
        cin>>c;
        push(c);
    }
    
    cout << "\n";
    cout<< "Reversed word is: " << "\n";

    for(int j=0; j<n; j++){
        pop();
    }
    
    return 0;
}