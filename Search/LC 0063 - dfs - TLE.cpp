/*
63. Unique Paths II

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

#include "../include/include.h"

class Solution {
public:
    
    int dfs(const vector<vector<int>>&m, vector<vector<int>>&ctr, int x, int y){
        
        // cout <<x <<" "<<y<<endl;
        if(x == ctr.size() - 1 && y == ctr[0].size() - 1) return 1;
        
        if(x < ctr.size() - 1){
            if(ctr[x+1][y] == 0 && m[x+1][y] != 1)
                ctr[x+1][y] = dfs(m, ctr, x + 1, y);
            ctr[x][y] += ctr[x+1][y];
        }
        if(y < ctr[0].size() - 1){
            if(ctr[x][y+1] == 0 && m[x][y+1] != 1)
                ctr[x][y+1] = dfs(m, ctr, x, y + 1);
            ctr[x][y] += ctr[x][y+1];
        }
        
        return ctr[x][y];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if(obstacleGrid[0][0] == 1) return 0;
        
        vector<vector<int>>ctr(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        
        return dfs(obstacleGrid, ctr, 0, 0);
    }
};

int main()
{

}