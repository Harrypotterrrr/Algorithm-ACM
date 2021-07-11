/*
101. Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return false;
        return solve(root->left, root->right);
    }
    
    bool solve(TreeNode* lnode, TreeNode* rnode){
        if(lnode && rnode){
            if(lnode->val != rnode->val)
                return false;
            return solve(lnode->left, rnode->right) && solve(lnode->right, rnode->left);
        }
        if(!lnode && !rnode)
            return true;
        return false;
    }
};


// Solution 2: iteration

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> Q({root->left}), P({root->right});
        while(!Q.empty() && !P.empty()){
            TreeNode *q = Q.front();
            Q.pop();
            TreeNode *p = P.front();
            P.pop();
            if(!q && !p)
                continue;
            if(!q || !p)
                return false;
            if(p->val != q->val)
                return false;
            Q.push(q->left);
            P.push(p->right);
            Q.push(p->left);
            P.push(q->right);
        }
        return true;
    }
};