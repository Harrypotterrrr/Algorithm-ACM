/************************************************
Problem: 		1877. Minimize Maximum Pair Sum in Array
Algorithm: 		Array, Greed
Difficulty: 	*
Importance:		***
Remark:			Minmax
*************************************************/

// Solution:

// Prove:
// assuming amin <= ai <= amax, amin <= aj <= amax,
// the combination of max(amin + amax, ai + aj), and max(amin + ai, aj + amax).

// for max(amin + ai, aj + amax) = aj + amax
// for max(amin + amax, ai + aj) = ai + aj < aj = amax or amin + amax < aj + amax
// thus, the first one is always not bad than the second one

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        for(int i=0 ; i<(n>>1) ; i++)
            ans = ans > nums[i] + nums[n-1-i] ? ans : nums[i] + nums[n-1-i];
        return ans;
    }
};