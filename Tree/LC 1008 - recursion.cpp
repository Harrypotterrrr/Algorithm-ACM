/*
1008. Construct Binary Search Tree from Preorder Traversal
DFS, Tree, Recursion
*/

// Solution 1: dfs

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int num;
        return build(preorder, 0, INT_MIN, INT_MAX, num);
    }
    
    TreeNode* build(vector<int>& vec, int k, int left, int right, int &num){
        if(k >= vec.size() || vec[k] > right){
            num = 0;
            return nullptr;
        }
        int left_ctr = 0, right_ctr = 0;
        TreeNode* node = new TreeNode(vec[k]);
        node->left = build(vec, k+1, left, vec[k]-1, left_ctr);
        node->right = build(vec, k+1+left_ctr, vec[k]+1, right, right_ctr);
        num  = left_ctr + right_ctr + 1;
        return node;
    }
};

// Solution 2: dfs

class Solution {
public:
    
    int k = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int num;
        return build(preorder, INT_MAX);
    }
    
    TreeNode* build(vector<int>& vec, int upper){
        if(k >= vec.size() || vec[k] > upper) return nullptr;
        TreeNode* node = new TreeNode(vec[k++]);
        node->left = build(vec, vec[k-1]-1);
        node->right = build(vec, upper);
        return node;
    }
};