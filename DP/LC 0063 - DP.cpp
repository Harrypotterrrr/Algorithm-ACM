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
    int uniquePathsWithObstacles_wasteSpace(vector<vector<int>>& obstacleGrid) {
        vector<vector<long long>>dp(obstacleGrid.size(), vector<long long>(obstacleGrid[0].size(), 0));
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        for(int i=0; i<n; i++){
            if(obstacleGrid[0][i] == 0) dp[0][i] = 1;
            else break;
        }
        for(int i=0; i<m ; i++){
            if(obstacleGrid[i][0] == 0) dp[i][0] = 1;
            else break;
        }
        for(int i=1 ; i<m ; i++)
            for(int j=1 ; j<n ; j++)
                if(obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[dp.size()-1][dp[0].size() - 1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if(obstacleGrid[0][0] == 1) return 0;
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<long long>dp(n, 0);
        
        for(int i=0; i<n; i++){
            if(obstacleGrid[0][i] == 0) dp[i] = 1;
            else break;
        }
        
        for(int i=1, flag = 1 ; i<m ; i++){
            if(obstacleGrid[i][0] == 1){
                flag = 0;
                dp[0] = 0;
            }
            if(flag == 1) dp[0] = 1;
            for(int j=1 ; j<n ; j++)
                if(obstacleGrid[i][j] == 0) dp[j] += dp[j-1];
                else dp[j] = 0;
        }
           
        return dp[n - 1];
    }
};

int main()
{

}