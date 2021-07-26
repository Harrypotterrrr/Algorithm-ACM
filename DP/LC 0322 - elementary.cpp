/*
322. Coin Change
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

// Solution 2: recursion + memory array

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, INT_MAX);
        dp[0] = 0;
        return solve(dp, coins, amount);
    }
    int solve(vector<int>& dp, vector<int>& coins, int amount){
        if(amount < 0)
            return -1;
        if(dp[amount] != INT_MAX)
            return dp[amount];
        for(int i=0 ; i<coins.size() ; i++){
            int tmp = solve(dp, coins, amount - coins[i]);
            if(tmp >= 0)
                dp[amount] = dp[amount] > tmp + 1 ? tmp + 1 : dp[amount];
        }
        return dp[amount] = (dp[amount] == INT_MAX ? -1 : dp[amount]);
    }
};

// Solution 3: replace vector with unordered_map

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> uM;
        uM[0] = 0;
        return solve(uM, coins, amount);
    }
    int solve(unordered_map<int, int>& uM, vector<int>& coins, int amount){
        if(amount < 0)
            return -1;
        if(uM.find(amount) != uM.end())
            return uM[amount];
        uM[amount] = INT_MAX;
        for(int i=0 ; i<coins.size() ; i++){
            int tmp = solve(uM, coins, amount - coins[i]);
            if(tmp >= 0)
                uM[amount] = uM[amount] > tmp + 1 ? tmp + 1 : uM[amount];
        }
        return uM[amount] = (uM[amount] == INT_MAX ? -1 : uM[amount]);
    }
};

// Solution 4 [Failed]: TLE dfs O(n^n)

class Solution {
public:
    
    static bool cmp(int &a, int &b){
        return a > b;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), cmp);
        return solve(coins, amount, 0);
    }
    int solve(vector<int>& coins, int remain, int k){
        if(remain == 0)
            return 0;
        if(k >=coins.size())
            return -1;
        int quot = remain / coins[k], rtn = INT_MAX;
        if(remain % coins[k] == 0)
            return quot;
        for(int i=quot ; i>=0 ; i--){
            int tmp = solve(coins, remain - i * coins[k], k + 1);
            if(tmp != -1)
                rtn = min(rtn, tmp+i);
        }
        return rtn == INT_MAX ? -1 : rtn;
    }
};

// Solution 5 [Failed]: TLE dfs + pruning

class Solution {
public:
    
    static bool cmp(int &a, int &b){
        return a > b;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), cmp);
        int ans = INT_MAX;
        solve(coins, amount, 0, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }
    void solve(vector<int>& coins, int remain, int k, int ctr, int &ans){
        if(remain == 0){
            ans = min(ans, ctr);
            return;
        }
        if(k >=coins.size())
            return;
        int quot = remain / coins[k], rtn = INT_MAX;
        // if(remain % coins[k] == 0)
        //     return;
        for(int i=quot ; i>=0 ; i--){
            if(ctr + i > ans)
                break;
            solve(coins, remain - i * coins[k], k + 1, ctr + i, ans);
        }
    }
};
