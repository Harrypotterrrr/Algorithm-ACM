/*
19. Remove Nth Node From End of List

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.
*/

#include "../include/include.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int N = 0;
        while(p){
            p = p->next;
            N++;
        }
        n = N - n - 1;
        if(n == -1){
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        else{
            p = head;
            while(n--) p =p->next;
            ListNode* tmp = p->next;
            p->next = p->next->next;
            delete tmp;
        }
        return head;
    }
};