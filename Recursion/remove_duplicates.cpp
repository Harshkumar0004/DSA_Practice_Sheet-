#include <iostream>
#include <algorithm>  
using namespace std;

void removeDuplicates(int arr[], int n, int index = 0) {
    //if array has 0 or 1 element left
    if (index >= n - 1) {
        cout << arr[index] << " ";
        return;
    }

    // element not equal to next
    if (arr[index] != arr[index + 1]) {
        cout << arr[index] << " ";
    }
    removeDuplicates(arr, n, index + 1);
}

int main() {
    int arr[] = {1, 2, 2, 3, 3, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);
    cout << "Array after removing duplicates: ";
    removeDuplicates(arr, n);
    return 0;
}
