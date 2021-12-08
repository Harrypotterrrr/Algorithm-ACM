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
        for(auto &i: transactions){
            uM[i[0]] -= i[2];
            uM[i[1]] += i[2];
        }
        vector<int>vec;
        for(auto &i: uM){
            if(i.second)
                vec.push_back(i.second);
        }
        int n = vec.size();
        
        function<int(int)> solve = [&n, &vec, &solve](int k){
            if(k >= n) return 0;
            if(vec[k] == 0) return solve(k+1);
            int cur = INT_MAX;
            for(int i=k+1 ; i<n ; i++){
                if(vec[k] == 0 || (unsigned(vec[i]) >> 31) ^ (unsigned(vec[k]) >> 31) == 0) continue;
                vec[i] += vec[k];
                cur = min(cur, solve(k+1) + 1);
                vec[i] -= vec[k];
            }
            return cur;
        };
        
        return solve(0);
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