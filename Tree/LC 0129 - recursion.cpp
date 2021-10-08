/*
129. Sum Root to Leaf Numbers
*/

// Solution 1: recursion

class Solution {
public:
    
    int ans = 0;
    
    int sumNumbers(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
    
    void solve(TreeNode* node, int cur){
        if(!node) return;
        cur = cur * 10 + node->val;
        if(!node->left && !node->right){
            ans += cur;
            return;
        }
        solve(node->left, cur);
        solve(node->right, cur);
    }
};

// Solution 2: int function, no global variable

class Solution {
public:
    
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
    
    int solve(TreeNode* node, int cur){
        if(!node) return 0;
        cur = cur * 10 + node->val;
        if(!node->left && !node->right) return cur;
        return solve(node->left, cur) + solve(node->right, cur);
    }
};

// Solution 3: preorder iteration

class Solution {
public:
    
    int sumNumbers(TreeNode* root) {
        
        if(!root) return 0;
        stack<TreeNode*> S({root});
        int ans = 0, tmp = 0;
        TreeNode* p;
        while(!S.empty()){
            p = S.top(); S.pop();
            if(!p->left && !p->right)
                ans += p->val;
            if(p->right){
                p->right->val = p->val * 10 + p->right->val;
                S.push(p->right);
            }
            if(p->left){
                p->left->val = p->val * 10 + p->left->val;
                S.push(p->left);
            }
        }
        return ans;
    }
    
};