/*
72. Edit Distance
*/

// Solution 1:

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if(!n || !m) return max(n, m);
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0 ; i<=n ; i++) dp[i][0] = i;
        for(int j=0 ; j<=m ; j++) dp[0][j] = j;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                dp[i][j] = word1[i-1] == word2[j-1] ? dp[i-1][j-1] : min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
        return dp[n][m];
    }
};

// Solution 2: space optimization

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if(!n || !m) return max(n, m);
        vector<vector<int>> dp(2, vector<int>(m+1, 0));
        bool flag = false;
        for(int j=0 ; j<=m ; j++)
            dp[flag][j] = j;
        flag = !flag;
        for(int i=1 ; i<=n ; i++){
            dp[flag][0] = i;
            for(int j=1 ; j<=m ; j++){
                dp[flag][j] = word1[i-1] == word2[j-1] ? dp[!flag][j-1] : min(dp[!flag][j-1], min(dp[!flag][j], dp[flag][j-1])) + 1;
            }
            flag = !flag;
        }
        return dp[!flag][m];
    }
};