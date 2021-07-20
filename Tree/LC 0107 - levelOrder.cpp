/*
107. Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
            // ans.insert(ans.begin(), tmp);
            ans.push_back(tmp);
        }
        for(int i=0 ; i<(ans.size()>>1) ; i++)
            swap(ans[i], ans[ans.size() - 1 - i]);
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Solution 2: recursion then reverse

class Solution {
public:
    
    vector<vector<int>> ans;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        levelOrder(root, 0);
        return vector<vector<int>>(ans.rbegin(), ans.rend());
    }
    void levelOrder(TreeNode* node, int level){
        if(!node)
            return;
        if(ans.size() <= level)
            ans.push_back({});
        ans[level].push_back(node->val);
        levelOrder(node->left, level + 1);
        levelOrder(node->right, level + 1);
    }
};