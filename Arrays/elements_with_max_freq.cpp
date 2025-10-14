#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxFrequencyElements(vector<int>& nums) {
    // count the frequency of each element using a hash map
    unordered_map<int, int> mp;
    for (auto i : nums)
        mp[i]++;

    // find the maximum frequency among all elements
    int maxi = 0;
    for (auto i : mp)
        maxi = max(maxi, i.second);

    // count total occurrences of all elements that have this maximum frequency
    int cnt = 0;
    for (auto i : mp) {
        if (i.second == maxi)
            cnt += i.second;
    }
    return cnt;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4};

    int result = maxFrequencyElements(nums);

    cout << "Total occurrences of elements with maximum frequency: " << result << endl;

    return 0;
}
