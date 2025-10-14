//approach 1: using extra space

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // handle cases where k > n
        vector<int> temp(n);
        // place each element at its new rotated position
        for (int i = 0; i < n; i++)
            temp[(i + k) % n] = nums[i];
        nums = temp;
    }
};

//approach 2: using reverse

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s=nums.size();
        k=k%s;
        //reverse entire array
        reverse(nums.begin(),nums.end());
        //reverse first k elements
        reverse(nums.begin(),nums.begin()+k);
        // reverse the rest
        reverse(nums.begin()+k,nums.end());
        
    }
};

