/*
374. Guess Number Higher or Lower
*/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

// Solution 1: Binary search

class Solution {
public:
    int guessNumber(int n) {
        int pick = n;
        int left = 1, right = n;
        while(left < right){
            int pick = ((right - left >> 1) + left);
            int rtn = guess(pick);
            if(rtn < 0) right = pick;
            else if(rtn > 0) left = pick + 1;
            else left = right = pick;
        }
        return left;
    }
};

// Solution 2: Ternary search

class Solution {
public:
    int guessNumber(int n) {
        int pick = n;
        int left = 1, right = n;
        while(left < right){
            int mid1 = (left + (right - left) / 3);
            int mid2 = (right - (right - left) / 3);
            int rtn1 = guess(mid1);
            int rtn2 = guess(mid2);
            if(rtn1 == 0) return mid1;
            if(rtn2 == 0) return mid2;
            if(rtn1 < 0) right = mid1;
            else if(rtn2 > 0) left = mid2 + 1;
            else {
                left = mid1 + 1;
                right = mid2;
            }
        }
        return left;
    }
};
