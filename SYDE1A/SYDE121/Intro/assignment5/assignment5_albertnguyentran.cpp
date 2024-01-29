#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream in_stream;
    ofstream out_stream;
    in_stream.open("input5.txt");

    if (in_stream.fail()) {
        cout << "Input file opening failed, exiting";
        exit(1);
    }
    out_stream.open("output5.txt");
    if (out_stream.fail()) {
        cout << "Output file opening failed, exiting";
        exit(1);
    }
    int first, second, third, fourth, fifth, sixth, seventh, eigth;
    in_stream >> first >> second >> third >> fourth >> fifth >> sixth >> seventh >> eigth;
    int arr[8] = {first, second, third, fourth, fifth, sixth, seventh, eigth};
    cout << left << setw(6) << setfill(' ') << "x";
    cout << left << setw(6) << setfill(' ') << "x^2";
    cout << left << setw(6) << setfill(' ') << "Current Sum\n";
    cout << left << setw(6) << setfill(' ') << "===";
    cout << left << setw(6) << setfill(' ') << "===";
    cout << left << setw(6) << setfill(' ') << "===========\n";

    out_stream << left << setw(6) << setfill(' ') << "x";
    out_stream << left << setw(6) << setfill(' ') << "x^2";
    out_stream << left << setw(6) << setfill(' ') << "Current Sum\n";
    out_stream << left << setw(6) << setfill(' ') << "===";
    out_stream << left << setw(6) << setfill(' ') << "===";
    out_stream << left << setw(6) << setfill(' ') << "===========\n";

    int sum;
    sum = 0;

    for (int i = 0; i < 8; i++) {
        sum += arr[i];
        cout << left << setw(6) << setfill(' ') << arr[i];
        cout << left << setw(6) << setfill(' ') << arr[i]*arr[i];
        cout << left << setw(6) << setfill(' ') << sum;
        cout << "\n";

        out_stream << left << setw(6) << setfill(' ') << arr[i];
        out_stream << left << setw(6) << setfill(' ') << arr[i]*arr[i];
        out_stream << left << setw(6) << setfill(' ') << sum;
        out_stream << "\n";
    }

    int average;
    average = (sum/8);
    
    cout << "\n    The average of these 8 numbers is: " << average;
    out_stream << "\n    The average of these 8 numbers is: " << average;
    out_stream.close();

}