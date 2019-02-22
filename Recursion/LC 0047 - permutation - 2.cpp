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
    
    void getNextPermutation(vector<int>cur, int begin){
        if(begin == cur.size()){
            ans.push_back(cur);
            return;
        }
        for(int i=begin ; i<cur.size() ; i++){
            if(i != begin && cur[begin] == cur[i]) continue;
            swap(cur[begin], cur[i]);
            getNextPermutation(cur, begin+1);
            // swap(cur[begin], cur[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        getNextPermutation(nums, 0);
        return ans;
    }
};

int main()
{

}