/*
36. Valid Sudoku
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> flag(27, vector<bool>(9, false));
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                if(board[i][j] == '.')
                    continue;
                else{
                    if(!flag[i][board[i][j] - '0' - 1])
                        flag[i][board[i][j] - '0' - 1] = true;
                    else
                        return false;
                    if(!flag[9+j][board[i][j] - '0' - 1])
                        flag[9+j][board[i][j] - '0' - 1] = true;
                    else
                        return false;
                }
                    
            }
        }
        for(int i=0 ; i<3 ; i++){
            for(int j=0 ; j<3 ; j++){
                for(int k=0 ; k<9 ; k++){
                    int cur_x = i * 3 + k / 3, cur_y = j * 3 + k % 3;
                    if(board[cur_x][cur_y] == '.')
                        continue;
                    else if(!flag[18+i*3+j][board[cur_x][cur_y] - '0' - 1])
                        flag[18+i*3+j][board[cur_x][cur_y] - '0' - 1] = true;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};

// Solution 2: a bit of optimization of iteration

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowFlag(9, vector<bool>(9, false));
        vector<vector<bool>> colFlag(9, vector<bool>(9, false));
        vector<vector<bool>> cellFlag(9, vector<bool>(9, false));
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9; j++){
                if(board[i][j] == '.')
                    continue;
                char cur = board[i][j] - '0' - 1;
                if(!rowFlag[i][cur] && !colFlag[j][cur] && !cellFlag[i/3*3+j/3][cur]){
                    rowFlag[i][cur] = true;
                    colFlag[j][cur] = true;
                    cellFlag[i/3*3+j/3][cur] = true;
                }
                else
                    return false;
            }
        }
        return true;
    }
};

// Solution 3: space optimization

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>uS;
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9; j++){
                if(board[i][j] == '.')
                    continue;
                char cur = board[i][j] - '0' - 1;
                string row = "0" + to_string(i) + to_string(cur);
                string col = "1" + to_string(j) + to_string(cur);
                string cell = "2" + to_string(i/3*3+j/3) + to_string(cur);
                if(!uS.count(row) && !uS.count(col) && !uS.count(cell)){
                    uS.insert(row);
                    uS.insert(col);
                    uS.insert(cell);
                }
                else
                    return false;
            }
        }
        return true;
    }
};