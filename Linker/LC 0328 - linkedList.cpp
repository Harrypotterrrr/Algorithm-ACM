/*
328. Odd Even Linked List
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* p = head, *even = head->next, *odd_tail, *tmp;
        bool flag = false;
        while(p && p->next){
            tmp = p->next;
            p->next = p->next->next;
            p = tmp;
            flag = !flag;
            if(!flag)
                odd_tail = p;
        }
        odd_tail->next = even;
        return head;
    }
};

// Solution 2: two pointer, more elegant

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *odd = head, *even = head->next, *even_head = even;
        while(even && even->next){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};