#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    int l = 0, h = nums.size() - 1;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (nums[m] == target)
            return m;
        // check which half is sorted
        if (nums[l] <= nums[m])
        {
            // left half is sorted
            if (nums[l] <= target && target <= nums[m])
                h = m - 1;//if in left half shorten search sapce to left
            else
                l = m + 1;//if not then shorten search sapce to right
        }
        else
        {
            // right half is sorted
            if (nums[m] <= target && target <= nums[h])
                l = m + 1;//if in right half shorten search sapce to right
            else
                h = m - 1;//if not then shorten search sapce to left
        }
    }
    return -1;
}

int main() {

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int index = search(nums, target);
    cout  << index << endl;
    return 0;
}
