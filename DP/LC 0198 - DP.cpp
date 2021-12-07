/************************************************
Problem: 		198. House Robber
Algorithm: 		Dynamic Programming, Recursion
Difficulty: 	*
Importance:		***
Remark:			
*************************************************/

// Solution 1: top to bottom, recursion + memo

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums[0];
        vector<int>memo(n, -1);
        
        function<int(int)> solve = [&n, &nums, &memo, &solve](int cur){
            if(cur >= n) return 0;
            if(memo[cur] != -1) return memo[cur];
            memo[cur] = max(solve(cur+2) + nums[cur], solve(cur+1));
            return memo[cur];
        };
        solve(0);
        return memo[0];
    }
};

// Solution 2: bottom to top, dp

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums[0];
        vector<int>dp(n+1, 0);
        dp[n-1] = nums[n-1];
        
        for(int i=n-2 ; i>=0 ; i--){
            dp[i] = max(dp[i+1], dp[i+2]+nums[i]);
        }
        return dp[0];
    }
};

// Solution 3: space optimization

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums[0];
        
        int cur = nums[n-1], next = 0;
        
        for(int i=n-2 ; i>=0 ; i--){
            int tmp = cur;
            cur = max(cur, next + nums[i]);
            next = tmp;
        }
        return cur;
    }
};

// Solution 4: two array dp myself

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums[0];
        vector<int>use(n, 0), unuse(n, 0);
        use[0] = nums[0]; use[1] = nums[1]; unuse[1] = nums[0];
        for(int i=2 ; i<n ; i++){
            use[i] = (use[i-2], unuse[i-1]) + nums[i];
            unuse[i] = max(use[i-1], unuse[i-1]);
        }
        return max(use[n-1], unuse[n-1]);
    }
};
