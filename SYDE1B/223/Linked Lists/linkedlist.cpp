#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

typedef Node* NodePtr;

void headInsert(NodePtr& head, int number) {
    NodePtr t;

    t = new Node;

    t -> data = number;
    head -> next = t;
    head = t;
};

NodePtr search(NodePtr& search, int target) {
    while(search -> next != NULL) {

        if (search->data == target) {
            return search;
        }
    }

    return NULL;
};

int main(){

    // Setup basic linked list and add nodes to the tail
    Node *a;
    Node *t;
    Node *h;

    a = new Node;
    a -> data = 4;
    t = a;
    h = a;

    a = new Node;
    a -> data = 5;
    t -> next = a;
    t = a;

    a = new Node;
    a -> data = 6;
    a -> next = NULL;
    t -> next = a;
    t = a;

    cout << h->data << endl;

    while (h->next != NULL) {
        h = h->next;
        cout << h->data << endl;
    };


    //----------------------- Using Insert Function ------------------------

    NodePtr head;
    head -> data = NULL;

    headInsert(head, 4);
    headInsert(head, 5);
    headInsert(head, 6);
    headInsert(head, 7);

    cout << head->data << endl;

    while (head->next != NULL) {
        head = head->next;
        cout << head->data << endl;
    }



    // ----------------- Search algorithm -----------------

    NodePtr test;
    NodePtr test_answer;
    int target;

    // Look at search function
    test_answer = search(test, target);
    

};