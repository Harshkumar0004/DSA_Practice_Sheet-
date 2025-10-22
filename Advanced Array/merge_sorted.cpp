#include<iostream>
#include<vector>
#include<map>
using namespace std;

//using custom counting sort
vector<int> countingsort(vector<int> &nums)
{
    map<int, int> mp;
    for (int i : nums)
        mp[i]++;
    vector<int> ans;
    for (auto &[f, s] : mp)
    {
        while (s > 0)
        {
            ans.emplace_back(f);
            s--;
        }
    }
    return ans;
}
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int i = 0; i < n; i++)
    {
        nums1[m + i] = nums2[i];
    }
    nums1 = countingsort(nums1);
}

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    int m=3;
    vector<int> nums2 = {2,5,6};
    int n=3;
    merge(nums1,m,nums2,n);
    for(int ti:nums1){
        cout<<ti<<" ";
    }
    return 0;
}