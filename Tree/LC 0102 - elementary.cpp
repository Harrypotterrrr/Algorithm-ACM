/*
102. Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*>Q({root});
        while(!Q.empty()){
            vector<int>tmp;
            for(int i=Q.size() ; i>0 ; i--){
                TreeNode* cur = Q.front(); Q.pop();
                tmp.push_back(cur->val);
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};


// Solution 2: recursive way

class Solution {
public:
    
    vector<vector<int>> ans;
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        levelOrder(root, 0);
        return ans;
    }
    
    void levelOrder(TreeNode* node, int level){
        if(!node)
            return;
        if(ans.size() <= level)
            // ans.push_back(vector<int>());
            ans.push_back({});
        ans[level].push_back(node->val);
        levelOrder(node->left, level + 1);
        levelOrder(node->right, level + 1);
    }
};

