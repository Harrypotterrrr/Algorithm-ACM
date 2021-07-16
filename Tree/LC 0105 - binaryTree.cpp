/*
105. Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pl = 0;
        return solve(preorder, inorder, pl, 0, inorder.size() - 1);
    }
    
    TreeNode* solve(vector<int>& pre, vector<int>& in, int& pl, int il, int ir){
        if(il > ir || pl >= pre.size())
            return nullptr;
        TreeNode *node = new TreeNode(pre[pl]);
        int in_id = search(in, pre[pl], il, ir);
        pl += 1;
        node->left = solve(pre, in, pl, il, in_id - 1);
        node->right = solve(pre, in, pl, in_id + 1, ir);
        return node;
    }
    
    int search(vector<int>& vec, int target, int left, int right){
        for(int i=left; i<=right ; i++)
            if(vec[i] == target)
                return i;
        return -1;
    }
};


// Solution 2: a bit optimization, discard the reference

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, inorder, 0, preorder.size() -1, 0, inorder.size() - 1);
    }
    
    TreeNode* solve(vector<int>& pre, vector<int>& in, int pl, int pr, int il, int ir){
        if(il > ir || pl > pr)
            return nullptr;
        TreeNode *node = new TreeNode(pre[pl]);
        int in_id = search(in, pre[pl], il, ir);
        node->left = solve(pre, in, pl+1, pl+in_id-il, il, in_id - 1);
        node->right = solve(pre, in, pl+in_id-il+1, pr, in_id + 1, ir);
        return node;
    }
    
    int search(vector<int>& vec, int target, int left, int right){
        for(int i=left; i<=right ; i++)
            if(vec[i] == target)
                return i;
        return -1;
    }
};