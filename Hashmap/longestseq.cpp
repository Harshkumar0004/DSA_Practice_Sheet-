#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    
    int longest = 1, cur = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) continue;
        if (nums[i] == nums[i - 1] + 1) cur++;
        else {
            longest = max(longest, cur);
            cur = 1;
        }
    }
    return max(longest, cur);
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest consecutive sequence length: " << longestConsecutive(nums) << endl;
    return 0;
}
