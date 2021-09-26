/*
782. Transform to Chessboard
*/

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        int row_diff, col_diff;
        for(int i=0 ; i<n ; i++){
            row_diff = 0;
            for(int j=0 ; j<n ; j++){
                if(board[i][j] == 1) row_diff++;
                else row_diff--;
            }
            if(abs(row_diff) > 1) return -1;
            col_diff = 0;
            for(int j=0 ; j<n ; j++){
                if(board[j][i] == 1) col_diff++;
                else col_diff--;
            }
            if(abs(col_diff) > 1) return -1;
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++)
                if(board[i][0] ^ board[0][0] ^ board[0][j] ^ board[i][j])
                    return -1;
        }
        if(n % 2){
            int row_ctr = 0, col_ctr = 0;
            for(int i=0 ; i<n ; i++){
                if(row_diff > 0) row_ctr += (board[n-1][i] == i % 2 ? 1 : 0);
                else row_ctr += (board[n-1][i] == i % 2 ? 0 : 1);
                if(col_diff > 0) col_ctr += (board[i][n-1] == i % 2 ? 1 : 0);
                else col_ctr += (board[i][n-1] == i % 2 ? 0 : 1);
            }
            return (row_ctr + col_ctr) >> 1;
        }
        else{
            int row_ctr1 = 0, row_ctr0 = 0, col_ctr0 = 0, col_ctr1 = 0;
            for(int i=0 ; i<n ; i++){
                row_ctr1 += (board[n-1][i] == i % 2 ? 1 : 0);
                row_ctr0 += (board[n-1][i] == i % 2 ? 0 : 1);
                col_ctr1 += (board[i][n-1] == i % 2 ? 1 : 0);
                col_ctr0 += (board[i][n-1] == i % 2 ? 0 : 1);
            }
            return (min(row_ctr1, row_ctr0) + min(col_ctr1, col_ctr0)) >> 1;
        }
    }
};