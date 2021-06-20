/*
53. Maximum Subarray
*/

// Solution 1: dp

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], pre = nums[0];
        for(int i=1 ; i<nums.size() ; i++){
            pre = pre + nums[i] > nums[i] ? pre + nums[i] : nums[i];
            ans = ans > pre ? ans : pre;
        }
        return ans;
    }
};

// Solution 2: divide and conquer

class Solution {
public:
    
    int findMax(vector<int>&nums, int left, int right){
        if(left == right)
            return nums[left];
        int mid = left + ((right - left) >> 1);
        
        int left_max = findMax(nums, left, mid);
        int right_max = findMax(nums, mid+1, right);
        
        int lmax = INT_MIN, lsum = 0;
        for(int i=mid ; i>=left ; i--){
            lsum += nums[i];
            lmax = lmax > lsum ? lmax : lsum;
        }
        int rmax = INT_MIN, rsum = 0;
        for(int i=mid+1 ; i<=right ; i++){
            rsum += nums[i];
            rmax = rmax > rsum ? rmax : rsum;
        }
        return max(left_max, max(right_max, lmax+rmax));
    }
    
    int maxSubArray(vector<int>& nums) {
        return findMax(nums, 0, nums.size() - 1);
    }
};