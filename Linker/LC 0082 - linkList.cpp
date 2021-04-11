/*
82. Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p, *q;
        while(head && head->next){
            p = head->next;
            while(p && p->val == head->val){
                p = p->next;
            }
            if(p != head->next){
                while(head != p){
                    ListNode *tmp = head;
                    head = head->next;
                    delete tmp;
                }
            }
            else break;
        }
        
        p = q = head;

        while(p){
            cout<<p->val<<endl;
            q = p->next;
            while(q && q->next && q->val == q->next->val)
                q = q->next;
            if(q != p->next){
                ListNode *target = q->next;
                while(p->next != target){
                    ListNode *tmp = p->next;
                    p->next = tmp->next;
                    delete tmp;
                }
            }
            else
                p = p->next;
        }
        return head;
    }
};


// Solution 2: create dummy head
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-INT_MAX, head);
        ListNode *p = dummy, *q = dummy;

        while(p){
            cout<<p->val<<endl;
            q = p->next;
            while(q && q->next && q->val == q->next->val)
                q = q->next;
            if(q != p->next){
                ListNode *target = q->next;
                while(p->next != target){
                    ListNode *tmp = p->next;
                    p->next = tmp->next;
                    delete tmp;
                }
            }
            else
                p = p->next;
        }
        return dummy->next;
    }
};