/*
116. Populating Next Right Pointers in Each Node
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return nullptr;
        
        queue<Node*>Q({root});
        while(!Q.empty()){
            Node *pre = nullptr;
            for(int i=Q.size()-1 ; i>=0 ; i--){
                Node *cur = Q.front(); Q.pop();
                cur->next = pre;
                pre = cur;
                if(cur->right) Q.push(cur->right);
                if(cur->left) Q.push(cur->left);
            }
            
        }
        return root;
    }
};

// Solution 2: recursive version

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return nullptr;
        if(root->left)
            root->left->next = root->right;
        if(root->right && root->next)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }
};

// Solution 3: level order of two pointers

class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root || !root->left)
            return root;
        
        Node *cur = root->left, *pre = root, *tmp = pre;
        while(cur){
            tmp = cur;
            while(pre){
                cout<<cur->val<<endl;
                cur->next = pre->right;
                cur = cur->next;
                pre = pre->next;
                cur->next = pre ? pre->left : nullptr;
                cur = cur->next;
            }
            pre = tmp;
            cur = tmp->left;
        }
        return root;
    }
};

// Solution 4: a bit optimization of level order of two pointers

class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root || !root->left)
            return root;
        
        Node *cur = root, *pre;
        while(cur->left){
            pre = cur;
            while(cur){
                cur->left->next = cur->right;
                cur->right->next = cur->next ? cur->next->left : nullptr;
                cur = cur->next;
            }
            cur = pre->left;
        }
        return root;
    }
};