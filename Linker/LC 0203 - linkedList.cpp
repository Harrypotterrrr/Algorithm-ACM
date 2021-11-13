/************************************************
Problem: 		203. Remove Linked List Elements
Algorithm: 		LinkedList, Recursion, Iteration
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

// Solution 1: iteration, dummy head

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *p = dummy;
        while(p->next){
            if(p->next->val == val){
                ListNode *tmp = p->next->next;
                delete p->next;
                p->next = tmp;
            }
            else p = p->next;
        }
        ListNode *rtn = dummy->next;
        return rtn;
    }
};

// Solution 2: recursion

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1, head);
        solve(dummy, val);
        ListNode *rtn = dummy->next;
        delete dummy;
        return rtn;
    }
    
    ListNode* solve(ListNode *node, const int val){
        if(!node->next) return node;
        if(node->next->val == val){
            ListNode *tmp = node->next->next;
            delete node->next;
            node->next = tmp;
            solve(node, val);
        }
        else solve(node->next, val);
        return node;
    }
};

// Solution 3: recursion without dummy

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        return solve(head, val);
    }
    
    ListNode* solve(ListNode *node, const int val){
        if(!node) return nullptr;
        if(node->val == val) return solve(node->next, val);
        node->next = solve(node->next, val);
        return node;
    }
};