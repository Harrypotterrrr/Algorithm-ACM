/************************************************
Problem: 		708. Insert into a Sorted Circular Linked List
Algorithm: 		LinkedList
Difficulty: 	**
Importance:		*
Remark:			
*************************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head){
            Node *new_node = new Node(insertVal);
            new_node->next = new_node;
            return new_node;
        }
        Node *cur = head;
        
        while(cur->next != head){
            if(cur->val <= insertVal && insertVal <= cur->next->val) break;
            if(cur->val > cur->next->val){
                if(insertVal < cur->next->val) break;
                if(insertVal > cur->val) break;
            }
            cur = cur->next;
        }
        Node *new_node = new Node(insertVal, cur->next);
        cur->next = new_node;
        return head;
    }
};