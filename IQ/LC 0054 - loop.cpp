/*
54. Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

#include "../include/include.h"

class Solution {
public:

    vector<int> ans;

    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        if(matrix.empty()) return ans;

        int move[][2]={{0, 1},{1, 0},{0, -1},{-1, 0}};
        int i = 0, j = -1, k, dir=0;
        int steps[2] = {matrix[0].size(), matrix.size()-1};

        while(steps[dir & 0x01]){
            for(k=0; k<steps[dir & 0x01] ; k++){
                i += move[dir][0]; j += move[dir][1];
                ans.push_back(matrix[i][j]);
            }
            steps[dir & 0x01] --;
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};