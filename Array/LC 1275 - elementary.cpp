/*
1275. Find Winner on a Tic Tac Toe Game
*/

// Solution 1: simulation

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>>vec(3, vector<int>(3, 0));
        for(int i=0 ; i<moves.size() ; i++){
            vec[moves[i][0]][moves[i][1]] = ((i % 2) << 1) - 1;
        }
        
        int flag = 0, i = 0;
        for(int j ; i<3 ; i++){
            // check row
            j = 0; flag = vec[i][0];
            for(j=1 ; j<3 ; j++){
                if(vec[i][j] != flag && flag)
                    break;
            }
            if(flag && j == 3)
                return flag == -1 ? "A" : "B";
            
            // check column
            j = 0; flag = vec[0][i];
            for(j=1 ; j<3 ; j++){
                if(vec[j][i] != flag && flag)
                    break;
            }
            if(flag && j == 3)
                return flag == -1 ? "A" : "B";
        }
        
        // check diagonal
        flag = vec[0][0];
        for(i=1; i<3 ; i++){
            if(vec[i][i] != flag && flag)
                break;
        }
        if(flag && i == 3)
            return flag == -1 ? "A" : "B";
        
        // check anti-diagonal
        flag = vec[0][2];
        for(i=1; i<3 ; i++){
            if(vec[i][2-i] != flag && flag)
                break;
        }
        if(flag && i == 3)
            return flag == -1 ? "A" : "B";
        return moves.size() < 9 ? "Pending" : "Draw";
    }

};

// Solution 2: calculate sum of row, col, diagonal and anti-diagonal

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int>row(3, 0);
        vector<int>col(3, 0);
        int diag = 0, antid = 0;
        int flag = 1;
        for(auto &i : moves){
            row[i[0]] += flag;
            col[i[1]] += flag;
            if(i[0] - i[1] == 0)
                diag += flag;
            if(i[0] + i[1] == 2)
                antid += flag;
            if(abs(row[i[0]]) == 3 || abs(col[i[1]]) == 3 || abs(diag) == 3 || abs(antid) == 3)
                return flag == 1 ? "A" : "B";
            flag = -flag;
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};