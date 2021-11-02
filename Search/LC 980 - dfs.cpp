/************************************************
Problem: 		980. Unique Paths III
Algorithm: 		Search, DFS
Difficulty: 	*
Importance:		**
Remark:			
*************************************************/

class Solution {
public:
    
    int move[4][2] = {{0,-1},{-1,0},{1,0},{0,1}};
    int n, m, steps;
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int start_x, start_y;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 0 || grid[i][j] == 2) steps++;
                else if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                }
            }
        }
        visited[start_x][start_y] = true;
        return dfs(grid, visited, start_x, start_y, 0);
    }
    
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int k){
        if(grid[x][y] == 2){
            if(k == steps)
                return 1;
            return 0;
        }
        if(k >= steps) return 0;
        int ctr = 0;
        for(int i=0 ; i<4 ; i++){
            int cur_x = x + move[i][0];
            int cur_y = y + move[i][1];
            if(cur_x >= 0 && cur_x < n && cur_y >= 0 && cur_y < m && grid[cur_x][cur_y] != -1 && !visited[cur_x][cur_y]){
                visited[cur_x][cur_y] = true;
                ctr += dfs(grid, visited, cur_x, cur_y, k+1);
                visited[cur_x][cur_y] = false;
            }
        }
        return ctr;
    }
};