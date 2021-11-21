/************************************************
Problem: 		540. Single Element in a Sorted Array
Algorithm: 		Binary Search, Array
Difficulty: 	**
Importance:		***
Remark:			
*************************************************/

// Solution 1: binary search

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int left = 0, right = nums.size();
        while(left < right){
            int mid = ((right - left) >> 1) + left;
            if(nums[mid] == nums[mid+1]) { // mid ? n
                if(mid % 2) right = mid - 1; 
                else left = mid + 2;
            }
            else{
                if(mid % 2) left = mid + 1;
                else right = mid;
            }
        }
        return nums[left];
    }
};