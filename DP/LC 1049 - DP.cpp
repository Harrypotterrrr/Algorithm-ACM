/************************************************
Problem: 		1049. Last Stone Weight II
Algorithm: 		DP
Difficulty: 	***
Importance:		*****
Remark:			0-1 Knapsack problem
*************************************************/

// Solution 1: dp

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int summ = 0, half = 0;
        for(auto &i: stones) summ += i;
        half = (summ >> 1);
        vector<vector<int>>dp(n+1, vector<int>(half + 1, 0));
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=half ; j++){
                if(j >= stones[i-1])
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i-1]] + stones[i-1]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return summ - 2 * dp[n][half];
    }
};

// Solution 2: space optimization

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int summ = 0, half = 0;
        for(auto &i: stones) summ += i;
        half = (summ >> 1);
        vector<int>dp(half + 1, 0);
        for(int i=1 ; i<=n ; i++){
            for(int j=half ; j>=0 ; j--){
                if(j >= stones[i-1])
                    dp[j] = max(dp[j], dp[j-stones[i-1]] + stones[i-1]);
                else
                    dp[j] = dp[j];
            }
        }
        return summ - 2 * dp[half];
    }
};