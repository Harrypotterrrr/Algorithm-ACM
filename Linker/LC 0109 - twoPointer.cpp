/*
109. Convert Sorted List to Binary Search Tree
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode *pre, *slow, *fast;
        fast = pre = slow = head;
        while(fast->next && fast->next->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *cur = new TreeNode(slow->val);
        if(slow != head){
            pre->next = nullptr;
            cur->left = sortedListToBST(head);            
        }
        cur->right = sortedListToBST(slow->next);
        return cur;
    }
};