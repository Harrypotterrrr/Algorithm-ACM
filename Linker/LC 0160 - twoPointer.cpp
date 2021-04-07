/*
160. Intersection of Two Linked Lists
*/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int num1 = 0, num2 = 0;
        ListNode *p = headA, *q = headB;
        while(p){
            p = p->next;
            num1 ++;
        }
        while(q){
            q = q->next;
            num2 ++;
        }
        if(num1 > num2)
            while(num1-- > num2) 
                headA = headA->next;
        else if(num1 < num2)
            while(num2 -- > num1)
                headB = headB->next;
        
        while(headA && headB){
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};