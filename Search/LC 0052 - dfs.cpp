/*
52. N-Queens II
*/

class Solution {
public:
    
    int ctr;
    
    void dfs(int k, const int n, vector<bool>&col, vector<bool>&diag, vector<bool>&diag_inv){
        if(k >= n){
            ctr++;
            return;
        }
        for(int i=0 ; i<n ; i++){
            if(!col[i] && !diag[n-1+i-k] && !diag_inv[i+k]){
                col[i] = true;
                diag[n-1+i-k] = true;
                diag_inv[i+k] = true;
                dfs(k+1, n, col, diag, diag_inv);
                col[i] = false;
                diag[n-1+i-k] = false;
                diag_inv[i+k] = false;
            }
        }
    }
    
    int totalNQueens(int n) {

        vector<bool>col(n, false);
        vector<bool>diag(n * 2, false);        
        vector<bool>diag_inv(n * 2, false);

        dfs(0, n, col, diag, diag_inv);
        return ctr;
    }
};