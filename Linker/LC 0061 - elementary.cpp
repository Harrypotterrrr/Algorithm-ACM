/*
61. Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode *p = head;
        if(!p || !p->next)
            return p;
        while(p->next){
            p = p->next;
            n++;
        }
        n++;
        k %= n;
        
        p->next = head;
        p = head;
        n = n - k - 1;
        while(n--){
            p = p->next;
        }
        head = p->next;
        p->next = nullptr;
        return head;
    }
};