/*
590. N-ary Tree Postorder Traversal
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
    vector<int>ans;
    vector<int> postorder(Node* root) {
        postOrder(root);
        return ans;
    }
    
    void postOrder(Node* node){
        if(!node) return;
        for(int i=0; i<node->children.size() ; i++)
            postOrder(node->children[i]);
        ans.push_back(node->val);
    }
    
};


// Solution 2: iterative way

class Solution {
public:
    
    struct sTreeNode {
        int val;
        vector<Node*> children;
        int ctr;
        sTreeNode(Node* t) {
            val = t->val;
            for(auto &i: t->children)
                children.push_back(i);
            ctr = 0;
        }
    };
    
    vector<int> postorder(Node* root) {
        vector<int>ans;
        if(!root) return ans;
        stack<sTreeNode*>S;
        Node *p = root;
        while(p || !S.empty()){
            while(p){
                sTreeNode *node = new sTreeNode(p);
                S.push(node);
                if(p->children.size()){
                    node->ctr ++;
                    p = p->children[0];
                }
                else
                    break;
            }
            sTreeNode *cur = S.top();
            if(cur->ctr < cur->children.size()){
                p = cur->children[cur->ctr];
                cur->ctr ++;
            }
            else{
                ans.push_back(cur->val);
                S.pop();
                p = nullptr;
            }
        }
        return ans;
    }
};

// Solution 3: reverse of node->right->left

class Solution {
public:
    
    vector<int> postorder(Node* root) {
        deque<int>dQ;
        if(!root) return {};
        stack<Node*>S({root});
        Node *p = root;
        while(!S.empty()){
            Node* cur = S.top(); S.pop();
            dQ.push_back(cur->val);
            for(auto &i: cur->children)
                S.push(i);
        }
        return vector<int>(dQ.rbegin(), dQ.rend());
    }
};
