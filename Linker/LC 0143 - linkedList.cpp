/*
143. Reorder List
*/

// Solution 1: two pointer

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow=head, *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *rev = reverse(slow);
        
        ListNode *cur = head, *tmp;
        while(cur != rev && cur->next != rev){
            tmp = rev->next;
            rev->next = cur->next;
            cur->next = rev;
            rev = tmp;
            cur = cur->next->next;
        }
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* tmp = nullptr, *pre = nullptr;
        ListNode* cur = head;
        while(cur){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

// Solution 2: stack


class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> S;
        ListNode *cur = head, *tmp;
        int ctr = 0;
        while(cur){
            S.push(cur);
            cur = cur->next;
            ctr ++;
        }
        cur = head;
        for(int i=0 ; i<((ctr-1)>>1) ; i++){
            S.top()->next = cur->next;
            cur->next = S.top(); S.pop();
            cur = cur->next->next;
        }
        S.top()->next = nullptr;
    }
};