/*
94. Binary Tree Inorder Traversal
*/

// Solution 1: recursion

class Solution {
public:
    
    vector <int> ans;
    
    void inorder(TreeNode* node){
        if(!node)
            return;
        inorder(node->left);
        ans.push_back(node->val);
        inorder(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};

// Solution 2: iteration

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>S;
        TreeNode *p = root, *cur = p;
        while(p || !S.empty()){
            while(p){
                S.push(p);
                p = p->left;
            }
            TreeNode* cur = S.top(); S.pop();
            ans.push_back(cur->val);
            p = cur->right;
        }
        return ans;
    }
};

// Solution 3: iteration in another way

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>S;
        TreeNode *p = root, *cur = p;
        while(p || !S.empty()){
            if(p){
                S.push(p);
                p = p->left;
            }
            else{
                TreeNode* cur = S.top(); S.pop();
                ans.push_back(cur->val);
                p = cur->right;
            }
        }
        return ans;
    }
};