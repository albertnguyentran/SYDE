#include <iostream>
#include <string>
using namespace std;

int main(){
    char text[500];
    cin >> text;
    char *ptr;
    int count;

    for (ptr = text; *ptr != '\0'; ptr++){
        count += 1;
    }

    cout << count;
}