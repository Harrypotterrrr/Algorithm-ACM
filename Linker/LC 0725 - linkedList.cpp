/*
725. Split Linked List in Parts
*/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans(k);
        int ctr = 0, avg, remain;
        ListNode *p, *tmp;
        
        for(p=root ; p ; p=p->next) ctr++;
        
        avg = ctr / k;
        remain = ctr % k;
        
        p = root;
        for(int i=0 ; i<k ; i++){
            ans[i] = p;
            for(int j=1 ; j<avg + (i < remain) ; j++)
                p = p->next;
            if(p){
                tmp = p->next;
                p->next = nullptr;
                p = tmp;
            }
        }
        return ans;
    }
};