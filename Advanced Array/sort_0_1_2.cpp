#include<iostream>
#include<vector>
using namespace std;

void sortcolors(vector<int> &nums)
{
    if (nums.size() < 2)
        return;

    int i = 0;

    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] == 0)
        {
            swap(nums[i], nums[j]);
            i++;
        }
    }

    for (int j = i; j < nums.size(); j++)
    {
        if (nums[j] == 1)
        {
            swap(nums[i], nums[j]);
            i++;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortcolors(nums);

    for (int x : nums)
        cout << x << " ";
    cout << endl;

    return 0;
}
