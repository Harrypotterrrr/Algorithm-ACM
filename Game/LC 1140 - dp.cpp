/************************************************
Problem: 		1140. Stone Game II
Algorithm: 		Dynamic Programming, Game Theory
Difficulty: 	***
Importance:		****
Remark:			
*************************************************/

// Solution 1: 
// reference: https://leetcode.com/problems/stone-game-ii/discuss/345230/JavaPython-DP-Solution

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        vector<int>suff_sum(n, 0);
        suff_sum[n-1] = piles[n-1];
        for(int i=n-2 ; i>=0 ; i--) suff_sum[i] = suff_sum[i+1] + piles[i];
        
        function<int(int, int)> solve = [&](int i, int m){
            if(i + 2 * m >= n) return suff_sum[i];
            if(dp[i][m]) return dp[i][m];
            for(int x=1 ; x<=(m<<1) ; x++){
                // dp[i][m] = max(dp[i][m], suff_sum[i] - dp[i+x][max(m, x)]);
                dp[i][m] = max(dp[i][m], suff_sum[i] - solve(i+x, max(m, x)));
            }
            return dp[i][m];
        };
        
        return solve(0, 1);
    }
};
