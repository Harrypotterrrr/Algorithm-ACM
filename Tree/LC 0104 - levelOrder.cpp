/*
104. Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};


// Solution 2:  Level order traversal

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*>Q({root});
        int depth = 0, cur_ctr = 1, next_ctr = 0;
        while(!Q.empty()){
            TreeNode* cur = Q.front();
            Q.pop();
            cur_ctr--;
            if(cur->left){
                next_ctr++;
                Q.push(cur->left);
            }
            if(cur->right){
                next_ctr++;
                Q.push(cur->right);
            }
            if(!cur_ctr){
                cur_ctr = next_ctr;
                next_ctr = 0;
                depth++;
            }
        }
        return depth;
    }
};

// Solution 3: Level order traversal 2nd way

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*>Q({root});
        int depth = 0;
        while(!Q.empty()){
            for(int i=Q.size() ; i>0 ; i--){
                TreeNode* cur = Q.front();
                Q.pop();
                if(cur->left)
                    Q.push(cur->left);
                if(cur->right)
                    Q.push(cur->right);
            }
            depth++;
        }
        return depth;
    }
};