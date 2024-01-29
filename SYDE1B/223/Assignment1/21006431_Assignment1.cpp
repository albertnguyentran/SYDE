// Albert Nguyen-Tran
// 21006431
// SYDE 223 Assignment 1

#include <iostream>
using namespace std;

class CircularLinkedList {
    private:
        struct Node {
            int data;
            Node* next;

            Node(int value) : data(value), next(nullptr) {}
        };
        
        Node* head;
    
    public:
        CircularLinkedList() : head(nullptr) {}

        ~CircularLinkedList() {
            if (head == nullptr)
                return;

            Node* current = head->next;
            while (current != head) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            delete head;
            head = nullptr;
        };

        void insert(int value) {
            Node* new_node = new Node(value);

            if (head == nullptr) {
                head = new_node;
                head->next = head;

            } else {
                Node* current = head;

                while (current->next != head) {
                    current = current->next;
                }
                current->next = new_node;
                new_node->next = head;
            };
        };

        void deleteLast(int value) {
            // If there's nothing in linked list
            if (head == nullptr)
                return;
            
            // If head is the only node and it is also the target node
            if (head->data == value && head->next == head) {
                head = nullptr;
                return;
            };
    
            Node* prev = nullptr;
            Node* current = head;
            Node* lastOccurrencePrev = nullptr;
            Node* lastOccurrence = nullptr;

            // Find the last occurrence and its previous node
            do {
                if (current->data == value) {
                    lastOccurrencePrev = prev;
                    lastOccurrence = current;
                }
                prev = current;
                current = current->next;
            } while (current != head);

            // If there is 2 or more nodes and head is NOT the last occurrence
            if (lastOccurrencePrev != nullptr) {
                lastOccurrencePrev->next = lastOccurrence->next;
            } else {
                // If head is the last occurrence
                head = head->next;
                prev->next = head;
            }  
            
            delete lastOccurrence;
            };

        void display() const {
            if (head == nullptr) {
                cout << "Circular Linked List is empty";
                return;
            };

            cout << "Circular Linked List displayed in clockwise order is: ";

            Node* current = head;

            do {
                cout << current -> data << " ";
                current = current->next;
            } while (current != head);
            cout << endl;
        };

        int search(int value) const {
            if (head == nullptr)
                return -1;
            
            Node* current = head;

            int i = 0;

            do {
                if (current->data == value)
                    return i;
                i++;
                current = current->next;
            } while (current != head);

            return -1;
        };
};

int main() {

    // ----- Example use of CircularLinkedList class -----
    // Proffessor and TA said its good if I just give an example of all 4 methods of the class being used!

    CircularLinkedList A_CircularLinkedList;
    A_CircularLinkedList.insert(1);
    A_CircularLinkedList.insert(3);
    A_CircularLinkedList.insert(2);
    A_CircularLinkedList.insert(3);
    cout << endl << "-------------------------------------" << endl;
    A_CircularLinkedList.display();
    int i = A_CircularLinkedList.search(3);
    cout << "Index of first 3 is: " << i << endl;

    // Example Case 1:
    cout << endl << "----- Example Case 1: Delete Last 3 -----" << endl;
    A_CircularLinkedList.deleteLast(3);
    A_CircularLinkedList.display();

    // Example Case 2:
    cout << endl << "----- Example Case 2: Delete Head -----" << endl;
    A_CircularLinkedList.deleteLast(1);
    A_CircularLinkedList.display();

    // Example Case 3:
    cout << endl << "----- Example Case 3: Delete All values -----" << endl;
    A_CircularLinkedList.deleteLast(3);
    A_CircularLinkedList.deleteLast(2);
    A_CircularLinkedList.display();
    int j = A_CircularLinkedList.search(2);
    // I made it so when you try to search for an element that doesn't exist in the circular linked list, -1 is returned
    cout << endl << "Index of first 2 is: " << j << " which means there are no 2's in the list which is correct!" << endl;

    return 0;
}