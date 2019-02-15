/*
46. Permutations

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

#include "../include/include.h"

class Solution {
public:
    vector<vector<int>> ans;
    vector<int>V, cur, flag;
    void getNextPermutation(int k){
        if(k == V.size()) {
            ans.push_back(cur);
            return;
        }
        for(int i = 0 ; i<V.size() ; i++){
            if(flag[i] == true) continue;
            cur.push_back(V[i]);
            flag[i] = true;
            getNextPermutation(k+1);
            cur.pop_back();
            flag[i] = false;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        for(int i=0 ; i<nums.size() ; i++) {
            flag.push_back(false);
            V.push_back(nums[i]);
        }
        getNextPermutation(0);
        return ans;
    }
};

int main()
{

}