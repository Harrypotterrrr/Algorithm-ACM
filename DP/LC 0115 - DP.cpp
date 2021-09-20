/*
115. Distinct Subsequences
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size() < t.size())
            return 0;
        
        vector<vector<unsigned long long>>dp(t.size()+1, vector<unsigned long long>(s.size()+1, 0));

        for(int i=0 ; i<=s.size() ; i++)
            dp[0][i] = 1;
        for(int i=1 ; i<=t.size() ; i++){
            for(int j=i ; j<=s.size() ; j++){
                if(s[j-1] == t[i-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[t.size()][s.size()];
    }
};
