/************************************************
Problem: 		1277. Count Square Submatrices with All Ones
Algorithm: 		DP, Array
Difficulty: 	**
Importance:		***
Remark:			
*************************************************/

// Solution: 

// 1 1 1
// 1 2 2
// 1 2 3
// dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j] && i > 0 && j > 0)
                    matrix[i][j] = min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1])) + 1;
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};