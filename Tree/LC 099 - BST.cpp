/*
99. Recover Binary Search Tree
*/

// Solution 1: space O(n)

class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int>vec;
        vector<TreeNode*> ll;
        solve(root, vec, ll);
        sort(vec.begin(), vec.end());
        for(int i=0 ; i<ll.size() ; i++)
            ll[i]->val = vec[i];
        
    }
    void solve(TreeNode* node, vector<int>&vec,vector<TreeNode*> &ll){
        if(!node) return;
        solve(node->left, vec, ll);
        vec.push_back(node->val);
        ll.push_back(node);
        solve(node->right, vec, ll);
    }
    
};

// Solution 2: previous pointer, space O(n) due to the height of tree

class Solution {
public:
    TreeNode *pre=nullptr, *first=nullptr, *second=nullptr;
    void recoverTree(TreeNode* root) {
        solve(root);
        swap(first->val, second->val);
    }
    void solve(TreeNode* node){
        if(!node) return;
        solve(node->left);
        if(!pre) pre = node;
        else{
            if(pre->val > node->val){
                if(!first) first = pre;
                second = node;
            }
            pre = node;
        }
        solve(node->right);
    }
    
};

// Solution 3: TODO Morris traversal