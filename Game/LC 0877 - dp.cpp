/************************************************
Problem: 		877. Stone Game
Algorithm: 		Dynamic Programming, Game Theory
Difficulty: 	**
Importance:		****
Remark:			
*************************************************/

// Solution 1: 
// reference: https://leetcode.com/problems/stone-game/discuss/154610/DP-or-Just-return-true

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

// Solution 2: DP, dp[i][j]: from i~j, how much you could get

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size(), summ = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0 ; i<n ; i++) {
            dp[i][i] = piles[i];
            summ += piles[i];
        }
        for(int l=2 ; l<=n ; l++){
            for(int i=0 ; i+l-1<n ; i++){
                int j = i+l-1;
                dp[i][j] = max(dp[i+1][j]+piles[i], dp[i][j-1]+piles[j]);
            }
        }
        if(dp[0][n-1] > summ-dp[0][n-1]) return true;
        return false;
    }
};

// Solution 3: DP, dp[i][j]: from i~j, how much you could get more than opponents

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size(), summ = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0 ; i<n ; i++) dp[i][i] = piles[i];
        for(int l=2 ; l<=n ; l++){
            for(int i=0 ; i+l-1<n ; i++){
                int j = i+l-1;
                dp[i][j] = max(piles[i]-dp[i+1][j], piles[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1] > 0;
    }
};

// Solution 4: DP one dimension of solution 3

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size(), summ = 0;
        vector<int> dp(n, 0);
        for(int i=0 ; i<n ; i++) dp[i] = piles[i];
        for(int l=2 ; l<=n ; l++){
            for(int i=0 ; i+l-1<n ; i++){
                int j = i+l-1;
                dp[i] = max(piles[i]-dp[i+1], piles[j]-dp[i]);
            }
        }
        return dp[0] > 0;
    }
};