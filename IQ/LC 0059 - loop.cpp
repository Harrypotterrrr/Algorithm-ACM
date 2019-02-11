/*
59. Spiral Matrix II

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

#include "../include/include.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int i=0, j = -1, dir = 0, ctr = 1;
        int move[][2] = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
        int steps[] = {n, n-1};
        while(steps[dir & 0x01]){
            for(int k=0 ; k<steps[dir & 0x01] ; k++){
                i += move[dir][0];
                j += move[dir][1];
                ans[i][j] = ctr++;
            }
            steps[dir & 0x01] --;
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};
int main()
{
}