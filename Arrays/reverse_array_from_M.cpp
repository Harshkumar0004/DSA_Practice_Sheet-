#include <iostream>
#include <vector>
using namespace std;

void swapelement(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void reverseArray(vector<int> &arr, int m) {
    // set left pointer to the element just after index m
    int left = m + 1;
    
    // set right pointer to the last element of the array
    int right = arr.size() - 1;

    // continue swapping until both pointers meet in the middle
    while (left < right) {
        // swap the elements at left and right positions
        swapelement(arr[left], arr[right]);

        // move pointers closer towards the center
        left++;
        right--;
    }     	
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int m = 3; // reverse from index 4 to end (indices after m)

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    reverseArray(arr, m);

    cout << "Array after reversing elements after index " << m << ": ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
