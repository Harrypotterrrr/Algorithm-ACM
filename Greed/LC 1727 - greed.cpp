/*
1727. Largest Submatrix With Rearrangements
*/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<m ; j++)
                if(matrix[i][j])
                    matrix[i][j] += matrix[i-1][j];
        }
        for(int i=0 ; i<n ; i++){
            sort(matrix[i].begin(), matrix[i].end(), [](int &a, int &b){
                return a > b;
            });
            int maxn = matrix[i][0], j;
            for(j=1 ; j<=m && matrix[i][j-1] ; j++){
                int tmp = j * matrix[i][j-1];
                ans = ans > tmp ? ans : tmp;
            }
        }
        return ans;
    }
};