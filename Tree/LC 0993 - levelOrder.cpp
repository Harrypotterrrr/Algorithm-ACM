/*
993. Cousins in Binary Tree
Tree, LevelOrderTraversal, BFS, DFS
*/

// Solution 1: naive, bfs, level order traversal

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>Q({root});
        while(!Q.empty()){
            bool flag = false;
            for(int i=Q.size()-1 ; i>=0 ; i--){
                TreeNode *cur = Q.front(); Q.pop();
                if(cur->left && cur->right){
                    if((cur->left->val == x && cur->right->val == y) || (cur->left->val == y && cur->right->val == x))
                        return false;
                }
                if(cur->left){
                    if(cur->left->val == x || cur->left->val == y){
                        if(flag) return true;
                        else flag = true;
                    }
                    Q.push(cur->left);
                }
                if(cur->right){
                    if(cur->right->val == x || cur->right->val == y){
                        if(flag) return true;
                        else flag = true;
                    }
                    Q.push(cur->right);
                }
            }
            if(flag) return false;
        }
        return false;
    }
};

// Solution 2: another more elegant level-order traversal way

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>Q({root});
        while(!Q.empty()){
            bool isX = false, isY = false;
            for(int i=Q.size()-1 ; i>=0 ; i--){
                TreeNode *cur = Q.front(); Q.pop();
                if(cur->left && cur->right){
                    if((cur->left->val == x && cur->right->val == y) || (cur->left->val == y && cur->right->val == x))
                        return false;
                }
                if(cur->val == x) isX = true;
                if(cur->val == y) isY = true;
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
            if(isX && isY) return true;
            else if(isX || isY) return false;
        }
        return false;
    }
};

// Solution 3: dfs

class Solution {
public:
    int depth_x = -1, depth_y = -1;
    
    bool isCousins(TreeNode* root, int x, int y) {
        return dfs(root, 0, x, y);
    }
    
    bool dfs(TreeNode* node, int depth, const int x, const int y){
        if(!node) return false;
        if(node->left && node->right)
            if((node->left->val == x && node->right->val == y) || (node->left->val == y && node->right->val == x))
                return false;
        if(node->val == x) depth_x = depth;
        if(node->val == y) depth_y = depth;
        if(depth_x > 0 && depth_y > 0){
            if(depth_x == depth_y) return true;
            return false;
        }
        bool flag;
        if(node->left) flag = dfs(node->left, depth+1, x, y);
        if(!flag) return dfs(node->right, depth+1, x, y);
        return true;
    }
};
