/*
24. Swap Nodes in Pairs
LinkedList
*
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head);
        return solve(dummy);
    }
    
    ListNode* solve(ListNode* node){
        if(!node->next || !node->next->next) return node->next;
        ListNode *p = node, *tmp = p->next;
        p->next = tmp->next;
        tmp->next = p->next->next;
        p->next->next = tmp;
        solve(p->next->next);
        return node->next;
    }
};