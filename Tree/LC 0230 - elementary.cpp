/*
230. Kth Smallest Element in a BST
*/

// Solution 1: build vector O(n) space and time

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>vec;
        dfs(vec, root);
        return vec[k-1];
    }
    
    void dfs(vector<int>&vec, TreeNode* node){
        if(!node)
            return;
        dfs(vec, node->left);
        vec.push_back(node->val);
        dfs(vec, node->right);
    }
};

// Solution 2: iteration to optimize the time complexity to O(n)

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>S;
        TreeNode *p = root;
        while(p || !S.empty()){
            while(p){
                S.push(p);
                p = p->left;
            }
            TreeNode *cur = S.top(); S.pop();
            if(!--k) return cur->val;
            // cout<<cur->val<<endl;
            p = cur->right;
        }
        return -1;
    }

};