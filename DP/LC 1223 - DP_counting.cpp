/************************************************
Problem: 		1223. Dice Roll Simulation
Algorithm: 		Dynamic Programming, Math
Difficulty: 	****
Importance:		****
Remark:			counting, math problem
*************************************************/

// Solution 1: Dynamic Programming O(n^2)

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        const int mod = 1e9 + 7;
        
        vector<vector<long>>dp(n+1, vector<long>(6, 0));
        vector<long>summ(n+1, 0);
        summ[0] = 1; // important initialization to make dp[1][x] = 1
        
        // dp[i][j] = dp[i-1][j^c] + dp[i-2][j^c] + ... + dp[i-k][j^c], where k = rollMax[j]
        // dp[i][j^c] = dp[i][1] + dp[i][2] + ... + dp[i][6] - dp[i][j] = sum(i) - dp[i][j]
        
        for(int i=1 ; i<=n ; i++){
            for(int j=0 ; j<6 ; j++){
                for(int k=1 ; k<=i && k<=rollMax[j] ; k++)
                    dp[i][j] = (dp[i][j] - dp[i-k][j] + summ[i-k] + mod) % mod;
                summ[i] = (summ[i] + dp[i][j]) % mod;
            }
        }
        
        return int(summ[n]);
    }
};