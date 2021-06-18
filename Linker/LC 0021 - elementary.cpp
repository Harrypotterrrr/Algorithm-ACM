/*
21. Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2;
        ListNode *ans = nullptr, *tail;
        if(p && q){
            if(p->val > q->val){
                ans = new ListNode(q->val);
                tail = ans;
                q = q->next;
            }
            else{
                ans = new ListNode(p->val);
                tail = ans;
                p = p->next;
            }
            while(p && q){
                if(p->val > q->val){
                    tail->next = new ListNode(q->val);
                    q = q->next;
                }
                else{
                    tail->next = new ListNode(p->val);
                    p = p->next;
                }
                tail = tail->next;
            }
            while(p){
                tail->next = new ListNode(p->val);
                tail = tail->next;
                p = p->next;
            }
            while(q){
                tail->next = new ListNode(q->val);
                tail = tail->next;
                q = q->next;
            }
        }
        else if(p)
            return p;
        else if(q)
            return q;
        return ans;
    }
};


// Solution 2: optimization

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(), *r = dummy;
        ListNode *p = l1, *q = l2;
        while(l1 && l2){
            if(l1->val > l2->val){
                r->next = l2;
                l2 = l2->next;
            }
            else{
                r->next = l1;
                l1 = l1->next;
            }
            r = r->next;
        }
        r->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

// Solution 3: recursive way

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val > l2->val){
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        else{
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    }
};

