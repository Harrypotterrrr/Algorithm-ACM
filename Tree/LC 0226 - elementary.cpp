/*
226. Invert Binary Tree
Tree, Recursion
*
*/


// Solution 1: recursive way

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode *tmp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = tmp;
        return root;
    }
};

// Solution 2: interative way

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        queue<TreeNode*> Q({root});
        while(!Q.empty()){
            TreeNode* cur = Q.front(); Q.pop();
            TreeNode* tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
            if(cur->left) Q.push(cur->left);
            if(cur->right) Q.push(cur->right);
        }
        return root;
        
    }
};