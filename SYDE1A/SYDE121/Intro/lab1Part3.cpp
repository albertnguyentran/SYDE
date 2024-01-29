#include <iostream>
#include <string>

using namespace std;

int main(){

    string onOff;
    cout << "Is the light on? Type on or off.\n";
    cin >>  onOff;

    if (onOff == "on") {
        cout << "turn it off";
    } else if (onOff == "off"){
        cout << "good job kid";
    } else {
        cout << "please type on or off";
    }
}