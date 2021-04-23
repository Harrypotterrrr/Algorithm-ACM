/*
95. Unique Binary Search Trees II
 */

class Solution {
public:
    
    vector<TreeNode*> dfs(int start, int end){
        if(start > end){
            return vector<TreeNode*>({nullptr});
            // return {nullptr};
        }
        vector<TreeNode*> rtn;
        for(int k=start ; k<=end ; k++){
            auto left_tree_list = dfs(start, k-1);
            auto right_tree_list = dfs(k+1, end);
            for(auto &i : left_tree_list){
                for(auto &j : right_tree_list){
                    TreeNode *root = new TreeNode(k);
                    root->left = i;
                    root->right = j;
                    rtn.push_back(root);
                }
            }
        }
        return rtn;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
};

// Solution 2: using memory array to optimize time

class Solution {
public:
    
    vector<TreeNode*> dfs(vector<vector<vector<TreeNode*>>> &memory, int start, int end){
        if(start > end)
            return vector<TreeNode*>({nullptr});
            // return {nullptr};
        if(!memory[start-1][end-1].empty())
            return memory[start-1][end-1];
        
        vector<TreeNode*> rtn;
        for(int k=start ; k<=end ; k++){
            auto left_tree_list = dfs(memory, start, k-1);
            auto right_tree_list = dfs(memory, k+1, end);
            for(auto &i : left_tree_list){
                for(auto &j : right_tree_list){
                    TreeNode *root = new TreeNode(k);
                    root->left = i;
                    root->right = j;
                    rtn.push_back(root);
                }
            }
        }
        memory[start-1][end-1] = rtn;
        return rtn;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> memory(n, vector<vector<TreeNode*>>(n));
        return dfs(memory, 1, n);
    }
};
