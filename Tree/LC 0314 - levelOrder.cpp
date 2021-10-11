/*
314. Binary Tree Vertical Order Traversal
*/

// Solution 1: two traverse, O(n)

class Solution {
public:
    
    int minn = INT_MAX, maxn = INT_MIN;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        find_min_max(root, 0);
        ans.resize(maxn - minn + 1);
        // cout<<minn <<" "<<maxn<<endl;;
        
        queue<pair<TreeNode*, int>>Q({{root, 0-minn}}); 
        while(!Q.empty()){
            for(int i=Q.size()-1 ; i>=0 ; i--){
                TreeNode* cur = Q.front().first; 
                int id = Q.front().second;
                Q.pop();
                ans[id].push_back(cur->val);
                if(cur->left) Q.push({cur->left, id-1});
                if(cur->right) Q.push({cur->right, id+1});
            }
        }
        return ans;
    }
    void find_min_max(TreeNode* node, int id){
        if(!node) return;
        minn = minn < id ? minn : id;
        maxn = maxn > id ? maxn : id;
        find_min_max(node->left, id - 1);
        find_min_max(node->right, id + 1);
    }
};

// Solution 2: map to sort, O(nlog(n))

class Solution {
public:
    
    int minn = INT_MAX, maxn = INT_MIN;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        map<int, vector<int>> M;
        queue<pair<TreeNode*, int>> Q({{root, 0}});
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            M[cur.second].push_back(cur.first->val);
            if (cur.first->left) Q.push({cur.first->left, cur.second-1});
            if (cur.first->right) Q.push({cur.first->right, cur.second+1});
        }
        for (auto &i : M) {
            ans.push_back(i.second);
        }
        return ans;
    }
};