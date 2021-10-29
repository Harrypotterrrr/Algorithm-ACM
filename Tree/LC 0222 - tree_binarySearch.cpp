/*
222. Count Complete Tree Nodes
Tree, Binary Search
***
*/


// Solution 1: naive

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// Solution 2: complete tree property

class Solution {
public:
    int countNodes(TreeNode* root) {
        TreeNode *p = root;
        int max_level = 0, level = 1, ans = 1;
        while(p) {
            max_level ++;
            p = p->left;
        }
        p = root;
        while(level < max_level){
            level ++;
            // if(!p->left && level == max_level - 1) break;
            if(exist(p->left, max_level, level + 1)){
                ans = (ans << 1) + 1;
                p = p->right;
            }
            else{
                p = p->left;
                ans <<= 1;
            }
        }
        
        return p ? ans : ans - 1;
    }
    
    bool exist(TreeNode *node, int max_level, int level){
        if(!node) return false;
        TreeNode *p = node;
        while(level <= max_level){
            p = p->right;
            level ++;
        }
        return p != nullptr;
    }
};

// Solution 3: binary search with recursive pow func

class Solution {
public:
    
    int pow(int n, int k){
        if(k == 0) return 1;
        if(k % 2) return pow(n, k - 1) * n;
        int tmp = pow(n, k >> 1);
        return tmp * tmp;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode *p = root;
        int left_level = 0, right_level = 0;
        while(p){
            p = p->left;
            left_level ++;
        }
        p = root;
        while(p){
            p = p->right;
            right_level;
        }
        if(left_level == right_level)
            return pow(2, left_level) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// Solution 4: binary search with iterative pow func

class Solution {
public:
    
    int pow(int n, int k){
        int ans = 1;
        while(k){
            if(k & 1) ans *= n;
            k >>= 1;
            n *= n;
        }
        return ans;
    }
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode *p = root;
        int left_level = 0, right_level = 0;
        while(p){
            p = p->left;
            left_level ++;
        }
        p = root;
        while(p){
            p = p->right;
            right_level;
        }
        if(left_level == right_level)
            return 1 << left_level - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// Solution 5: another way of binary search

class Solution {
public:
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left_level = getLeftHeight(root->left);
        int right_level = getLeftHeight(root->right);
        if(left_level == right_level)
            return (1 << (left_level)) + countNodes(root->right);
        return (right_level == 0 ? 0 : (1 << (right_level)) - 1) + countNodes(root->left) + 1;
    }
    
    int getLeftHeight(TreeNode *node){
        return node ? getLeftHeight(node->left) + 1 : 0;
    }
    
};

// Solution 6: iterative way of solution 5

class Solution {
public:
     
    int countNodes(TreeNode* root) {
        int left_level = 0;
        int right_level = 0;
        int ans = 0;
        TreeNode *p = root;
        while(p){
            left_level = getLeftHeight(p->left);
            right_level = getLeftHeight(p->right);
            if(left_level == right_level){
                ans += (1 << left_level);
                p = p->right;
            }
            else{
                ans += (1 << right_level);
                p = p->left;
            }
        }
        return ans;
    }
    
    int getLeftHeight(TreeNode *node){
        return node ? getLeftHeight(node->left) + 1 : 0;
    }
    
};