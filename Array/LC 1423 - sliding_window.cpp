/************************************************
Problem: 		1423. Maximum Points You Can Obtain from Cards
Algorithm: 		Array, Sliding Window
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

// Solution 1: Sliding window

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int cur = 0, ans = INT_MIN;
        for(int i=0; i<k ; i++)
            cur += cardPoints[i];
        ans = cur;
        for(int i=0 ; i<k ; i++){
            cur -= cardPoints[k-1-i];
            cur += cardPoints[n-1-i];
            ans = ans > cur ? ans : cur;
        }
        return ans;
    }
};