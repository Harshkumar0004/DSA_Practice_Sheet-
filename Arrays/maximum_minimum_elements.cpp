#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumDeletions(vector<int>& nums) {
    // indices of minimum and maximum elements
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int minindex = 0, maxindex = 0;

    for (int i = 0; i < nums.size(); i++) {
        // update minimum element and its index
        if (nums[i] < mini) {
            mini = nums[i];
            minindex = i;
        }
        // update maximum element and its index
        if (nums[i] > maxi) {
            maxi = nums[i];
            maxindex = i;
        }
    }

    // compute how many deletions are needed from front and back
    int front_min = minindex + 1;                
    int front_max = maxindex + 1;               
    int back_min = nums.size() - minindex;     
    int back_max = nums.size() - maxindex;       

    // all 3 possible ways

    // both from the front
    int front_deletions = max(front_min, front_max);

    // both from the back
    int back_deletions = max(back_min, back_max);

    // one from front and one from back
    int mix_deletions = min(front_min + back_max, front_max + back_min);

    return min({front_deletions, back_deletions, mix_deletions});
}

int main() {
    vector<int> nums = {48,-49,-67,18,-59,-56,47,-26,-24,-73,-96,27,-2,-45};

    int result = minimumDeletions(nums);

    cout << "Minimum deletions required: " << result << endl;

    return 0;
}
