/*
55. Jump Game
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        for(int i=0 ; i<nums.size();i++){
            if(max_reach < i){
                return false;
            }
            int end = nums[i] + i;
            if(max_reach < end)
                max_reach = end;
        }
        return true;
    }
};

// DP solution

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