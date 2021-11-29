/************************************************
Problem: 		562. Longest Line of Consecutive One in Matrix
Algorithm: 		Dynamic Programming
Difficulty: 	*
Importance:		**
Remark:			
*************************************************/

// Solution 1:

class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vertical(n+1, vector<int>(m+1, 0));
        vector<vector<int>> horizon(n+1, vector<int>(m+1, 0));
        vector<vector<int>> diagonal(n+1, vector<int>(m+1, 0));
        vector<vector<int>> antidiag(n+1, vector<int>(m+1, 0));
        int ans = 0;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(mat[i][j] == 0) continue;
                vertical[i+1][j+1] = vertical[i][j+1] + 1;
                horizon[i+1][j+1] = horizon[i+1][j] + 1;
                diagonal[i+1][j+1] = diagonal[i][j] + 1;
                antidiag[i+1][m-j] = antidiag[i][m-j-1] + 1;
                ans = max(ans, max(vertical[i+1][j+1], max(horizon[i+1][j+1], max(diagonal[i+1][j+1], antidiag[i+1][m-j]))));
            }
        }
        return ans;
    }
};

// Solution 2: space optimization  O(m)

class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> vertical(m+1, 0);
        vector<int> horizon(m+1, 0);
        vector<int> diagonal(m+1, 0);
        vector<int> antidiag(m+1, 0);
        int ans = 0;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(mat[i][j] == 0) {
                    vertical[j+1] = horizon[j+1] = antidiag[m-j] = 0;
                }
                else{
                    vertical[j+1] = vertical[j+1] + 1;
                    horizon[j+1] = horizon[j] + 1;
                    antidiag[m-j] = antidiag[m-j-1] + 1;
                    ans = max(ans, max(vertical[j+1], max(horizon[j+1], antidiag[m-j])));
                }
            }
        }
        
        for(int i=0 ; i<n ; i++){
            for(int j=m-1 ; j>=0 ; j--){
                if(mat[i][j] == 0) {
                    diagonal[j+1] = 0;
                }
                else{
                    diagonal[j+1] = diagonal[j] + 1;
                    ans = max(ans, diagonal[j+1]);
                }
            }
            
        }
        return ans;
    }
};

