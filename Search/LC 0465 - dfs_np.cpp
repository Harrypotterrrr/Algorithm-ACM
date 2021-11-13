/************************************************
Problem: 		465. Optimal Account Balancing
Algorithm: 		Search, DFS, STL, Dynamic Programming
Difficulty: 	*****
Importance:		*****
Remark:			NP problem, State Compression DP
*************************************************/

// Solution 1: dfs for NP problem O(n!)

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int>uM;
        for(auto &i: transactions) {
            uM[i[0]] -= i[2];
            uM[i[1]] += i[2];
        }
        vector<int>acc;
        for(auto &i: uM) if(i.second) acc.push_back(i.second);
        int ans = INT_MAX;
        solve(acc, 0, 0, ans);
        return ans;
    }
    
    void solve(vector<int>&acc, int k, int ctr, int &ans){
        while(k<acc.size() && !acc[k]) k++; 
        // or : if(!acc[k]) {solve(acc, k+1, ctr, ans); return;}
        if(k >= acc.size()){
            ans = ans < ctr ? ans : ctr;
            return;
        }
        if(ctr >= ans) return;
        for(int i=k+1 ; i<acc.size() ; i++){
            if(acc[i] && (unsigned(acc[k]) >> 31) ^ (unsigned(acc[i]) >> 31)){
                acc[i] += acc[k];
                solve(acc, k+1, ctr+1, ans);
                acc[i] -= acc[k];
            }
        }
    }
};

// Solution 2: state compression DP O(n2^n), detail: https://leetcode.com/problems/optimal-account-balancing/discuss/219187/Short-O(N-*-2N)-DP-solution-with-detailed-explanation-and-complexity-analysis

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int>uM;
        for(auto &i: transactions){
            uM[i[0]] -= i[2];
            uM[i[1]] += i[2];
        }
        vector<int>bill;
        for(auto &i: uM) if(i.second) bill.push_back(i.second);
        int n = bill.size();
        
        vector<int>dp(1 << n);
        vector<int>summ(1 << n);
        
        for(int subset=0 ; subset < (1 << n) ; subset++){
            for(int bit_id=0 ; bit_id < n ; bit_id++){
                int bit = 1 << bit_id;
                int new_set = bit | subset;
                if(new_set ^ subset){ // new_set is different with subset
                    summ[new_set] = summ[subset] + bill[bit_id];
                    if(summ[new_set])
                        dp[new_set] = dp[new_set] > dp[subset] ? dp[new_set] : dp[subset];
                    else
                        dp[new_set] = dp[new_set] > dp[subset] + 1 ? dp[new_set] : dp[subset] + 1;
                }
            }
        }
        return n - dp[(1<<n)-1];
    }
};