/*
392. Is Subsequence
*/

// Solution: O(n+m)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=1; i<prices.size() ; i++){
            int diff = prices[i] - prices[i-1];
            profit += diff > 0 ? diff : 0;
        }
        return profit;
    }
};

// Solution of Follow-up: O(knlog(m))

class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>>uM;
        for(int i=0 ; i<t.size() ; i++)
            uM[t[i]].push_back(i);
        int pre_pos = -1;
        for(auto &i: s){
            auto it = upper_bound(uM[i].begin(), uM[i].end(), pre_pos);
            if(it == uM[i].end()) return false;
            pre_pos = *it;
        }
        return true;
    }
};