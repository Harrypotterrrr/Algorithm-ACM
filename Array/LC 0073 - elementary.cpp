/*
73. Set Matrix Zeroes
*/

class Solution {
public:
    
    int m, n;
    
    void setZero(vector<vector<int>>& matrix, int x, int y){
        for(int i=0 ; i<m ; i++){
            matrix[i][y] = 0;
        }
        for(int j=0 ; j<n; j++){
            matrix[x][j] = 0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        for(int i=0 ; i < m ; i++){
            for(int j = 0 ; j< n ; j++){
                if(matrix[i][j] == 0)
                    flag[i][j] = true;
            }
        }
        for(int i=0 ; i < m ; i++){
            for(int j = 0 ; j< n ; j++){
                if(flag[i][j])
                    setZero(matrix, i, j);
            }
        }
    }
};

// Solution 2: more simple and more fast

class Solution {
public:
    
    int m, n;
    
    void setZeroes(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<bool>row(n, false);
        vector<bool>col(n, false);
        for(int i=0 ; i < m ; i++){
            for(int j = 0 ; j< n ; j++){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(int i=0 ; i < m ; i++){
            for(int j = 0 ; j< n ; j++){
                if(row[i] == true || col[j] == true)
                    matrix[i][j] = 0;
            }
        }
    }
};