/*
216. Combination Sum III

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]

Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

#include "../include/include.h"

class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int>cur;
    void dfs(int target, int st, int k){
        if(k == 0 && target == 0) ans.push_back(cur);
        else if(k <= 0) return;
        else {
            for(int i=st ; i<=9 ; i++){
                if(target - i < 0) return;
                cur.push_back(i);
                dfs(target - i, i+1, k-1);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(n, 1, k);
        return ans;
    }
};

int main()
{
}