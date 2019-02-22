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
    vector<int> V, cur;
    vector<bool> flag;
    
    void getNextPermutation(int begin){
        if(begin == V.size()){
            ans.push_back(cur);
            return;
        }
        for(int i=0 ; i<V.size() ; i++){
            if(flag[i] == false) continue;
            if(i > 0 && V[i] == V[i-1] && flag[i-1] == true) continue;
            flag[i] = false;
            cur.push_back(V[i]);
            getNextPermutation(begin + 1);
            flag[i] = true;
            cur.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for(auto i=0 ; i<nums.size() ; i++){
            V.push_back(nums[i]);
            flag.push_back(true);
        }
        getNextPermutation(0);
        return ans;
    }
};

int main()
{

}