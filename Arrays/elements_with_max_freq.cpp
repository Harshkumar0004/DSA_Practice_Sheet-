class Solution {
public:
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
};
