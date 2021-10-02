/*
1428. Leftmost Column with at Least a One
*/

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

// Solution 1: binary search O(nlog(n))

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int n = binaryMatrix.dimensions()[0], m = binaryMatrix.dimensions()[1];
        int ans = INT_MAX;
        for(int i=0 ; i<n ; i++){
            int rtn = binarySearch(binaryMatrix, i, m-1);
            if(rtn == -1) continue;
            ans = ans < rtn ? ans : rtn;
        }
        return ans == INT_MAX ? -1 : ans;
    }
    int binarySearch(BinaryMatrix &binaryMatrix, int k, int right){
        int left = 0, mid, value;
        while(left < right){
            mid = ((right - left) >> 1) + left;
            value = binaryMatrix.get(k, mid);
            if(value) right = mid;
            else left = mid + 1;
        }
        
        return binaryMatrix.get(k, left) ? left : -1;
    }
};

// Solution 2: O(n + m)

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int n = binaryMatrix.dimensions()[0], m = binaryMatrix.dimensions()[1];
        int ans = INT_MAX, x = 0, y = m-1;
        while(x < n && y >= 0){
            if(binaryMatrix.get(x, y)) y--;
            else x++;
        }
        if(y == m-1) return -1;
        return y + 1;
    }
};