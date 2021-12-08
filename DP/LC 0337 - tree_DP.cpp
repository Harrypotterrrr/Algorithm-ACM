/************************************************
Problem: 		213. House Robber II
Algorithm: 		Dynamic Programming, Recursion
Difficulty: 	***
Importance:		***
Remark:			tree dp
*************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Solution 1: Recursion

class Solution {
public:
    
    unordered_map<TreeNode*, int>take, not_take;
    
    int rob(TreeNode* root) {
        
        function<int(TreeNode*, bool)> solve = [&](TreeNode* node, bool can_take){
            if(!node) return 0;
            if(can_take && take[node]) return take[node];
            if(!can_take && not_take[node]) return not_take[node];
            
            not_take[node] = solve(node->left, true) + solve(node->right, true);
            take[node] = max(solve(node->left, false) + solve(node->right, false) + node->val, not_take[node]);

            if(can_take) return take[node];
            return not_take[node];
        };
        return solve(root, true);
    }
};