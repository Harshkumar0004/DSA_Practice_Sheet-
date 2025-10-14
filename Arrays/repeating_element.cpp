#include <iostream>
#include <vector>
using namespace std;


void findRepeatingElements(int array[], int size) {
    int duplicateCount = 0;            // counter for duplicates found
    vector<int> duplicates;            //  array to store duplicates

    // compare each element with all subsequent elements
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] == array[j]) // if duplicate found
                duplicates.push_back(array[i]); // store it
        }
    }

    // print the repeating elements
    cout << "The repeating elements are: ";
    for (int i = 0; i < duplicates.size(); i++) 
        
        if (i == 0 || duplicates[i] != duplicates[i - 1])
            cout << duplicates[i] << " ";
    cout << endl;
}

int main() {
    int numbers[] = {1, 1, 2, 3, 4, 4, 5, 2}; 
    int size = sizeof(numbers) / sizeof(numbers[0]); 
    findRepeatingElements(numbers, size);

    return 0;
}
