#include <iostream>
#include <vector>
#include<algorithm>
#include<string>

using namespace std;

// Linear search
int linearSearch(vector<int>& nums, int target) {
    // iterate through each element
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target)  // check if current element is target
            return i;           // return index if found
    }
    return -1;  // target not found
}

// Binary search (array must be sorted)
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // prevent overflow

        if (nums[mid] == target) {
            return mid;  // target found
        } 
        else if (nums[mid] < target) {
            left = mid + 1;  // search right half
        } 
        else {
            right = mid - 1; // search left half
        }
    }
    return -1;  // target not found
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int target = 7;

    int idx1 = linearSearch(nums, target);
    cout << "Linear Search: Element " << target 
         << (idx1 != -1 ? " found at index " + to_string(idx1) : " not found") << endl;

    int idx2 = binarySearch(nums, target);
    cout << "Binary Search: Element " << target 
         << (idx2 != -1 ? " found at index " + to_string(idx2) : " not found") << endl;

    return 0;
}
