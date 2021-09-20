/*
940. Distinct Subsequences II
*/


class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int>memo(26, 0);
        long dp = 2, tmp, mod = 1e9+7;
        memo[s[0] - 'a'] = 1;
        for(int i=1 ; i<s.size() ; i++){
            tmp = dp;
            
            // dp = (dp * 2 - memo[s[i]-'a']) % mod
            dp = ((dp << 1) - (memo[s[i]-'a']) + mod) % mod;
            memo[s[i]-'a'] = tmp;
        }
        return int(dp - 1);
    }
};