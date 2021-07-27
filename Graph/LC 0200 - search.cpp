/*
200. Number of Islands
*/

// Solution 1: dfs

class Solution {
public:
    
    vector<vector<int>> move = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> flag(grid.size(), vector<bool>(grid[0].size(), false));
        int ctr = 0;
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[i][j] == '1' && !flag[i][j]){
                    ctr++;
                    dfs(grid, flag, i, j);
                }
            }
        }
        return ctr;
    }
    
    void dfs(vector<vector<char>>&grid, vector<vector<bool>>&flag, int x, int y){
        flag[x][y] = true;
        for(int i=0 ; i<move.size() ; i++){
            int _x = x + move[i][0], _y = y + move[i][1];
            if(_x < 0 || _x >= grid.size())
                continue;
            if(_y < 0 || _y >= grid[0].size())
                continue;
            if(grid[_x][_y] == '1' && !flag[_x][_y]){
                dfs(grid, flag, _x, _y);
            }
        }
    }
};

// Solution 2: bfs

class Solution {
public:
    
    
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> move = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> flag(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>>Q;
        
        int ctr = 0;
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[i][j] == '1' && !flag[i][j]){
                    ctr++;
                    flag[i][j] = true;
                    Q.push({i, j});
                    while(!Q.empty()){
                        auto cur = Q.front(); Q.pop();
                        for(int i=0 ; i<move.size() ; i++){
                            int x = cur.first + move[i][0], y = cur.second + move[i][1];
                            if(x < 0 || x >= grid.size())
                                continue;
                            if(y < 0 || y >= grid[0].size())
                                continue;
                            if(grid[x][y] == '1' && !flag[x][y]){
                                flag[x][y] = true;
                                Q.push({x, y});
                            }
                        }
                    }
                }
            }
        }
        return ctr;
    }
    
};