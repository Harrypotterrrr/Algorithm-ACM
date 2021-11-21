/************************************************
Problem: 		1110. Delete Nodes And Return Forest
Algorithm: 		Tree, BFS, DFS
Difficulty: 	**
Importance:		****
Remark:			level order traversal
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

// Solution 1: level order traversal, check fewer times, but ugly code

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return {};
        queue<pair<TreeNode*, pair<bool, bool>>> Q;
        unordered_set<int>uS(to_delete.begin(), to_delete.end());
        auto it = uS.find(root->val);        
        if(it != uS.end()) Q.push({root, {true, false}});
        else Q.push({root, {false, true}});
        vector<TreeNode*> ans;
        while(!Q.empty()){
            for(int i= Q.size()-1 ; i>=0 ; i--){
                auto [cur, flag] = Q.front(); Q.pop();
                auto [del_flag, new_flag] = flag;
                if(cur->left){
                    it = uS.find(cur->left->val);
                    if(it != uS.end()){
                        Q.push({cur->left, {true, false}});
                        cur->left = nullptr;
                    }
                    else Q.push({cur->left, {false, del_flag}});
                }

                if(cur->right){
                    it = uS.find(cur->right->val);
                    if(it != uS.end()){
                        Q.push({cur->right, {true, false}});
                        cur->right = nullptr;
                    }
                    else Q.push({cur->right, {false, del_flag}});
                }
                if(new_flag) ans.push_back(cur);
            }
        }
        return ans;
        
    }
};

// Solution 2: more elegant of level traversal

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return {};
        unordered_set<int> uS(to_delete.begin(), to_delete.end());
        queue<pair<TreeNode*, bool>> Q({{root, false}});
        vector<TreeNode*> ans;
        while(!Q.empty()){
            for(int i=Q.size()-1 ; i>=0 ; i--){
                auto [cur, has_parent] = Q.front(); Q.pop();
                bool cur_exist = (uS.find(cur->val) == uS.end());
                if(cur->left){
                    Q.push({cur->left, cur_exist});
                    if(uS.find(cur->left->val) != uS.end()) cur->left = nullptr;
                }
                if(cur->right){
                    Q.push({cur->right, cur_exist});
                    if(uS.find(cur->right->val) != uS.end()) cur->right = nullptr;
                }
                if(!has_parent && cur_exist) ans.push_back(cur);
            }
        }
        return ans;
        
    }
};

// Solution 3: DFS, find more times in uS


class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_set<int>uS(to_delete.begin(), to_delete.end());

        function<void(TreeNode*, bool)> dfs = [&](TreeNode* node, bool has_parent){
            if(!node) return;
            bool cur_exist = uS.find(node->val) == uS.end();
            if(node->left){
                dfs(node->left, cur_exist);
                if(uS.find(node->left->val) != uS.end())
                    node->left = nullptr;
            }
            if(node->right){
                dfs(node->right, cur_exist);
                if(uS.find(node->right->val) != uS.end())
                    node->right = nullptr;
            }
            if(!has_parent && cur_exist)
            ans.push_back(node);
        };
        dfs(root, false);
        return ans;
    }
};

// Solution 4: DFS, more elegant and fewer find times in uS because of modifier of the content of the pointer node

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_set<int>uS(to_delete.begin(), to_delete.end());

        function<TreeNode*(TreeNode*, bool)> dfs = [&](TreeNode* node, bool has_parent) -> TreeNode*{
            if(!node) return nullptr;
            bool cur_exist = uS.find(node->val) == uS.end();
            if(!has_parent && cur_exist) ans.push_back(node);
            if(node->left) node->left = dfs(node->left, cur_exist);
            if(node->right) node->right = dfs(node->right, cur_exist);
            return cur_exist ? node : nullptr;
        };
        dfs(root, false);
        return ans;
    }
};
