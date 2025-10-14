#include <iostream>
#include <vector>
using namespace std;


int pivotIndex(vector<int>& nums) {
    int totalSum = 0;   // sum of all elements
    int leftSum = 0;    // sum of elements to the left of current index

    // calculate total sum
    for (int num : nums) {
        totalSum += num;
    }
    for (int i = 0; i < nums.size(); i++) {
        int rightSum = totalSum - leftSum - nums[i]; // sum to the right of index i
        if (leftSum == rightSum) {
            return i; // pivot found
        }
        leftSum += nums[i]; // add current element to left sum
    }

    return -1; // no pivot index exists
}

int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    
    int result = pivotIndex(nums);
    cout << "Pivot index: " << result << endl; 

    return 0;
}
