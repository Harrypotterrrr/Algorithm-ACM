/************************************************
Problem: 		130. Surrounded Regions
Algorithm: 		Search, BFS, DFS
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

// Solution 1: BFS

class Solution {
public:
    
    
    int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int n, m;
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        for(int i=0 ; i<n ; i++){
            if(board[i][0] == 'O') bfs(board, i, 0);
            if(board[i][m-1] == 'O') bfs(board, i, m-1);
        }
        for(int j=0 ; j<m ; j++){
            if(board[0][j] == 'O') bfs(board, 0, j);
            if(board[n-1][j] == 'O') bfs(board, n-1, j);
        }

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(board[i][j] == 'S') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
    
    void bfs(vector<vector<char>>& board, int i, int j){
        board[i][j] = 'S';
        queue<pair<int, int>> Q({{i, j}});
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int k=0 ; k<4 ; k++){
                int x = cur.first + move[k][0];
                int y = cur.second + move[k][1];
                if(x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O'){
                    board[x][y] = 'S';
                    Q.push({x, y});
                }
            }
        }
    }
};

// Solution 2: DFS

class Solution {
public:
    
    
    int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int n, m;
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        for(int i=0 ; i<n ; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][m-1] == 'O') dfs(board, i, m-1);
        }
        for(int j=0 ; j<m ; j++){
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[n-1][j] == 'O') dfs(board, n-1, j);
        }

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(board[i][j] == 'S') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j){
        board[i][j] = 'S';
        for(int k=0 ; k<4 ; k++){
            int x = i + move[k][0];
            int y = j + move[k][1];
            if(x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O'){
                board[x][y] = 'S';
                dfs(board, x, y);
            }
        }
    }
};