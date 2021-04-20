/*
51. N-Queens
*/

class Solution {
public:
    
    vector<vector<string>> ans;
    
    void dfs(int k, const int n, vector<string>&chessboard, vector<bool>&col, vector<bool>&diag, vector<bool>&diag_inv){
        if(k >= n){
            ans.push_back(chessboard);
            return;
        }
        for(int i=0 ; i<n ; i++){
            if(!col[i] && !diag[n-1+i-k] && !diag_inv[i+k]){
                col[i] = true;
                diag[n-1+i-k] = true;
                diag_inv[i+k] = true;
                chessboard[k][i] = 'Q';
                dfs(k+1, n, chessboard, col, diag, diag_inv);
                col[i] = false;
                diag[n-1+i-k] = false;
                diag_inv[i+k] = false;
                chessboard[k][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard;
        for(int i=0 ; i<n;i++){
            string tmp;
            for(int j=0 ; j<n;j++){
                tmp += '.';
            }
            chessboard.push_back(tmp);
        }
        vector<bool>col(n, false);
        vector<bool>diag(n * 2, false);        
        vector<bool>diag_inv(n * 2, false);

        dfs(0, n, chessboard, col, diag, diag_inv);
        return ans;
    }
};