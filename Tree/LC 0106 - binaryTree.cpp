/************************************************
Problem: 		106. Construct Binary Tree from Inorder and Postorder Traversal
Algorithm: 		Tree, Recursion
Difficulty: 	**
Importance:		**
Remark:			
*************************************************/

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

// Solution 1: linear search

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

// Solution 2: unorder_map optimization

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	unordered_map<int, int>uM;
	int n = inorder.size();
	for(int i=0 ; i<n ; i++) uM[inorder[i]] = i;
	function<TreeNode*(int, int, int)> solve = [&](int inorder_left, int inorder_right, int post_right) ->TreeNode* {
		if(inorder_left > inorder_right) return nullptr;
		TreeNode *node = new TreeNode(postorder[post_right]);
		int inorder_id = uM[node->val];
		node->left = solve(inorder_left, inorder_id-1, post_right - inorder_right + inorder_id - 1);
		node->right = solve(inorder_id+1, inorder_right, post_right-1);
		return node;
	};
	return solve(0, n-1, n-1);
    }
};