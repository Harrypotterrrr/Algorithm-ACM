/*
23. Merge k Sorted Lists
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

// Solution 1: compare one by one O(nk)

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(), *r = dummy;
        vector<ListNode*>p(lists.size(), nullptr);
        for(int i=0 ; i<lists.size() ; i++)
            p[i] = lists[i];
        while(true){
            int k = -1, minn = INT_MAX;
            for(int i=0 ; i<p.size() ; i++){
                if(p[i] && p[i]->val < minn){
                    k = i;
                    minn = p[i]->val;
                }
            }
            if(k == -1)
                break;
            r->next = p[k];
            r = r->next;
            p[k] = p[k]->next;
        }
        return dummy->next;
    }
};

// Solution 2: priority queue to optimize comparing one by one, using lambda expression

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto cmp = [](ListNode*& a, ListNode*& b){
            return a->val > b->val;
        };
        
        ListNode *dummy = new ListNode(), *r = dummy;
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)>pQ(cmp);

        for(int i=0 ; i<lists.size() ; i++)
            if(lists[i])
                pQ.push(lists[i]);
        while(!pQ.empty()){
            ListNode* node = pQ.top(); pQ.pop();
            if(node->next) pQ.push(node->next);
            node->next = nullptr;
            r->next = node; 
            r = r->next;
        }
        return dummy->next;
    }
    
};

// Solution 3: priority queue to optimize comparing one by one, using operator override O(nlog(k))

class Solution {
public:
    
    bool operator()(const ListNode* a, const ListNode* b){
        return a->val > b->val;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *dummy = new ListNode(), *r = dummy;
        priority_queue<ListNode*, vector<ListNode*>, Solution>pQ;

        for(int i=0 ; i<lists.size() ; i++)
            if(lists[i])
                pQ.push(lists[i]);
        while(!pQ.empty()){
            ListNode* node = pQ.top(); pQ.pop();
            if(node->next) pQ.push(node->next);
            node->next = nullptr;
            r->next = node; 
            r = r->next;
        }
        return dummy->next;
    }
    
};


// Solution 4: nlog(n) sorting

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(), *r = dummy;
        vector<int>vec;
        for(int i=0 ; i<lists.size() ; i++){
            ListNode*p = lists[i];
            while(p){
                vec.push_back(p->val);
                p = p->next;
            }
        }
        sort(vec.begin(), vec.end());
        for(auto &i : vec){
            ListNode* node = new ListNode(i);
            r->next = node;
            r = r->next;
        }
        return dummy->next;
    }
};

// Solution 5: nlog(n) sorting a linkedlist node

class Solution {
public:
    
    static bool cmp(ListNode*& p, ListNode*& q){
        return p->val < q->val;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0), *r = dummy;
        vector<ListNode*>vec;
        for(int i=0 ; i<lists.size() ; i++){
            ListNode*p = lists[i], *tmp;
            while(p){
                tmp = p->next;
                p->next = nullptr;
                vec.push_back(p);
                p = tmp;
            }
        }
        sort(vec.begin(), vec.end(), cmp);
        for(auto &i : vec){
            r->next = i;
            r = r->next;
        }
        
        return dummy->next;
    }
};

// Solution 6: merge one by one 

class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(), *r = dummy;
        ListNode *p = l1, *q = l2;
        while(l1 && l2){
            if(l1->val > l2->val){
                r->next = l2;
                l2 = l2->next;
            }
            else{
                r->next = l1;
                l1 = l1->next;
            }
            r = r->next;
        }
        r->next = l1 ? l1 : l2;
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        ListNode* ans = lists[0];
        for(int i=1 ; i<lists.size() ; i++){
            ans = mergeTwoLists(ans, lists[i]);
        }
        
        return ans;
    }
};



// Solution 7: optimization of merge one by one, by divide and conquer O(nlog(k))

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        return divideAndConquer(lists, 0, lists.size() - 1);
    }
    
    ListNode* divideAndConquer(vector<ListNode*>& lists, int left, int right){
        if(left == right - 1)
            return mergeTwoLists(lists[left], lists[right]);
        if(left == right)
            return lists[left];
        int mid = left + ((right - left) >> 1);
        return mergeTwoLists(
            divideAndConquer(lists, left, mid),
            divideAndConquer(lists, mid+1, right)
        );
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(), *r = dummy;
        ListNode *p = l1, *q = l2;
        while(l1 && l2){
            if(l1->val > l2->val){
                r->next = l2;
                l2 = l2->next;
            }
            else{
                r->next = l1;
                l1 = l1->next;
            }
            r = r->next;
        }
        r->next = l1 ? l1 : l2;
        return dummy->next;
    }
    
};


