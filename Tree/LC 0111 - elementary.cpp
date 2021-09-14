/*
110. Balanced Binary Tree
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

 // Solution 1: recursion

class Solution {
public:
    
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left)
            return minDepth(root->right) + 1;
        if(!root->right)
            return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

// Solution 2: iteration

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
    
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> Q({root});
        int ans = 0;
        while(!Q.empty()){
            ans ++;
            for(int i=Q.size()-1 ; i>=0 ; i--){
                TreeNode *node = Q.front(); Q.pop();
                if(!node->left && !node->right) return ans;
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
            }
        }
        return ans;
    }
};