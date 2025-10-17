#include<iostream>
#include<vector>
#include<map>

using namespace std;


//counting sort algo
vector<int> sortArray(vector<int> &nums)
{
    map<int, int> mp;
    for (int i : nums)
        mp[i]++;
    vector<int> res;
    for (auto it : mp)
    {
        int k = it.second;
        while (k > 0)//add each element for its frequency in new array
        {
            res.emplace_back(it.first);
            k--;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {3, 1,6,9};
    vector<int>newarr=sortArray(nums);
    for(int i:newarr){
        cout<<i<<" ";
    }
    return 0;
    
}