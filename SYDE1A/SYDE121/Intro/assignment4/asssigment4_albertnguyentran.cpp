//SYDE 121 Assignment 4 Oct 18, 2022
//Albert Nguyen-Tran
//21006431
#include <iostream>
#include <string>
using namespace std;

void get_size(int& size);
void get_choice(int& choice);
void draw_triangle(int size, string c);
void draw_diamond(int size, string c);
void draw_upsideDownTriangle(int size, string c);
void draw_sideWayTriangle(int size, string c);
string space_generator(int num);

int main()
{
    int size;
    int choice;
    string c = "*";

    get_size(size);

    for (int i = 0; i < size - 1; i++){
        c += '*';
    }
    size = size / 2;

    get_choice(choice);

    if (choice == 1) {
        draw_triangle(size, c);
    } else if (choice == 2) {
        draw_diamond(size, c);
    } else if (choice == 3) {
        draw_upsideDownTriangle(size, c);
    } else if (choice == 4) {
        draw_sideWayTriangle(size, c);
    } else {
        cout << "\nInvalid number selected please try again";
    }
    return 0;
}

void get_size(int& size)
{
    cout << "Input the size of the shape (line with longest amount of stars)\n";
    cin >> size;
    return;
}

void get_choice(int& choice)
{  
    cout << "\nPress 1 for triangle, 2 for diamond, 3 for upside down triangle and 4 for side ways triangle\n";
    cin >> choice;
}

void draw_triangle(int size, string c)
{
    for (int i = size; i > -1; i -= 1){
        std::string space(i, ' ');
        cout << space << c.substr(i, (c.length() - i) - i) << space << "\n";
    }
}


void draw_diamond(int size, string c)
{
    for (int i = size; i > -1; i -= 1){
        std::string space(i, ' ');
        cout << space << c.substr(i, (c.length() - i) - i) << space << "\n";
    }

    for (int i = 1; i < size + 1; i++){
        std::string space(i, ' ');
        cout << space << c.substr(i, (c.length() - i) - i) << space << "\n";
    }

}

void draw_upsideDownTriangle(int size, string c)
{

    for (int i = 0; i < size + 1; i++){
        std::string space(i, ' ');
        cout << space << c.substr(i, (c.length() - i) - i) << space << "\n";
    }
}

void draw_sideWayTriangle(int size, string c)
{

    for (int i = 0; i <= (size * 2 + 1); i += 1){
        cout << c.substr(0, i) << "\n";
    }

    for (int i = size * 2; i > -1; i -= 1){
        cout << c.substr(0, i) << "\n";
    }

}
