/*
437. Path Sum III
Tree, Hashmap, PrefixSum
*/


// Solution 1: O(n^2)

class Solution {
public:
    
    
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        vector<long>S({0});
        int ctr = 0;
        solve(root, S, targetSum, ctr);
        return ctr;
    }
    
    void solve(TreeNode* node, vector<long>&S, int targetSum, int &ctr) {
        if(!node) return;
        S.push_back(S.back() + node->val);
        solve(node->left, S, targetSum, ctr);
        solve(node->right, S, targetSum, ctr);
        for(int i=0 ; i<S.size()-1 ; i++)
            if(S.back() - S[i] == targetSum)
                ctr++;
        S.pop_back();
    }
};

// Solution 2: Hashmap, recursion O(n)

class Solution {
public:
    
    
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        unordered_map<int, int>uM({{0, 1}});
        int prefix = 0, ctr = 0;
        solve(root, uM, prefix, targetSum, ctr);
        return ctr;
    }
    
    void solve(TreeNode* node, unordered_map<int, int>&uM, int &prefix, int targetSum, int &ctr) {
        if(!node) return;
        prefix += node->val;
        ctr += uM[prefix - targetSum];
        uM[prefix] ++;
        solve(node->left, uM, prefix, targetSum, ctr);
        solve(node->right, uM, prefix, targetSum, ctr);
        uM[prefix] --;
        prefix -= node->val;
    }
};