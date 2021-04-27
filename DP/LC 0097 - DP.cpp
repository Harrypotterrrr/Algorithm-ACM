/*
97. Interleaving String
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
            return false;
        if(s1 == "" && s2 == "")
            return true;
        
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        int k = 0;

        for(int i=0 ; i<s1.size() ; i++){
            if(s3[k] != s1[i])
                break;
            dp[i + 1][0] = true;
            k ++;
        }
        k = 0;
        for(int i=0 ; i<s2.size() ; i++){
            if(s3[k] != s2[i])
                break;
            dp[0][i + 1] = true;
            k ++;
        }
        k = 0;
        for(int i=0 ; i<s1.size() ; i++){
            for(int j=0 ; j<s2.size() ; j++){
                if(dp[i][j + 1] && s3[i+j+1] == s1[i])
                    dp[i+1][j+1] = true;
                if(dp[i + 1][j] && s3[i+j+1] == s2[j])
                    dp[i+1][j+1] = true;
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

// Solution 2: space optimization

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
            return false;
        if(s1 == "" || s2 == ""){
            if(s1 + s2 == s3)
                return true;
            return false;
        }
        
        vector<int>dp(s2.size() + 1, false);
        
        if(s3[0] == s1[0])
            dp[0] = true;
        for(int i=0 ; i<s1.size() + 1 ; i++){
            for(int j=0 ; j<s2.size()+1 ; j++){
                if(i == 0){
                    if(s3[j] == s2[j])
                        dp[j+1] = true;
                    else
                        break;
                }
                else{
                    if(dp[j] && s3[i+j-1] == s1[i-1])
                        dp[j] = true;
                    else if(j > 0 && dp[j-1] && s3[i+j-1] == s2[j-1])
                        dp[j] = true;
                    else
                        dp[j] = false;
                }
            }
        }
        return dp[s2.size()];
    }
};