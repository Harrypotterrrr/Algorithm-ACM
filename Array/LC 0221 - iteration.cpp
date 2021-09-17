/*
221. Maximal Square
*/

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

// Solution 2: TODO