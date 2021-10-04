/*
463. Island Perimeter
*/

// Solution 1:

class Solution {
public:
    
    int n, m;
    int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        
        n = grid.size(); m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        int ctr = 0, cur_x, cur_y;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]){
                    ctr += 4;
                    for(int k=0 ; k<4 ; k++){
                        cur_x = i + move[k][0];
                        cur_y = j + move[k][1];
                        if(cur_x < n && cur_x >= 0 && cur_y >= 0 && cur_y < m && grid[cur_x][cur_y]){
                            ctr -= 1;
                        }
                    }
                }
            }
        }
        return ctr;
    }
    
};

// Solution 2: Optimization of solution 1

class Solution {
public:
    
    int n, m;
    int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        
        n = grid.size(); m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        int ctr = 0, cur_x, cur_y;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]){
                    ctr += 4;
                    if(i > 0 && grid[i-1][j]) ctr -= 2;
                    if(j > 0 && grid[i][j-1]) ctr -= 2;
                }
            }
        }
        return ctr;
    }
    
};