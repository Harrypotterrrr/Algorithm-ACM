/*
1987. Number of Unique Good Subsequences
*/

// Solution 1: DP

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        
        int mod = 1e9 + 7, n = binary.size();
        vector<vector<int>>dp(n, vector<int>(2, 0));
        dp[0][1] = (binary[0] == '1' ? 1 : 0);
        for(int i=1 ; i<n ; i++){
            if(binary[i] == '1'){
                dp[i][0] = dp[i-1][0];
                dp[i][1] = (dp[i-1][0] + dp[i-1][1] + 1) % mod;
            }
            else if(binary[i] == '0'){
                dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
                dp[i][1] = dp[i-1][1];
            }
        }
        
        return (dp[n-1][0] || binary[0] == '0') ? (dp[n-1][0] + dp[n-1][1] + 1) % mod : dp[n-1][1];
    }
};

// Solution 2: space optimization

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        
        int mod = 1e9 + 7, n = binary.size();
        int zero = 0, one = 0;
        one = (binary[0] == '1' ? 1 : 0);
        for(int i=1 ; i<n ; i++){
            if(binary[i] == '1'){
                one = (zero + one + 1) % mod;
            }
            else if(binary[i] == '0'){
                zero = (zero + one) % mod;
            }
        }
        
        return (zero || binary[0] == '0') ? (zero + one + 1) % mod : one;
    }
};