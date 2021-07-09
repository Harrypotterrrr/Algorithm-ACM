/*
142. Linked List Cycle II
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, * fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                break;
        }
        if(!fast || !fast->next)
            return nullptr;
        slow = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};