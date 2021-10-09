/*
666. Path Sum IV
*/

// Solution 1: recursion

class Solution {
public:
    int ans = 0, n;
    int pathSum(vector<int>& nums) {
        n = nums.size();
        solve(nums, 0, 1, 1);
        return ans;
    }
    
    int solve(vector<int>& nums, int summ, int level, int k){
        int i;
        for(i=0 ; i < n ; i++){
            if(nums[i] / 100 == level && nums[i] % 100 / 10 == k)
                break;
        }
        if(i == n) return -1;
        int val = nums[i]%10;
        int left = solve(nums, summ+val, level + 1, ((k - 1) << 1) + 1);
        int right = solve(nums, summ+val, level + 1, ((k - 1) << 1) + 2);
        if(left == -1 && right == -1){
            ans += summ+val;
        }
        return i;
                
    }
};
