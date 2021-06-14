/*
145. Binary Tree Postorder Traversal
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
    
    void postorder(TreeNode* node){
        if(!node)
            return;
        postorder(node->left);
        postorder(node->right);
        ans.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
};

// Solution 2: iterative way
// create new struct by adding flag to check the second visited node

class Solution {
public:
    
    struct sTreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        bool flag;
        sTreeNode(TreeNode* t) {
            val = t->val;
            left = t->left;
            right = t->right;
            flag = false;
        }
    };
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        stack<sTreeNode*>S;
        TreeNode *p = root;
        while(p || !S.empty()){
            while(p){
                sTreeNode *node = new sTreeNode(p);
                S.push(node);
                p = p->left;
            }
            sTreeNode *cur = S.top();
            if(!cur->flag){
                p = cur->right;
                cur->flag = true;
            }
            else{
                ans.push_back(cur->val);
                S.pop();
            }
        }
        return ans;
    }
};

// Solution 3: another iterative way
// set the pointer left and right subtree to nullptr to label the second visited node

class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        TreeNode *p = root;
        stack<TreeNode*>S({root});
        
        while(!S.empty()){
            TreeNode *cur = S.top();
            if(!cur->left && !cur->right){
                S.pop();
                ans.push_back(cur->val);
            }
            if(cur->right){
                S.push(cur->right);
                cur->right = nullptr;
            }
            if(cur->left){
                S.push(cur->left);
                cur->left = nullptr;
            }
        }
        return ans;
    }
};

// Solution 4: a bit optimization
// create pre pointer to record the previous node

class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        TreeNode *p = root, *pre = root;
        stack<TreeNode*>S({root});
        
        while(!S.empty()){
            TreeNode *cur = S.top();
            if((!cur->left && !cur->right) || cur->left == pre || cur->right == pre){
                S.pop();
                ans.push_back(cur->val);
                pre = cur;
            }
            else{
                if(cur->right) S.push(cur->right);
                if(cur->left) S.push(cur->left);
            }
        }
        return ans;
    }
};

// Solution 5: reverse of node->right->left

class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        
        deque<int>dQ;
        stack<TreeNode*>S({root});
        
        while(!S.empty()){
            TreeNode *cur = S.top(); S.pop();
            dQ.push_back(cur->val);
            if(cur->left) S.push(cur->left);
            if(cur->right) S.push(cur->right);
        }
        return vector<int>(dQ.rbegin(), dQ.rend());
    }
};