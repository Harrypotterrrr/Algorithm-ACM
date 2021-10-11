/*
543. Diameter of Binary Tree
*/

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
class Solution {
public:
    
    int ans = 0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
    
    int solve(TreeNode* node){
        int left = 0, right = 0;
        if(node->left) left = solve(node->left) + 1;
        if(node->right) right = solve(node->right) + 1;
        ans = ans > left + right? ans : left + right;
        return left > right ? left: right;
    }
};