#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int maxSubArray(vector<int>& nums) {
    int sum = 0;               // current subarray sum
    int maxSum = INT_MIN;      // maximum subarray sum found so far

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];        // add current element to current sum

        if (sum > maxSum) {    // update maxSum if current sum is greater
            maxSum = sum;
        }

        if (sum < 0) {         // reset current sum if it becomes negative
            sum = 0;
        }
    }

    return maxSum;             
}




int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = maxSubArray(nums);
    cout << "Maximum subarray sum: " << result << endl; 

    return 0;
}
