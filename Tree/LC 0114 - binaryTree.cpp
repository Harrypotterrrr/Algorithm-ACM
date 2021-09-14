/*
114. Flatten Binary Tree to Linked List
*/

// Solution 1: recursion

class Solution {
public:
    void flatten(TreeNode* root) {
        solve(root);
    }
    
    TreeNode* solve(TreeNode* node){
        if(!node) return nullptr;
        if(!node->left && !node->right) return node;
        TreeNode *last ;
        
        if(node->left){
            last = solve(node->left);
            last->right = node->right;
            if(node->right)
                last = solve(node->right);
            node->right = node->left;
            node->left = nullptr;
            return last;
        }
        else{
            return solve(node->right);
        }
    }
};


// Solution 2: recursion in other way

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* tmp = root->left;
        if(tmp){
            while(tmp && tmp->right) tmp = tmp->right;
            tmp->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
    
};

// Solution 3: iteration

class Solution {
public:
    void flatten(TreeNode* root) {
        
        TreeNode *cur = root;
        while(cur){
            if(cur->left){
                TreeNode *tmp = cur->left;
                while(tmp->right) tmp = tmp->right;
                tmp->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};