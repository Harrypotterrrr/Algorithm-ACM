/*
15. 3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include "../include/include.h"

class Solution {
public:
    vector<vector<int>> rtn;
    
    void twoSum(vector<int> &nums, int target, int begin, int end){
        while(begin < end){
            int sum = nums[begin] + nums[end];
            if(sum > target) end--;
            else if(sum < target) begin++;
            else{
                vector<int>ans{-target, nums[begin], nums[end]};
                rtn.push_back(ans);
                
                while(begin < end && nums[begin] == ans[1]) begin++;
                while(begin < end && nums[end] == ans[2]) end--;
            }
            
        }
    }   
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for(int i=0 ; i<nums.size(); ){
            // optimize
            if(nums[i] > 0) return rtn;
            int target = -nums[i];
            twoSum(nums, target, i+1, nums.size()-1);
            while(i < nums.size() && nums[i] == -target) i++;
        }
        return rtn;
    }
};

int main()
{

}