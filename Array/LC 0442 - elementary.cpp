/*
442. Find All Duplicates in an Array
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(auto &i: nums) {
            int abs_i = abs(i);
            if(nums[abs_i-1] < 0) ans.push_back(abs_i);
            nums[abs_i-1] = -nums[abs_i-1];
        }
        return ans;
    }
};