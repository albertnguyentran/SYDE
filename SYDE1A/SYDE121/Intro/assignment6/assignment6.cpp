//SYDE 121 Assignment 6
//Albert Nguyen-Tran
//21006431
//Nov 11, 2022
#include <iostream>
#include <string>

using namespace std;

class Book {
    public:
        //Default constructor that sets all three attributes to "n/a"
        Book( );
        //Constructor where all three attributes are inputted
        Book(string title, string author, string date);
        //Constructor where only the title and authors are provided
        Book(string title, string author);
        //Constructor where only the title is provided
        Book(string title);
        //Display constructor
        void display( );

    private:
        string title;
        string author;
        string date
};

int main(){
    //Example
    //Book book("test_title", "test_author"), will set the title to test_title, author to test_author and date to n/a
    Book book("a", "b", "c");
    return 0;
}

//Default constructor, set all to n/a
Book::Book( ){
    title = "n/a";
    author = "n/a";
    date = "n/a";
}

//Constructor when all three are inputted
Book::Book(string t, string a, string d){
    title = t;
    author = a;
    date = d;
}

//Constructor when only title and author are inputted
Book::Book(string t, string a){
    title = t;
    author = a;
    date = "n/a";
}

//Constructor when only title is inputted
Book::Book(string t){
    title = t;
    author = "n/a";
    date = "n/a";
}

//Display constructor
void Book::display(){
    cout << "Title: " << title << "\n";
    cout << "Author: " << author << "\n";
    cout << "Date: " << date << "\n";
}



