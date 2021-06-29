/*
234. Palindrome Linked List
*/

// Solution 1: stack but O(n) space

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            fast = fast ->next->next;
            slow = slow->next;
        }
        stack<int>S;
        while(slow){
            S.push(slow->val);
            slow = slow->next;
        }
        ListNode *p = head;
        while(!S.empty()){
            if(S.top() != p->val)
                return false;
            p = p->next;
            S.pop();
        }
        return true;
    }

};

// Solution 2: recursion

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* cur = head;
        return solve(head, cur);
    }
    
    bool solve(ListNode* node, ListNode*& cur){
        if(!node)
            return true;
        bool rtn = solve(node->next, cur) && (cur->val == node->val);
        cur = cur->next;
        return rtn;
    }
};

// Solution 3: two pointer to find the mid and reverse the later half to reduce the space to O(1)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *p = head;
        while(fast && fast->next){
            fast = fast ->next->next;
            slow = slow->next;
        }
        slow = reverseList(slow);
        
        while(slow){
            if(slow->val != p->val)
                return false;
            slow = slow->next;
            p = p->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* pre = nullptr, *cur = head, *tmp;
        while(cur){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};