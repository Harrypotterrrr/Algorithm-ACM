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


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>>ans;
        std::sort(nums.begin(), nums.end());
        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};

int main()
{

}