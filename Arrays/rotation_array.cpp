#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach 1: Using extra space
void rotateExtraSpace(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n; // handle cases where k > n
    vector<int> temp(n);

    // place each element at its new rotated position
    for (int i = 0; i < n; i++)
        temp[(i + k) % n] = nums[i];

    nums = temp; // copy back
}

// Approach 2: Using reverse (in-place)
void rotateReverse(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n; // handle k > n

    // reverse entire array
    reverse(nums.begin(), nums.end());
    // reverse first k elements
    reverse(nums.begin(), nums.begin() + k);
    // reverse remaining n-k elements
    reverse(nums.begin() + k, nums.end());
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    // Approach 1
    vector<int> arr1 = nums1; // copy original array
    rotateExtraSpace(arr1, k);
    cout << "After rotation (extra space): ";
    for (int x : arr1) cout << x << " ";
    cout << endl;

    // Approach 2
    vector<int> arr2 = nums1; // copy original array
    rotateReverse(arr2, k);
    cout << "After rotation (reverse method): ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}
