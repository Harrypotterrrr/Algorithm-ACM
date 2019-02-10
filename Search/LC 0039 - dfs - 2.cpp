/*
39. Combination Sum

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

#include "../include/include.h"

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
  
	// Each recursion is to find the `cur` with two conditions, one is `cur` contained s[i], while another doen't contain.  
    void dfs(const vector<int>& s, int i, int target){
        
        if(target == 0){
            ans.push_back(cur);
            return;
        }
        
        if(i >= s.size()) return;
        
        if(target - s[i] >= 0){
            cur.push_back(s[i]);
            dfs(s, i, target - s[i]);
            cur.pop_back();            
        }
        dfs(s, i+1, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return ans;
    }
};

int main()
{
}