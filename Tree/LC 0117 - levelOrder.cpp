/*
117. Populating Next Right Pointers in Each Node II
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

// Solution 1: recursive way

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return nullptr;
        Node *cur = root;

        if(!cur->left && !cur->right)
            return root;
        
        Node *tmp = cur->next;
        while(tmp){
            if(tmp->left){
                tmp = tmp->left;
                break;
            }
            else if(tmp->right){
                tmp = tmp->right;
                break;
            }
            else
                tmp = tmp->next;
        }
        
        if(cur->left && cur->right){
            cur->left->next = cur->right;
            cur->right->next = tmp;
        }
        else if(cur->left)
            cur->left->next = tmp;
        else if(cur->right)
            cur->right->next = tmp;
        connect(root->left);
        connect(root->right);
        return root;
    }
};

// Solution 2: a bit more elegant of solution 1

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return nullptr;

        if(!root->left && !root->right)
            return root;
        
        Node *tmp = root->next;
        while(tmp){
            if(tmp->left){
                tmp = tmp->left;
                break;
            }
            else if(tmp->right){
                tmp = tmp->right;
                break;
            }
            else
                tmp = tmp->next;
        }
        if(root->right)
            root->right->next = tmp;
        if(root->left)
            root->left->next = root->right ? root->right : tmp;
        
        connect(root->right);
        connect(root->left);
        return root;
    }
};

// Solution 3: trivial iterative way

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


// Solution 4: anchor pointer and dummy node, best solution, space complexity O(1)

class Solution {
public:
    
    Node* connect(Node* root) {
        if(!root)
            return nullptr;
        
        Node *dummy = new Node, *cur = dummy, *pre = root;
        
        while(pre){
            while(pre){
                if(pre->left){
                    cur->next = pre->left;
                    cur = cur->next;
                }
                if(pre->right){
                    cur->next = pre->right;
                    cur = cur->next;
                }
                pre = pre->next;
            }
            pre = dummy->next;
            cur = dummy;
            dummy->next = nullptr;
        }

        return root;
    }
};