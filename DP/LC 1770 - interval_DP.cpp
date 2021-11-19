/************************************************
Problem: 		1770. Maximum Score from Performing Multiplication Operations
Algorithm: 		DP
Difficulty: 	***
Importance:		*****
Remark:			Interval dp
*************************************************/

// [1 2 3 4]
// |-[2 3 4] 		-[1 2 3]
// |-[3 4] 	 -[2 3]		-[2 3]     -[1 2]
// |-[4] -[3] -[3] -[2] 	-[3] -[2]  -[2] -[1] 
// M level + m leaves


// Solution 1: Top-Down: Recursion with memorization (left, k)

class Solution {
public:
    
    int n, m;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = nums.size();
        m = multipliers.size();
        vector<vector<int>>memo(m, vector<int>(m, INT_MIN));
        return solve(nums, multipliers, memo, 0, 0, n-1);
    }

    int solve(vector<int>& nums, vector<int>& multipliers, vector<vector<int>> &memo, int k, int left, int right){
        if(k >= m) return 0;
        if(memo[left][k] != INT_MIN) return memo[left][k];
        int l = nums[left] * multipliers[k] + solve(nums, multipliers, memo, k+1, left + 1, right);
        int r = nums[right] * multipliers[k] + solve(nums, multipliers, memo, k+1, left, right - 1);
        return memo[left][k] = l > r ? l : r;
    }
};

// Solution 2: Top-Down: Recursion with lambda C++11

class Solution {
public:
    
    int n, m;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        const int n = nums.size();
        const int m = multipliers.size();
        vector<vector<int>>memo(m, vector<int>(m, INT_MIN));
        function<int(int, int)> solve = [&](int left, int right){
            const int k = n - 1 - right + left;
            if(k >= m) return 0;
            auto &cur = memo[left][k];
            if(cur != INT_MIN) return cur;
            int l = nums[left] * multipliers[k] + solve(left+1, right);
            int r = nums[right] * multipliers[k] + solve(left, right-1);
            return cur = l > r ? l : r;
        };
        return solve(0, n-1);
    }

};

// Solution 3: Bottom-Top DP

class Solution {
public:
    
    int n, m;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {

        const int n = nums.size();
        const int m = multipliers.size();
        vector<vector<int>>dp(m+1, vector<int>(m+1, INT_MIN));
        int ans = INT_MIN;
        dp[0][0] = 0;
        for(int level=1 ; level<=m ; level++){ // tree level
            for(int i=0, j=level-i ; i<=level ; ++i, --j){ // use left i elements and right j elements
                dp[i][j] = max( i ? dp[i-1][j] + nums[i-1] * multipliers[level-1] : INT_MIN,
                                j ? dp[i][j-1] + nums[n-j] * multipliers[level-1] : INT_MIN);
            }
        }
        for(int i=0 ; i<=m ; i++)
            ans = ans > dp[i][m-i] ? ans : dp[i][m-i];
        return ans;
    }

};