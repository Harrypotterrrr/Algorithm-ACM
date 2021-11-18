/************************************************
Problem: 		1509. Minimum Difference Between Largest and Smallest Value in Three Moves
Algorithm: 		Array, Recursion
Difficulty: 	**
Importance:		***
Remark:			
*************************************************/

// Solution 1: sorting + recursion O(Nlog(N))

class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return solve(nums, 0, nums.size()-1, 0);
    }
    
    int solve(vector<int>& nums, int left, int right, int k){
        if(right == left) return 0;
        if(k >= 3) return nums[right] - nums[left];
        int r, l;
        r = solve(nums, left, right-1, k+1);
        l = solve(nums, left+1, right, k+1);
        return r < l ? r : l;
    }
};

// Solution 2: sorting O(Nlog(N))

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for(int i=0 ; i<4 ; i++)
            ans = ans < nums[n-4+i] - nums[i] ? ans : nums[n-4+i] - nums[i];
        return ans;
    }
};