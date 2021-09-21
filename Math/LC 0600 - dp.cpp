/*
600. Non-negative Integers without Consecutive Ones
*/

class Solution {
public:
    int findIntegers(int n) {
        
        vector<int>dp(30, 0);
        int ans = 0, pre = 0;
        
        dp[0] = 1; dp[1] = 2;
        for(int i=2 ; i<30 ; i++)
            dp[i] = dp[i-1] + dp[i-2];
        
        for(int base = 29 ; base >= 0 ; base--){
            if(n & (1 << base)){
                ans += dp[base];
                if(pre == 1) return ans;
                pre = 1;
            }
            else pre = 0;
        }
        return ans + 1;
    }
};

// Solution 2: TODO https://www.cnblogs.com/grandyang/p/6959585.html