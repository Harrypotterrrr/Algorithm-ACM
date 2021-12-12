/************************************************
Problem: 		55. Jump Game
Algorithm: 		Dynamic Programming, Greedy
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

// Solution 1: DP solution

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector dp(nums.size(), 0);
        for(int i=1;i<nums.size();i++){
            dp[i] = max(dp[i-1], nums[i-1]) -1;
            if(dp[i] < 0)
                return false;
        }
        return true;
    }
};

// Solution 2: Greedy

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxn = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(i > maxn)
                return false;
            maxn = maxn > nums[i] + i ? maxn : nums[i] + i;
        }
        return true;
    }
};