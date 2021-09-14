/*
113. Path Sum II
*/

// Solution 1: recursion

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>tmp;
        dfs(root, targetSum, tmp);
        return ans;
    }
    
    void dfs(TreeNode* node, int targetSum, vector<int>&cur){
        if(!node) return;
        cur.push_back(node->val);
        if(!node->left && !node->right && targetSum == node->val){
            ans.push_back(cur);
        }
        dfs(node->left, targetSum - node->val, cur);
        dfs(node->right, targetSum - node->val, cur);
        cur.pop_back();
    }
};

// Solution 2: TODO iteration
