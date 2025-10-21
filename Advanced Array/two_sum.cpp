#include<iostream>
#include<map>
#include<vector>
using namespace std;

vector<int> twosum(vector<int> &nums, int target) {
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++) {
        int rest = target - nums[i];
        if (mpp.find(rest) != mpp.end()) {
            return {mpp[rest], i};
        }
        mpp[nums[i]] = i;
    }
    return {-1, -1};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twosum(nums, target);
    cout << ans[0] << " " << ans[1];
    return 0;
}
