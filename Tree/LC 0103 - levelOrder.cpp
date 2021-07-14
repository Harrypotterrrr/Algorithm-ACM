/*
103. Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> Q({root});
        bool flag = false;
        while(!Q.empty()){
            vector<int>tmp;
            for(int i=Q.size() ; i>0 ; i--){
                TreeNode* cur = Q.front(); Q.pop();
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
                tmp.push_back(cur->val);

            }
            if(flag)
                reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            flag = !flag;
        }
        return ans;
    }
};

// Solution 2: optimization of reverse op

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> Q({root});
        bool flag = false;
        while(!Q.empty()){
            deque<int>tmp;
            for(int i=Q.size() ; i>0 ; i--){
                TreeNode* cur = Q.front(); Q.pop();
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
                if(flag)
                    tmp.push_front(cur->val);
                else
                    tmp.push_back(cur->val);
            }
            // ans.push_back(vector<int>(tmp.begin(), tmp.end()));
            ans.emplace_back(tmp.begin(), tmp.end());
            flag = !flag;
        }
        return ans;
    }
};

// Solution 3: use index but a bit slower

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> Q({root});
        bool flag = false;
        while(!Q.empty()){
            vector<int>tmp(Q.size());
            for(int i=Q.size() ; i>0 ; i--){
                TreeNode* cur = Q.front(); Q.pop();
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
                if(flag)
                    tmp[i - 1] = cur->val;
                else
                    tmp[tmp.size() - i] = cur->val;
            }
            ans.push_back(tmp);
            flag = !flag;
        }
        return ans;
    }
};

// Solution 4: recursion, insert op high time complexity

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        levelOrder(root, 0);
        return ans;
    }
    void levelOrder(TreeNode* node, int level){
        if(!node)
            return;
        if(ans.size() <= level)
            ans.push_back({});
        if(level % 2 == 0)
            ans[level].push_back(node->val);
        else
            ans[level].insert(ans[level].begin(), node->val);
        levelOrder(node->left, level + 1);
        levelOrder(node->right, level + 1);
    }
};