/*
565. Array Nesting
*/


// Solution 1: int array

class Solution {
public:
    
    vector<int>memo;
    int arrayNesting(vector<int>& nums) {
        memo.resize(nums.size(), 0);
        for(int i=0 ; i<nums.size() ; i++)
            solve(nums, i);
        return *max_element(memo.begin(), memo.end());
    }
    int solve(vector<int>& nums, int k){
        if(nums[k] == k)
            return memo[k] = 1;
        if(memo[k] > 0)
            return memo[k];
        if(memo[k] < 0)
            return memo[k] = 0;
        memo[k] = -1;
        return memo[k] = 1 + solve(nums, nums[k]);
    }
};

// Solution 2: bool array

class Solution {
public:
    
    vector<bool>visit;
    int arrayNesting(vector<int>& nums) {
        visit.resize(nums.size(), false);
        int ans = INT_MIN;
        for(int i=0 ; i<nums.size() ; i++){
            int rtn = solve(nums, i);
            ans = ans > rtn ? ans : rtn;
        }
        return ans;
    }
    int solve(vector<int>& nums, int k){
        if(visit[k])
            return 0;
        visit[k] = true;
        return 1 + solve(nums, nums[k]);
    }
};

// Solution 3: