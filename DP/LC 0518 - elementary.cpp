/*
518. Coin Change 2
*/

// Solution 1: dp

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, amount + 1);
        dp[0] = 0;
        for(int i=1; i<=amount ; i++){
            for(int j=0; j<coins.size() ; j++){
                if(i >= coins[j])
                    dp[i] = dp[i] > dp[i-coins[j]] + 1 ? dp[i-coins[j]] + 1 : dp[i];
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

// Solution 2: space optimization

class Solution {
public:

    
    int change(int amount, vector<int>& coins) {
        
        vector<int>dp(amount+1, 0);
        dp[0] = 1;
        for(auto &i: coins){
            for(int j=i ; j<=amount ; j++)
                dp[j] += dp[j-i];
        }

        return dp[amount];
    }


};
