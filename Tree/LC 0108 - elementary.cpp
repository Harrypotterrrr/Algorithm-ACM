/*
108. Convert Sorted Array to Binary Search Tree
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
    
    TreeNode* buildTree(vector<int>&nums, int start, int end) {
        
        if(start > end)
            return nullptr;
        int mid = start + ((end - start) >> 1);
        
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildTree(nums,start, mid-1);
        node->right = buildTree(nums,mid+1, end);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() -1);
    }
};


// Solution 2:

class Solution {
public:
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.empty())
            return nullptr;
        
        int mid = nums.size() >> 1;
        
        TreeNode* node = new TreeNode(nums[mid]);
        vector<int> left_nums(nums.begin(),nums.begin() + mid);
        vector<int> right_nums(nums.begin() + mid + 1, nums.end());
        node->left = sortedArrayToBST(left_nums);
        node->right = sortedArrayToBST(right_nums);
        return node;
    }
};