/************************************************
Problem: 		1406. Stone Game III
Algorithm: 		Dynamic Programming, Game Theory
Difficulty: 	**
Importance:		****
Remark:			Minmax problem
*************************************************/

// Solution 1: Follow the Problem 1140. Stone Game Ⅱ solution 1

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);
        vector<int>suff_sum(n, 0);
        suff_sum[n-1] = stoneValue[n-1];
        for(int i=n-2 ; i>=0 ; i--) suff_sum[i] = suff_sum[i+1] + stoneValue[i];
        
        function<int(int)> solve = [&](int k){
            if(k >= n) return 0;
            if(dp[k] != INT_MIN) return dp[k];
            for(int i=1 ; i<=3 ; i++){
                dp[k] = max(dp[k], suff_sum[k] - solve(k+i));
            }
            return dp[k];
        };
        solve(0);
        if(dp[0] == suff_sum[0] - dp[0]) return "Tie";
        else if(dp[0] > suff_sum[0] - dp[0]) return "Alice";
        return "Bob";
    }
};

// Solution 2: Follow the Problem 1140. Stone Game Ⅱ solution 2

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);
        for(int i=n-1 ; i>=0 ; i--){
            int cur = 0;
            for(int j=1 ; j<=3 && i+j-1<n ; j++){
                cur += stoneValue[i+j-1];
                dp[i] = max(dp[i], cur - (i+j < n ? dp[i+j] : 0));
            }
        }
            
        if(dp[0] > 0) return "Alice";
        if(dp[0] < 0) return "Bob";
        return "Tie";
    }
};

// Solution 3: space optimization to O(1) for solution 2

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(4, INT_MIN);
        for(int i=n-1 ; i>=0 ; i--){
            int cur = 0;
            dp[i%4] = INT_MIN;
            for(int j=1 ; j<=3 && i+j-1<n ; j++){
                cur += stoneValue[i+j-1];
                dp[i%4] = max(dp[i%4], cur - (i+j < n ? dp[(i+j)%4] : 0));
            }
        }
            
        if(dp[0] > 0) return "Alice";
        if(dp[0] < 0) return "Bob";
        return "Tie";
    }
};
