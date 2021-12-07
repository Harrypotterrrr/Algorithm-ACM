/************************************************
Problem: 		213. House Robber II
Algorithm: 		Dynamic Programming, Recursion
Difficulty: 	**
Importance:		***
Remark:			
*************************************************/

// Solution 1: top to bottom, recursion + memo TODO


// Solution 2: bottom to top, dp

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums[0];
        vector<int>rob_first(n+1, 0), unrob_first(n+1, 0);
        for(int i=n-2 ; i>=0 ; i--){
            rob_first[i] = max(rob_first[i+2] + nums[i], rob_first[i+1]);
        }
        unrob_first[n-1] = nums[n-1];
        for(int i=n-2 ; i>=1 ; i--)
            unrob_first[i] = max(unrob_first[i+2] + nums[i], unrob_first[i+1]);
        unrob_first[0] = max(unrob_first[1], unrob_first[2]);
        
        return max(rob_first[0], unrob_first[0]);
    }
};

// Solution 3: space optimization

