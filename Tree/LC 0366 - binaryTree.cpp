/************************************************
Problem: 		366. Find Leaves of Binary Tree
Algorithm: 		Tree, DFS
Difficulty: 	**
Importance:		*
Remark:			
*************************************************/

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        
        function<int(TreeNode*)> solve = [&](TreeNode *node){
            if(!node) return 0;
            int left = solve(node->left) + 1;
            int right = solve(node->right) + 1;
            int depth = left > right ? left : right;
            if(ans.size() < depth) ans.push_back({node->val});
            else ans[depth-1].push_back({node->val});
            return depth;
        };
        solve(root);
        return ans;
    }
};