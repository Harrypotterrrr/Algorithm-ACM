/*
47. Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

#include "../include/include.h"

class Solution {
public:
    
    vector<vector<int>>ans;
    vector<int>cur;
    void getNextPermutation(int begin){
        if(begin == cur.size()){
            ans.push_back(cur);
            return;
        }
        for(int i=begin ; i<cur.size() ; i++){
            if(i != begin && cur[begin] == cur[i]) continue;
            swap(cur[begin], cur[i]);
            getNextPermutation(begin+1);
        }

        // resorted the array
        for(int i=begin ; i <cur.size() - 1 ; i++)
            swap(cur[i], cur[i+1]);
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for(auto i=0 ; i<nums.size() ; i++) cur.push_back(nums[i]);
        getNextPermutation(0);
        return ans;
    }
};

int main()
{

}