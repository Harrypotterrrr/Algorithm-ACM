/*
40. Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

#include "../include/include.h"

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    
    void dfs(const vector<int>& s, int st, int target){
        
        if(target == 0){
            ans.push_back(cur);
            return;
        }
        
        for(int i=st ; i<s.size() ; i++){
            if(target - s[i] < 0) break;
            if(i > st && s[i] == s[i-1]) continue;
            cur.push_back(s[i]);
            dfs(s, i+1, target - s[i]);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return ans;
    }
};
int main()
{
}