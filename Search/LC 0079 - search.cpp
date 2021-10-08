/*
79. Word Search
*/

class Solution {
public:
    
    vector<vector<bool>>visited;
    int n, m, len;
    vector<vector<int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size(), len = word.size();
        visited.resize(n, vector<bool>(m, false));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(board[i][j] == word[0] && dfs(board, i, j, word, 1))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int x, int y, string &word, int k) {
        if(k >= len) return true;
        visited[x][y] = true;
        for(int i=0 ; i<4 ; i++){
            int cur_x = x + move[i][0];
            int cur_y = y + move[i][1];
            if(cur_x >=0 && cur_x < n && cur_y >= 0 && cur_y < m && !visited[cur_x][cur_y] && word[k] == board[cur_x][cur_y])
                if(dfs(board, cur_x, cur_y, word, k+1))
                    return true;
        }
        visited[x][y] = false;
        return false;
    }
};

// Solution 2: not use visited array

class Solution {
public:
    
    int n, m, len;
    vector<vector<int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size(), len = word.size();
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(board[i][j] == word[0] && dfs(board, i, j, word, 1))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int x, int y, string &word, int k) {
        if(k >= len) return true;
        char c = board[x][y];
        board[x][y] = '@';
        for(int i=0 ; i<4 ; i++){
            int cur_x = x + move[i][0];
            int cur_y = y + move[i][1];
            if(cur_x >=0 && cur_x < n && cur_y >= 0 && cur_y < m && board[cur_x][cur_y] != '@' && word[k] == board[cur_x][cur_y])
                if(dfs(board, cur_x, cur_y, word, k+1))
                    return true;
        }
        board[x][y] = c;
        return false;
    }
};