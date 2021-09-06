/*
37. Sudoku Solver
*/

// Solution 1: iterate over 9 x 9 grid

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i=0 ; i<board.size() ; i++){
            for(int j=0 ; j<board.size() ; j++){
                if(board[i][j] != '.')
                    continue;
                for(int k='1' ; k<='9' ; k++){
                    if(isValid(board, i, j, k)){
                        board[i][j] = k;
                        if(solve(board))
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int x, int y, char val){
        for(int i=0 ; i<board.size() ; i++){
            if(val == board[x][i])
                return false;
            if(val == board[i][y])
                return false;
        }
        int box_x = x / 3, box_y = y / 3;
        for(int i=0 ; i<9 ; i++){
            int cur_x = x / 3 * 3 + i / 3;
            int cur_y = y / 3 * 3 + i % 3;
            if(board[cur_x][cur_y] == val)
                return false;
        }
        return true;
    }
};

// Solution 2:  WA, bcz independent entity & can not combine	

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
    
    bool solve(vector<vector<char>>& board, int x, int y){
        if(x >= board.size() || y >= board.size())
            return true;
        if(board[x][y] != '.')
            return solve(board, x+1, y) && solve(board, x, y+1);
        for(int i='1' ; i<='9' ; i++){
            if(isValid(board, x, y, i)){
                board[x][y] = i;
                if(solve(board, x+1, y) && solve(board, x, y+1))
                    return true;
                board[x][y] = '.';
            }
        }
        return false;
    }
    
    bool isValid(vector<vector<char>>& board, int x, int y, char val){
        for(int i=0 ; i<board.size() ; i++){
            if(val == board[x][i])
                return false;
            if(val == board[i][y])
                return false;
        }
        for(int i=0 ; i<9 ; i++){
            int cur_x = x / 3 * 3 + i / 3;
            int cur_y = y / 3 * 3 + i % 3;
            if(board[cur_x][cur_y] == val)
                return false;
        }
        return true;
    }
};

// Solution 3: scanning line-by-line

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
    
    bool solve(vector<vector<char>>& board, int x, int y){
        if(x >= 9) return true;
        if(y >= 9) return solve(board, x+1, 0);
        if(board[x][y] != '.') return solve(board, x, y+1);
        for(int i='1' ; i<='9' ; i++){
            if(isValid(board, x, y, i)){
                board[x][y] = i;
                if(solve(board, x, y+1))
                    return true;
                board[x][y] = '.';
            }
        }
        return false;
    }
    
    bool isValid(vector<vector<char>>& board, int x, int y, char val){
        for(int i=0 ; i<board.size() ; i++){
            if(val == board[x][i])
                return false;
            if(val == board[i][y])
                return false;
        }
        for(int i=0 ; i<9 ; i++){
            int cur_x = x / 3 * 3 + i / 3;
            int cur_y = y / 3 * 3 + i % 3;
            if(board[cur_x][cur_y] == val)
                return false;
        }
        return true;
    }
};


// Solution 4: