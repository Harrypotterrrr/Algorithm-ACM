/************************************************
Problem: 		441. Arranging Coins
Algorithm: 		Math, Binary Search
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

// Solution 1: binary search

class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1, right = 1 << 16;
        while(left < right){
            long mid = ((right - left) >> 1) + left;
            if((mid * mid + mid >> 1) > n) right = mid;
            else left = mid + 1;
        }
        return left - 1;
    }
};

// Solution 2: Math explicit solution

class Solution {
public:
    int arrangeCoins(int n) {
        return int(sqrt(long(2) * n + 1. / 4) - 0.5);
    }
};