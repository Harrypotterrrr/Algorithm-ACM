/************************************************
Problem: 		994. Rotting Oranges
Algorithm: 		Search, BFS
Difficulty: 	**
Importance:		**
Remark:			
*************************************************/


class Solution {
public:
    
    int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>>Q;
        int n = grid.size(), m = grid[0].size();
        bool flag = false;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 2){
                    Q.push({i, j});
                    // grid[i][j] = -1;
                }
                if(grid[i][j] == 1)
                    flag = true;
            }
        }
        if(!flag && Q.empty()) return 0;
        int level = -1;
        while(!Q.empty()){
            level ++;
            for(int k = Q.size()-1 ; k>=0 ; k--){
                auto cur = Q.front(); Q.pop();
                for(int i=0 ; i<4 ; i++){
                    int cur_x = cur.first + move[i][0];
                    int cur_y = cur.second + move[i][1];
                    if(cur_x >=0 && cur_x < n && cur_y >= 0 && cur_y < m && grid[cur_x][cur_y] == 1){
                        grid[cur_x][cur_y] = 2;
                        Q.push({cur_x, cur_y});
                    }
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return level;
    }
};