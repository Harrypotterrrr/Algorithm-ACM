/*
413. Arithmetic Slices
*/

// Solution 1: brute force recursion

class Solution {
public:
    
    int ans = 0;
    int numberOfArithmeticSlices(vector<int>& nums) {
        solve(nums, 0, -1, -1, 0);
        return ans;
    }
    void solve(vector<int>& nums, int start, int pre, long diff, int ctr){
        
        if(start >= nums.size())
            return;
        
        if(ctr == 0){
            solve(nums, start + 1, pre, diff, ctr);
            solve(nums, start + 1, nums[start], diff, ctr + 1);
        }
        else if(ctr == 1){
            solve(nums, start + 1, nums[start], long(nums[start]) - pre, ctr + 1);
        }
        else if(long(nums[start]) - pre == diff){
            ans ++;
            solve(nums, start + 1, nums[start], diff, ctr + 1);
        }

    }
};

// Solution 2: math, on pass traverse

class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        int ans = 0;
        int diff = nums[1] - nums[0], ctr = 2;
        for(int i=2 ; i<nums.size() ; i++){
            if(nums[i] - nums[i-1] == diff)
                ctr++;
            else{
                for(int j=1 ; j<=ctr-2 ; j++)
                    ans += j;
                ctr = 2;
                diff = nums[i] - nums[i-1];
            }
        }
        if(ctr > 2)
            for(int j=1 ; j<=ctr-2 ; j++)
                ans += j;
        return ans;
    }

};