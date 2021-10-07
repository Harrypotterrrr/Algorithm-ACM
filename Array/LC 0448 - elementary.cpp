/*
448. Find All Numbers Disappeared in an Array
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        for(auto &i: nums){
            int abs_i = i > 0 ? i : -i;
            nums[abs_i-1] = nums[abs_i-1] > 0 ? -nums[abs_i-1] : nums[abs_i-1];
        }
        for(int i=0 ; i<nums.size() ; i++)
            if(nums[i] > 0)
                ans.push_back(i+1);
        return ans;
    }
};