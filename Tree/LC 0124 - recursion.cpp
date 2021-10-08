/*
124. Binary Tree Maximum Path Sum
*/

// Solution 1: recursion

class Solution {
public:
    
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        int maxn = INT_MIN;
        solve(root, maxn);
        return ans;
    }
    
    void solve(TreeNode *node, int &maxn){
        if(!node){
            maxn = 0;
            return;
        }
        int left_max = INT_MIN, right_max = INT_MIN;
        solve(node->left, left_max);
        solve(node->right, right_max);
        maxn = maxn > node->val ? maxn : node->val;
        int tmp = left_max > right_max ? left_max : right_max;
        maxn = maxn > tmp + node->val ? maxn : tmp + node->val;
        
        ans = ans > maxn ? ans : maxn;
        ans = ans > node->val + left_max + right_max ? ans : node->val + left_max + right_max;
    }
};