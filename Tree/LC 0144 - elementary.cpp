/*
144. Binary Tree Preorder Traversal
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
    vector<int>ans;
    
    void preorder(TreeNode* node){
        if(node){
            ans.push_back(node->val);
            preorder(node->left);
            preorder(node->right);           
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }
};


// Solution 2: iterative way

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        stack<TreeNode*> S({root});
        
        while(!S.empty()){
            TreeNode* cur = S.top(); S.pop();
            ans.push_back(cur->val);
            if(cur->right) S.push(cur->right);
            if(cur->left) S.push(cur->left);
        }
        return ans;
    }
};
