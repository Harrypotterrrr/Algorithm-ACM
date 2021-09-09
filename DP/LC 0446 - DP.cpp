/*
446. Arithmetic Slices II - Subsequence
*/

// Solution 1: TLE brute force (2^n)

class Solution {
public:
    
    int ans = 0;
    int numberOfArithmeticSlices(vector<int>& nums) {
        solve(nums, 0, -1, -1, 0);
        return ans;
    }
    void solve(vector<int>& nums, int start, int pre, long diff, int ctr){
        
        if(start >= nums.size())
            return;
        
        solve(nums, start + 1, pre, diff, ctr);
        if(ctr < 2)
            solve(nums, start + 1, nums[start], long(nums[start]) - pre, ctr + 1);
        else if(diff == long(nums[start]) - pre){
            ans ++;
            solve(nums, start + 1, nums[start], diff, ctr + 1);
        }

    }
};