/*
141. Linked List Cycle
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// use two pointers
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};

// Solution 2: unordered_map
class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> uset;
        ListNode *cur = head;
        while(head){
            if(uset.find(head) != uset.end())
                return true;
            uset.insert(head);
            head = head->next;
        }
        return false;
    }
};