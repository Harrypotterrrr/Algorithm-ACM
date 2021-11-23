/************************************************
Problem: 		425. Word Squares
Algorithm: 		Tree, BST, Recursion, Iteration
Difficulty: 	***
Importance:		***
Remark:			
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

// Solution 1: Iteration

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *dummy = new TreeNode(INT_MAX, root, nullptr);
        TreeNode*p = root, *pre = dummy;
        bool is_left = true;
        // find the key node
        while(p && p->val != key){
            pre = p;
            if(p->val < key){
                p = p->right;
                is_left = false;
            }
            else {
                p = p->left;
                is_left = true;
            }
        }
        if(!p) return root;
        
        auto solve = [](TreeNode *key_right, TreeNode *p){
            if(key_right && p->right){
                TreeNode *tmp = key_right;
                while(tmp->left) tmp = tmp->left;
                tmp->left = p->right;
                p->right = key_right;
            }
            else if(key_right){
                p->right = key_right;
            }
        };
        
        if(is_left){
            if(p->left){
                TreeNode *key_right = p->right;
                pre->left = p->left;
                // delete p;
                p = pre->left;
                solve(key_right, p);
            }
            else{
                pre->left = p->right;
                // delete p;
            }
        }
        else{
            if(p->left){
                TreeNode *key_right = p->right;
                pre->right = p->left;
                // delete p;
                p = pre->right;
                solve(key_right, p);
            }
            else{
                pre->right = p->right;
                // delete p;
            }
        }
        return dummy->left;
    }
};

// Solution 2: Recursion

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root) return nullptr;
        if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        else{
            if(!root->left) return root->right;
            TreeNode *tmp = root->left, *pre;
            while(tmp && tmp->right) {
                pre = tmp;
                tmp = tmp->right;
            }
            if(tmp == root->left){
                root->val = tmp->val;
                root->left = tmp->left;
            }
            else{
                root->val = tmp->val;
                tmp = tmp->left;
                pre->right = tmp;
            }           
        }
        return root;
    }
};

// Solution 3: best recrusion 

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root) return nullptr;
        if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        else{
            if(!root->left && !root->right) return nullptr;
            if(!root->left || !root->right) return root->left ? root->left : root->right;
            
            TreeNode *tmp = root->left;
            while(tmp->right) tmp = tmp->right;
            root->val = tmp->val;
            root->left = deleteNode(root->left, root->val);
        }
        return root;
    }
};
