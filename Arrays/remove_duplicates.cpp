#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& arr) {
    // i points to the last unique element found
    int i = 0;

    // j traverses the array to find unique elements
    for (int j = 1; j < arr.size(); j++) {
        if (arr[j] != arr[i]) {  // found a new unique element
            i++;                 // move i to next position
            arr[i] = arr[j];     // update position i with new unique element
        }
    }

    // i + 1 is the new length of the array with unique elements
    return i + 1;
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5};

    int newLength = removeDuplicates(arr);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nNew length: " << newLength << endl;

    return 0;
}
