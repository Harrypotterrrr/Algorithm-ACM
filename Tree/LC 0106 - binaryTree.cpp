/*
106. Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    
    TreeNode* solve(vector<int>& in, vector<int>& post, int il, int ir, int pl, int pr){
        if(il > ir || pl > pr)
            return nullptr;
        TreeNode* node = new TreeNode(post[pr]);
        int in_id = search(in, post[pr], il, ir);
        node->left = solve(in, post, il, in_id-1, pl, pr-ir+in_id-1);
        node->right = solve(in, post, in_id+1, ir, pr-ir+in_id, pr-1);
        return node;
    }
    
    int search(vector<int>&vec, int target, int left, int right){
        for(int i=left; i<=right ; i++)
            if(vec[i] == target)
                return i;
        return -1;
    }
};