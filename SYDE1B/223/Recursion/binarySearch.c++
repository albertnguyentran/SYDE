#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int mid = (low + (high - low))/2;

    if (arr[mid] == target) {
        return mid;
    }

    else if (arr[mid] > target) {
        return binarySearch(arr, low, mid-1, target);
    };

    return binarySearch(arr, mid+1, high, target);
}
int main(){
    int arr[5];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    cout << arr[0];


    return 0;
};