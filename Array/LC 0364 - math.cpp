/************************************************
Problem: 		339. Nested List Weight Sum
Algorithm: 		Array, DFS
Difficulty: 	*
Importance:		***
Remark:			
*************************************************/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// Solution 1: double-pass dfs

class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int ans = 0, max_level = 0;
        function<void(vector<NestedInteger>&, int)> get_max = [&max_level, &get_max](vector<NestedInteger>& nested, int level){
            int n = nested.size();
            for(auto &cur: nested){
                if(cur.isInteger()) max_level = max_level > level ? max_level : level;
                else get_max(cur.getList(), level+1);
            }
        };
        function<void(vector<NestedInteger>&, int)> solve = [&max_level, &ans, &solve](vector<NestedInteger>& nested, int level){
            int n = nested.size();
            for(auto &cur: nested){
                if(cur.isInteger()) ans += (max_level - level + 1) * cur.getInteger();
                else solve(cur.getList(), level+1);
            }
        };
        get_max(nestedList, 1);
        solve(nestedList, 1);
        return ans;
    }
};

// Solution 2: single-pass dfs, rewrite the equation

class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int ans = 0, max_level = 0, summ = 0;
        
        function<void(vector<NestedInteger>&, int)> solve = [&summ, &max_level, &ans, &solve](vector<NestedInteger>& nested, int level){
            int n = nested.size();
            for(auto &cur: nested){
                if(cur.isInteger()) {
                    ans += (level - 1) * cur.getInteger();
                    summ += cur.getInteger();
                    max_level = max_level >level ? max_level : level;
                }
                else solve(cur.getList(), level+1);
            }
        };
        solve(nestedList, 1);
        return summ * max_level - ans;
    }
};