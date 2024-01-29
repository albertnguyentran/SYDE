#include <iostream>
#include <string>
using namespace std;

int strLen(char* str, int length)
{
       if (*str == '\0')// base case for reaching last element
           return length;
       else
           return strLen(1 + str, length+1);
}

int main() {
    char str[] = "abcdef";
    int ans;
    ans = strLen(str, 0);
    cout << ans;
};