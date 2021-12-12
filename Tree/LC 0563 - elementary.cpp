/************************************************
Problem: 		563. Binary Tree Tilt
Algorithm: 		Tree, Recursion
Difficulty: 	*
Importance:		*
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
class Solution {
public:
    int findTilt(TreeNode* root) {
        
        int ans = 0;
        
        function <int(TreeNode*)> solve = [&solve, &ans](TreeNode* node){
            if(!node) return 0;
            int left_sum = solve(node->left), right_sum = solve(node->right);
            int summ = node->val + left_sum + right_sum;
            ans += abs(left_sum - right_sum);
            return summ;
        };
        
        solve(root);
        return ans;
    }
};