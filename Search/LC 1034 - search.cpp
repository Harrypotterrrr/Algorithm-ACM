/*
1034. Coloring A Border
*/

// Solution 1: bfs

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int n, m;
        n = grid.size(); m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        queue<pair<int,int>>Q;
        int oldColor = grid[row][col];
        if(color == oldColor) return grid;
        grid[row][col] = color;
        visited[row][col] = true;
        Q.push({row, col});
        
        while(!Q.empty()){
            int x = Q.front().first;
            int y = Q.front().second;
            int ctr = 4;
            Q.pop();
            for(int i=0 ; i<4 ; i++){
                int cur_x = x + move[i][0];
                int cur_y = y + move[i][1];
                if(cur_x < n && cur_x >= 0 && cur_y >= 0 && cur_y < m){
                    if(grid[cur_x][cur_y] == oldColor){
                        if(!visited[cur_x][cur_y]){
                            visited[cur_x][cur_y] = true;
                            Q.push({cur_x, cur_y});
                            grid[cur_x][cur_y] = color;
                        }
                        ctr--;
                    }
                    else if(visited[cur_x][cur_y])
                        ctr--;
                }
            }
            if(!ctr) grid[x][y] = oldColor;
        }
        return grid;
    }
};

// Solution 2: bfs, optimization

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int n= grid.size(), m = grid[0].size();
        int oldColor = grid[row][col];
        if(color == oldColor) return grid;
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[row][col] = true;
        queue<pair<int,int>>Q;
        Q.push({row, col});
        
        while(!Q.empty()){
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            for(int i=0 ; i<4 ; i++){
                int cur_x = x + move[i][0];
                int cur_y = y + move[i][1];
                if(cur_x >= n || cur_x < 0 || cur_y < 0 || cur_y >= m || visited[cur_x][cur_y]) continue;
                if(grid[cur_x][cur_y] == oldColor){
                    visited[cur_x][cur_y] = true;
                    Q.push({cur_x, cur_y});
                }
                else grid[x][y] = color;
            }
            if(x == 0 || y == 0 || x == n-1 || y == m-1) grid[x][y] = color;
        }
        return grid;
    }
};

// Solution 3: dfs

class Solution {
public:
    int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int n, m;
    int newColor, oldColor;
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        oldColor = grid[row][col];
        if(color == oldColor) return grid;
        newColor = color;
        n= grid.size(), m = grid[0].size();
        dfs(grid, row, col);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] < 0) 
                    grid[i][j] = newColor;
            }
        }
        return grid;
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != oldColor) return;
        grid[x][y] = -oldColor;
        for(int i=0 ; i<4 ; i++){
            int cur_x = x + move[i][0];
            int cur_y = y + move[i][1];
            dfs(grid, cur_x, cur_y);
        }
        if(x > 0 && y > 0 && x < n-1 && y < m - 1 && oldColor == abs(grid[x - 1][y]) && oldColor == abs(grid[x + 1][y]) && oldColor == abs(grid[x][y - 1]) && oldColor == abs(grid[x][y + 1]))
            grid[x][y] = oldColor;
    }
};
