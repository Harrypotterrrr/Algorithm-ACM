/*
695. Max Area of Island
*/

// Solution 1: dfs

class Solution {
public:
    int n, m;
    int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size();
        int ans = 0, ctr = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                ctr = dfs(grid, i, j);
                ans = ans > ctr ? ans : ctr;
            }
        }
        return ans;
    }
    
    int dfs(vector<vector<int>>& grid, int x, int y){
        if(!grid[x][y] || grid[x][y] == -1) return 0;
        int ctr = 0;
        grid[x][y] = -1;
        for(int i=0 ; i<4 ; i++){
            int cur_x = x + move[i][0];
            int cur_y = y + move[i][1];
            if(cur_x >= 0 && cur_x < n && cur_y >=0 && cur_y < m)
                ctr += dfs(grid, cur_x, cur_y);
        }
        return ctr + 1;
    }
};

// Solution 2: bfs

class Solution {
public:

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>>Q;
        int ans = 0, ctr = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1){
                    ctr = 0;
                    Q.push({i, j});
                    grid[i][j] = -1;
                    while(!Q.empty()){
                        ctr++;
                        auto cur = Q.front(); Q.pop();
                        for(int k=0 ; k<4 ; k++){
                            int cur_x = cur.first + move[k][0];
                            int cur_y = cur.second + move[k][1];
                            if(cur_x >= 0 && cur_x < n && cur_y >=0 && cur_y < m && grid[cur_x][cur_y] == 1){
                                grid[cur_x][cur_y] = -1;
                                Q.push({cur_x, cur_y});
                            }
                        }
                    }
                    ans = ans > ctr ? ans : ctr;
                }
            }
        }
        return ans;
    }
};