/*
74. Search a 2D Matrix
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left=0, right=matrix.size()-1, col;
        if(matrix[right][0] <= target)
            col = right;
        else if(matrix[left][0] > target)
            return false;
        else{
            while(left < right){
                int mid = left + ((right - left) >> 1);
                if(matrix[mid][0] > target)
                    right = mid;
                else if(matrix[mid][0] < target)
                    left = mid + 1;
                else 
                    return true;
            }
            col = left - 1;
        }
        left = 0;
        right = matrix[0].size() - 1;
        while(left < right){
            int mid = left + ((right - left) >> 1);
            if(matrix[col][mid] > target)
                right = mid;
            else if(matrix[col][mid] < target)
                left = mid + 1;
            else 
                return true;
        }
        if(matrix[col][left] != target)
            return false;
        return true;
    }
};