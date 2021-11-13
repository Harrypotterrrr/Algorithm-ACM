/************************************************
Problem: 		1413. Minimum Value to Get Positive Step by Step Sum
Algorithm: 		Array
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 1, summ = 0;
        for(auto &i: nums){
            summ += i;
            if(summ <= 0)
                ans = ans > -summ + 1 ? ans : -summ + 1;
        }
        return ans;
    }
};