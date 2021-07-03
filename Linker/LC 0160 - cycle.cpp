/*
160. Intersection of Two Linked Lists
*/

// Solution 1: compare the length

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

// Solution 2: cycle

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        if(!p || !q) 
            return nullptr;
        while(p != q){
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }
        return p;
    }
};