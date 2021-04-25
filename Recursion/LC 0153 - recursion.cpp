/*
153. Find Minimum in Rotated Sorted Array
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() -1;
        
        while(left < right){
            int mid = (left + right) >> 1;
            if(nums[mid] > nums[right])
                left = mid + 1;
            else if(nums[mid] < nums[left])
                right = mid;
            else
                return nums[left];
        }
        return nums[left];
    }
};

// Solution 2: recursion version

class Solution {
public:
    
    int recursion(vector<int>&nums, int left, int right){
        if(left == right)
            return nums[left];
        int mid = left + ((right - left) >> 1);
        if(nums[mid] > nums[right])
            return recursion(nums, mid + 1, right);
        else if(nums[mid] < nums[left])
            return recursion(nums, left, mid);
        return nums[left];
    }
    
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() -1;
        return recursion(nums, left, right);
    }
};

// Solution 3: divide and conquer

class Solution {
public:
    
    int recursion(vector<int>&nums, int left, int right){
        if(nums[left] <= nums[right])
            return nums[left];
        int mid = left + ((right - left) >> 1);
        return min(recursion(nums, left, mid), recursion(nums, mid+1, right));
    }
    
    int findMin(vector<int>& nums) {
        return recursion(nums, 0, nums.size() -1);
    }
};