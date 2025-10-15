
#include<iostream>
#include<vector>
#include<algorithm>

// binary search function to check if target exists in nums2
bool find_bs(vector<int> &nums2, int &target)
{
    int l = 0, r = nums2.size() - 1;
    while (l <= r)
    {
        int m = (l + r) / 2; // middle index
        if (nums2[m] == target)
            return true; // found target
        if (nums2[m] > target)
            r = m - 1; // search left half
        else
            l = m + 1; // search right half
    }
    return false; // target not found
}

// function to find intersection of nums1 and nums2
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    for (int i : nums1)
    {
        // check if element already in ans to avoid duplicates
        if (count(ans.begin(), ans.end(), i) == 0)
        {
            sort(nums2.begin(), nums2.end()); // sort nums2 for binary search
            bool present = find_bs(nums2, i); // check if element exists in nums2
            if (present)
                ans.push_back(i); // add to result if found
        }
    }
    return ans; // return the intersection array
}
