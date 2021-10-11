/*
1522. Diameter of N-Ary Tree
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    int ans = 0;
    
    int diameter(Node* root) {
        solve(root);
        return ans;
    }
    
    int solve(Node* node){
        if(!node) return 0;
        vector<int>vec(node->children.size(), 0);
        int maxn = 0, maxnn = 0;
        for(int i=0 ; i<node->children.size() ; i++){
            vec[i] = solve(node->children[i]) + 1;
            if(vec[i] > maxn){
                maxnn = maxn;
                maxn = vec[i];
            }
            else if(vec[i] > maxnn){
                maxnn = vec[i];
            }
        }
        ans = ans > maxn + maxnn ? ans : maxn + maxnn;
        return maxn;
    }
};