/*
98. Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
    
    bool solve(TreeNode* node, long minn, long maxn){
        if(!node)
            return true;
        if(node->val >= maxn || node->val <= minn)
            return false;
        return solve(node->left, minn, node->val) && solve(node->right, node->val, maxn);
        
    }
};

// Solution 2: build a vector to check sequence: 
// some binary search tree is defined as left <= mid < right, then the above method not work

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int>tmp;
        checkBST(root, tmp);
        for(int i=1 ; i<tmp.size() ; i++){
            if(tmp[i] <= tmp[i-1])
                return false;
        }
        return true;
    }
    
    void checkBST(TreeNode* node, vector<int>&vec){
        if(!node)
            return;
        checkBST(node->left, vec);
        vec.push_back(node->val);
        checkBST(node->right, vec);
    }
};

// Solution 3: maintain the value of the previous node, and compare it with the current node

class Solution {
public:
    
    long pre;
    
    bool isValidBST(TreeNode* root) {
        pre = LONG_MIN;
        return inorderCheck(root);
    }
    
    bool inorderCheck(TreeNode* node){
        if(!node)
            return true;
        
        if(!inorderCheck(node->left))
            return false;
        if(pre >= node->val)
            return false;
        pre = node->val;
        return inorderCheck(node->right);
    }
}

// Solution 4: use pointer reference to maintain the previous node

class Solution {
public:
    
    bool isValidBST(TreeNode* root) {
        TreeNode *pre = nullptr;
        return inorderCheck(root, pre);
    }
    
    bool inorderCheck(TreeNode* node, TreeNode*& pre){
       if(!node)
           return true;
        if(!inorderCheck(node->left, pre))
            return false;
        if(pre && pre->val >= node->val)
            return false;
        pre = node;
        return inorderCheck(node->right, pre);
    }
};

// Solution 5: use iteration and stack to inorder


class Solution {
public:
    
    bool isValidBST(TreeNode* root) {
        
        TreeNode *p = root, *pre = nullptr;
        stack<TreeNode*>S;
        while(!S.empty() || p){
            while(p){
                S.push(p);
                p = p->left;
            }
            TreeNode *cur = S.top(); S.pop();
            if(pre && pre->val >= cur->val)
                return false;
            pre = cur;
            p = cur->right;
        }
        return true;
    }

};