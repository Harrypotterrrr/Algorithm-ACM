/*
174. Dungeon Game
*/

// Solution 1: space O(n^2)

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=0 ; i<n ; i++)
            dp[i][m] = INT_MAX;
        for(int j=0 ; j<m ; j++)
            dp[n][j] = INT_MAX;
        dp[n][m-1] = 1;
        for(int i=n-1; i>=0 ; i--){
            for(int j=m-1 ; j>=0 ; j--){
                if(dungeon[i][j] < 0)
                    dp[i][j] = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                else
                    dp[i][j] = min(dp[i+1][j] - dungeon[i][j] < 1 ? 1 : dp[i+1][j] - dungeon[i][j], dp[i][j+1] - dungeon[i][j] < 1 ? 1 : dp[i][j+1] - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};

// Solution 2: space O(n)

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<int>dp(m+1, 0);
        for(int j=0 ; j<m ; j++)
            dp[j] = INT_MAX;
        
        for(int i=n-1; i>=0 ; i--){
            dp[m] = (i == n-1 ? 1 : INT_MAX);
            for(int j=m-1 ; j>=0 ; j--){
                if(dungeon[i][j] < 0)
                    dp[j] = min(dp[j], dp[j+1]) - dungeon[i][j];
                else
                    dp[j] = min(dp[j] - dungeon[i][j] < 1 ? 1 : dp[j] - dungeon[i][j], dp[j+1] - dungeon[i][j] < 1 ? 1 : dp[j+1] - dungeon[i][j]);
            }
        }
        return dp[0];
    }
};