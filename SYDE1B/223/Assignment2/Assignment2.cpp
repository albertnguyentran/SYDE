#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

struct Classmate {
    Classmate* left;
    Classmate* right;

    struct ShoeData {
        double shoeSize;
        string firstName;

        ShoeData(double size, const string& name)
            : shoeSize(size), firstName(name) {}
    };
    vector<ShoeData> data;

    Classmate(double sSize)
        : left(nullptr), right(nullptr) {}
};

// This function inserts all the classmates into a bst
void insertNode(Classmate* &root, const string& firstName, double shoeSize) {

    // Base case: if the bst is empty create the root node
    // Recursive cases: because we want to create a bst, traverse the left if less than and right if greater than and add classmates with the same shoe size
    if (root == nullptr) {
        root = new Classmate(shoeSize);
        root->data.push_back(Classmate::ShoeData(shoeSize, firstName));
        return;
    }

    if (shoeSize < root->data[0].shoeSize) {
        insertNode(root->left, firstName, shoeSize);
    } else if (shoeSize > root->data[0].shoeSize) {
        insertNode(root->right, firstName, shoeSize);
    } else {
        root->data.push_back(Classmate::ShoeData(shoeSize, firstName));
    }
}

// This function deallocates the memory of the BST
void deallocateBST(Classmate* root) {
    if (root == nullptr) {
        return;
    }

    deallocateBST(root->left);
    deallocateBST(root->right);

    delete root;
}

// This function traverses the bst in order and reports the names of people who have shared shoe sizes
void traverseInOrder_shared(Classmate* root) {
    if (root == nullptr) {
        return;
    }

    traverseInOrder_shared(root->left);

    if (root->data.size() > 1) {
        cout << "Shoe Size: " << fixed << setprecision(2) << root->data[0].shoeSize << ", Names: ";
        for (size_t i = 0; i < root->data.size(); ++i) {
            cout << root->data[i].firstName;
            if (i != root->data.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    traverseInOrder_shared(root->right);
}

// This function traverses the bst in order and removes the nodes with more than one name in its vector
void removeNames_shared(Classmate* root) {
    if (root == nullptr) {
        return;
    }

    removeNames_shared(root->left);

    if (root->data.size() > 1) {
        root->data.clear();
    }

    removeNames_shared(root->right);
}

// This function traverses the bst in order and reports the names of people who unique shoe sizes since we just deleted the shared ones
void traverseInOrder_unique(Classmate* root) {
    if (root == nullptr) {
        return;
    }

    traverseInOrder_unique(root->left);

    if (!root->data.empty()) {
        cout << "Shoe Size: " << fixed << setprecision(2) << root->data[0].shoeSize << ", Name: " << root->data[0].firstName << endl;
    }

    traverseInOrder_unique(root->right);
}


int main() {
    // Part 1: reading data from the text file
    ifstream inputFile("data.txt");
    if (!inputFile.is_open()) {
        cout << "Cannot open the input file" << endl;
        return 1;
    }

    // Part 2: Storing the data into an array/vector
    vector<Classmate> classmates;
    string firstName;
    double shoeSize;

    while (inputFile >> firstName >> shoeSize) {
        classmates.push_back(Classmate(shoeSize));
        classmates.back().data.push_back(Classmate::ShoeData(shoeSize, firstName));
    }

    inputFile.close();


    // Part 3: Making a BST from the array
    Classmate* root = nullptr;

    for (size_t i = 0; i < classmates.size(); ++i) {
        insertNode(root, classmates[i].data[0].firstName, classmates[i].data[0].shoeSize);
    }


    // Part 4: Idenify the names of people who have the same shoe size
    cout << "Names of people who have Shared Sizes:" << endl;
    traverseInOrder_shared(root);

    // Part 5: Remove the names from the tree
    removeNames_shared(root);

    // Part 6: Identify the names in ascending shoe size order of people with unique shoe sizes
    cout << "Names of people who have Unique Sizes:" << endl;
    traverseInOrder_unique(root);

    // Deallocate memory
    deallocateBST(root);

    return 0;
}
