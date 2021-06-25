/*
92. Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *pre=nullptr, *cur=head, *tmp, *sub_head=head;
        for(int i=1 ; i<left ; i++){
            sub_head = cur;
            cur = cur->next;
        }
        ListNode* sub_tail = cur;
        for(int i=left ; i<=right ; i++){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        
        sub_tail->next = cur;

        if(left != 1){ // sub_head != sub_tail // left == 1
            sub_head->next = pre;
            return head;
        }
        else
            return pre;
    }
};

// Solution 2: recrusion way

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* start = head;
        for(int i=1 ; i<left ; i++)
            start = start->next;
        reverseN(start, right - left);
        return head;
    }
    
    ListNode* reverseN(ListNode* node, int n){
        if(n == 1){
            swap(node->val, node->next->val);
            return node->next;
        }
        if(n == 0){
            return node;
        }
        ListNode* tail = reverseN(node->next, n-2);
        swap(node->val, tail->next->val);
        return tail->next;
    }
};