/************************************************
Problem: 		238. Product of Array Except Self
Algorithm: 		Array, Prefix Sum
Difficulty: 	*
Importance:		**
Remark:			left prefix sum, two-pass
*************************************************/

// Solution: time O(N), space O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        ans[n-1] = 1;
        for(int i=n-2 ; i>=0 ; i--)
            ans[i] = ans[i+1] * nums[i+1];
        int tmp = 1;
        for(int i=0 ; i<n ; i++){
            ans[i] = tmp * ans[i];
            tmp *= nums[i];
        }
        return ans;
    }
};