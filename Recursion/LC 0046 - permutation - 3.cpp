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
    void getNextPermutation(vector<int>V, int k){
        if(k == V.size() - 1) {
            ans.push_back(V);
            return;
        }
        for(int i = k; i<V.size() ; i++){
            swap(V[k], V[i]);
            getNextPermutation(V, k + 1);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>V;
        for(int i=0 ; i<nums.size() ; i++) V.push_back(nums[i]);
        getNextPermutation(V, 0);
        return ans;
    }
};

int main()
{

}