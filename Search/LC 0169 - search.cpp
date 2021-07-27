/*
169. Majority Element
*/

// Solution 1: divide and conquer, time O(nlog(n)), space O(log(n))

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
    int solve(vector<int>& nums, int start, int end){
        if(start == end)
            return nums[start];
        int mid = start + ((end - start) >> 1);
        int left = solve(nums, start, mid);
        int right = solve(nums, mid+1, end);
        if(left == right)
            return left;
        int ctr_l = 0, ctr_r = 0;
        
        for(int i=start ; i<=end ; i++){
            if(nums[i] == left)
                ctr_l ++;
            else if(nums[i] == right)
                ctr_r ++;
        }
        return ctr_l > ctr_r ? left : right;
    }
};

// Solution 2: divide and conquer with a little bit change, time O(nlog(n)), space O(log(n))
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
    int solve(vector<int>& nums, int start, int end){
        if(start == end)
            return nums[start];
        int mid = start + ((end - start) >> 1);
        int left = solve(nums, start, mid);
        int right = solve(nums, mid+1, end);
        if(left == right)
            return left;
        int ctr_l = 0, ctr_r = 0;
        
        for(int i=start ; i<=end ; i++){
            if(nums[i] == left)
                ctr_l ++;
            else if(nums[i] == right)
                ctr_r ++;
        }
        return ctr_l >= ctr_r ? left : right; // change this line, but still correct
    }
};