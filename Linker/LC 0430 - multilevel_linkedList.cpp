/************************************************
Problem: 		430. Flatten a Multilevel Doubly Linked List
Algorithm: 		Recursion, LinkedList, Iteration, DFS, Stack
Difficulty: 	**
Importance:		****
Remark:			
*************************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

// Solution 1: Naive

class Solution {
public:
    Node* flatten(Node* head) {
        Node* tail;
        return solve(head, tail);
    }
    
    Node* solve(Node* node, Node*&tail){
        if(!node) return nullptr;
        Node* p = node, *pre, *child_tail;
        while(p){
            if(p->child){
                Node* next_node = p->next;
                Node* child = solve(p->child, child_tail);
                child->prev = p;
                p->next = child;
                if(next_node) {
                    child_tail->next = next_node;
                    next_node->prev = child_tail;
                }
                pre = child_tail;
                p->child = nullptr;
                p = next_node;
            }
            else {
                pre = p;
                p = p->next;
            }
        }
        tail = pre;
        return node;
    }
};

// Solution 2: dfs recrusively like a binary tree if turn the multilevel linkedlist 90 degrees around the clock

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;
        Node* dummy = new Node(-1, nullptr, head, nullptr);
        solve(dummy, head);
        head->prev = nullptr;
        delete dummy;
        return head;
    }
    
    Node* solve(Node* pre, Node* cur){
        if(!cur) return pre;
        
        pre->next = cur;
        cur->prev = pre;
        
        Node* next_node = cur->next, *child_tail;
        if(cur->child) {
            child_tail = solve(cur, cur->child);
            cur->child = nullptr;
            return solve(child_tail, next_node);
        }
        return solve(cur, cur->next);
    }
};

// Solution 3: dfs iteratively

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;
        Node *dummy = new Node(-1, nullptr, head, nullptr);
        Node *pre = dummy;
        stack<Node*> S({head});
        while(!S.empty()){
            Node* cur = S.top(); S.pop();
            pre->next = cur;
            cur->prev = pre;
            if(cur->next) S.push(cur->next);
            if(cur->child){
                S.push(cur->child);
                cur->child = nullptr;
            }
            pre = cur;
        }
        head->prev = nullptr;
        delete dummy;
        return head;
    }
};