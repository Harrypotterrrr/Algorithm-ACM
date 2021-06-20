/*
198. House Robber
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>rob(nums.size(), 0), unrob(nums.size(), 0);
        rob[0] = nums[0];
        unrob[0] = 0;
        for(int i=1 ; i<nums.size() ; i++){
            rob[i] = unrob[i-1] + nums[i];
            unrob[i] = max(unrob[i-1], rob[i-1]);
        }
        return max(rob[nums.size() - 1], unrob[nums.size() -1]);
    }
};

// Solution 2: space optimization

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = nums[0], unrob = 0;
        
        for(int i=1 ; i<nums.size() ; i++){
            int tmp = rob;
            rob = unrob + nums[i];
            unrob = max(unrob, tmp);
        }
        return max(rob, unrob);
    }
};

// Solution 3:

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums[0];
        vector<int>dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2 ; i<nums.size() ; i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[nums.size() - 1];
    }
};