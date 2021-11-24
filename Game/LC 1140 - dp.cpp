/************************************************
Problem: 		1140. Stone Game II
Algorithm: 		Dynamic Programming, Game Theory
Difficulty: 	***
Importance:		****
Remark:			Minmax problem
*************************************************/

// Solution 1: 
// reference: https://leetcode.com/problems/stone-game-ii/discuss/345230/JavaPython-DP-Solution
// dp[i, m] = maximum stones the current player can get from piles[i:] with M=m
// A[i]= total stones of piles[i:]
// when current player pick stones from i to i+x-1
// -> the other player's stones: dp[i+x, max(m, x)]
// -> total stones of current player: A[i] - dp[i+x, max(m, x)]
// we want the current player gets maximum means the other player gets minimum

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

// Solution 2:
// solve(s, m) = max diff score between two players starting from s for the given M.
// cache[s][M] = max{sum(piles[s:s+x]) – solve(s+x, max(x, M)}, 1 <= x <= 2*M, s + x <= n

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n, vector<int>(n, INT_MIN));
        vector<int>suff_sum(n, 0);
        suff_sum[n-1] = piles[n-1];
        for(int i=n-2 ; i>=0 ; i--) suff_sum[i] = suff_sum[i+1] + piles[i];
        
        function<int(int, int)> solve = [&](int i, int m){
            if(i + 2 * m >= n) return suff_sum[i]; //
            if(dp[i][m] != INT_MIN) return dp[i][m];
            int cur = 0;
            for(int x=1 ; x<=(m<<1) ; x++){
                cur += piles[i+x-1];
                // dp[i][m] = max(dp[i][m], suff_sum[i] - dp[i+x][max(m, x)]);
                dp[i][m] = max(dp[i][m], cur - solve(i+x, max(m, x)));
            }
            return dp[i][m];
        };
        return (suff_sum[0] + solve(0, 1)) >> 1;
    }
};
