class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        //store the first element to calculate consecutive sums
        int nextsum=nums[0];
        for(int i=1;i<nums.size();i++){
            //add the next element to nextsum
            nextsum+=nums[i];
            //replace the current element with nextsum
            nums[i]=nextsum;
        }
        return nums;
    }
};