/*
35. Search Insert Position
*/

class Solution {
public:
    
    int find(const vector<int>&nums, const int target, int left, int right){
        int mid = (left + right) / 2;
        if(nums[mid] == target)
            return mid;
        else if(right <= left){
            if(nums[left] > target)
                return left;
            else
                return left+1;
        }
        else if(nums[mid] > target)
            return find(nums, target, left, mid - 1);
        else
            return find(nums, target, mid + 1, right);
        
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return find(nums, target, 0, nums.size()-1);
    }
};