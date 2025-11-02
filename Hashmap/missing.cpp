#include <iostream>
#include <vector>
using namespace std;

int missing(vector<int>& nums) {
    vector<int> freq(nums.size() + 1, 0); 

    for (int i : nums) {
        freq[i]++;
    }

    for (int i = 0; i < freq.size(); i++) {
        if (freq[i] == 0) return i;
    }

    return 0; 
}

int main() {
    vector<int> nums = {0, 1, 3};
    cout << missing(nums) << endl;  
}
