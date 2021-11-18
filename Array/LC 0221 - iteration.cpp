/************************************************
Problem: 		221. Maximal Square
Algorithm: 		DP, Array
Difficulty: 	**
Importance:		***
Remark:			Similar to LC 1277
*************************************************/

// Solution 1: tricky O(MN)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<vector<int>>memo(n, vector<int>(m, 0));
        for(int i=0 ; i<n ; i++){
            int ctr = 0;
            for(int j=m-1 ; j>=0 ; j--){
                if(matrix[i][j] == '0') ctr = 0;
                else memo[i][j] = ++ctr;
            }
        }

        for(int j=0 ; j<m ; j++){
            int ctr = 0;
            for(int i=n-1 ; i>=0 ; i--){
                if(matrix[i][j] == '0') ctr = 0;
                else{
                    ctr ++;
                    memo[i][j] = memo[i][j] < ctr ? memo[i][j] : ctr;
                }
            }
        }

        for(int i=0 ; i<n ; i++){
            // x = i-j, y = m-1-j
            int j = 0, ctr = 1;
            while(i-j>=0 && i-j<n && m-1-j>=0){
                if(matrix[i-j][m-1-j] == '0') ctr = 0;

                else{
                    ctr = memo[i-j][m-1-j] = memo[i-j][m-1-j] < ctr ? memo[i-j][m-1-j] : ctr;
                    ans = ans > memo[i-j][m-1-j] ? ans : memo[i-j][m-1-j];
                }
                j++; ctr++;
            }
        }

        for(int i=0 ; i<m ; i++){
            // x = n-1-j, y = i-j
            int j = 0, ctr = 1;
            while(n-1-j>=0 && i-j>=0 && i-j<m){
                if(matrix[n-1-j][i-j] == '0') ctr = 0;
                else{
                    ctr = memo[n-1-j][i-j] = memo[n-1-j][i-j] < ctr ? memo[n-1-j][i-j] : ctr;
                    ans = ans > memo[n-1-j][i-j] ? ans : memo[n-1-j][i-j];
                }
                j++; ctr++;
            }
        }

        return ans * ans;
    }
};

// Solution 2: DP time: O(NM), space: O(NM)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j] == '1'){
                    if(i > 0 && j > 0)
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    else
                        dp[i][j] = 1;
                }
                ans = ans > dp[i][j] ? ans : dp[i][j];
            }
        }
        return ans * ans;
    }
};

// Solution 3: DP compress the space to O(M)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0, pre, cur;
        vector<int> dp(m, 0);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cur = dp[j];
                if(matrix[i][j] == '1'){
                    if(i > 0 && j > 0)
                        dp[j] = min(pre, min(dp[j-1], cur)) + 1;
                    else
                        dp[j] = 1;
                }
                else dp[j] = 0;
                pre = cur;
                ans = ans > dp[j] ? ans : dp[j];
            }
        }
        return ans * ans;
    }
};