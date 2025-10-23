#include<iostream>
#include<vector>
using namespace std;

int lower_b(vector<int>&nums,int target){
    int l=0,h=nums.size()-1;
    int ans=nums.size();
    while(l<=h){
        int mid=(l+h)/2;
        if(nums[mid]>=target){//seacrh for lesser index
            ans=mid;
            h=mid-1;
        }
        else l=mid+1;//go to right 

    }
    return ans;
}

int main(){
    vector<int>nums={0,3,9,10,11};
    int x=lower_b(nums,6);
    cout<<x<<endl;
    return 0;
}