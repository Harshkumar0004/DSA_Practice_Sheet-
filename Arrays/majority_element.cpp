#include <iostream>
#include <vector>
#include <map>
using namespace std;



// approach 1- O(n) Space complexity
int majorityElement(vector<int> &nums)
{
    map<int, int> mpp;  // map to store frequency of each element
    int maj_element;    // variable to store majority element

    // count frequency of each element
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]] += 1;
    }

    // find element whose count is greater than n/2
    for (auto it : mpp)
    {
        if (it.second > nums.size() / 2)
        {
            maj_element = it.first;
        }
    }
    return maj_element; // return majority element
}

//approach 2 - O(1) Space complexity

int majorityElement_voting_method(vector<int> &nums)
{
    int candidate = nums[0]; // candidate for majority
    int count = 1;           // count of candidate

    // find candidate
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == candidate)
            count++;        // same as candidate, increase count
        else
            count--;        // different, decrease count

        if (count == 0)
        {
            candidate = nums[i]; // pick new candidate
            count = 1;
        }
    }

    // candidate is the majority element
    return candidate;
}

int main(){
    vector<int> nums = {3, 2, 5, 5, 6, 7, 7, 7, 78, 1};
    cout << majorityElement(nums) << endl; 
    cout << majorityElement_voting_method(nums) << endl;//optimal
    return 0;
}
