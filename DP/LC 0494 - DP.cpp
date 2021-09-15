/*
494. Target Sum
*/

// Solution 1: TLE brute force

class Solution {
public:
    int ans = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(nums, target, 0);
        return ans;
    }
    void solve(vector<int>& nums, int target, int start){
        if(start == nums.size()){
            if(!target) ans ++;
            return;
        }
        solve(nums, target-nums[start], start + 1);
        solve(nums, target+nums[start], start + 1);
    }
};

// Solution 2: Solution 1 + pruning

class Solution {
public:
    int ans = 0;
    vector<int>sum;
    int findTargetSumWays(vector<int>& nums, int target) {
        sum.resize(nums.size(), 0);
        sum.back() = nums.back();
        for(int i=sum.size()-2 ; i>=0 ; i--)
            sum[i] = nums[i] + sum[i+1];
        solve(nums, target, 0);
        return ans;
    }
    void solve(vector<int>& nums, int target, int start){
        if(start == nums.size()){
            if(!target) ans ++;
            return;
        }
        if(sum[start] > 0){
            if(target > 0 && target - sum[start] > 0)
                return;
            if(target < 0 && target + sum[start] < 0)
                return;
        }
        if(sum[start] < 0){
            if(target > 0 && target + sum[start] > 0)
                return;
            if(target < 0 && target - sum[start] < 0)
                return;
        }
        solve(nums, target-nums[start], start + 1);
        solve(nums, target+nums[start], start + 1);
    }
};

