/*
112. Path Sum
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        if(!root->right && !root->left && targetSum == root->val)
            return true;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

// Solution 2: iteration:

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root)
            return false;
        
        queue<TreeNode*> Q({root});
        while(!Q.empty()){
            TreeNode *cur = Q.front();
            Q.pop();
            if(!cur->right && !cur->left && cur->val == targetSum)
                return true;
            if(cur->right){
                cur->right->val += cur->val;
                Q.push(cur->right);
            }
            if(cur->left){
                cur->left->val += cur->val;
                Q.push(cur->left);
            }
        }
        return false;
    }
};