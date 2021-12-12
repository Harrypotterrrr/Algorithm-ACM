/************************************************
Problem: 		1290. Convert Binary Number in a Linked List to Integer
Algorithm: 		Bit Manipulation, LinkedList
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while(head){
            ans <<= 1;
            ans |= head->val;
            head = head->next;
        }
        return ans;
    }
};