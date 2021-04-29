/*
110. Balanced Binary Tree
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
    
    
    int recursion(TreeNode* node) {
        if(!node)
            return 0;
        int left_num = recursion(node->left);
        if(left_num == -1)
            return -1;
        int right_num = recursion(node->right);
        if(right_num == -1 || abs(left_num - right_num) > 1)
            return -1;
        return max(left_num, right_num) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(recursion(root) == -1)
            return false;
        return true;
    }
};