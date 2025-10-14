#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    // store the first element to calculate consecutive sums
    int nextsum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        // add the next element to nextsum
        nextsum += nums[i];
        // replace the current element with nextsum
        nums[i] = nextsum;
    }

    return nums;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    vector<int> result = runningSum(nums);

    cout << "Running sum: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
