/************************************************
Problem: 		1510. Stone Game IV
Algorithm: 		Dynamic Programming, Game Theory
Difficulty: 	**
Importance:		****
Remark:			
*************************************************/

// Solution 1: dp[i]: win or lose with the number of i stones used (start from using 1, 2, ... , n stones)

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1, false);
        
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=1 ; i+j*j<=n ; j++)
                dp[i] = dp[i] || !dp[i+j*j];
        }
        return dp[0];
    }
};

// Solution 2: dp[i]: win or lose with the number of i stones left (start from left n, n-1, ..., 2, 1 stones)

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1, false);
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j*j<=i ; j++)
                if(!dp[i-j*j]){
                    dp[i] = true;
                    break;
                }
        }
        return dp[n];
    }
};