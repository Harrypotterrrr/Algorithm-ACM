/************************************************
Problem: 		465. Optimal Account Balancing
Algorithm: 		Search, DFS, STL
Difficulty: 	***
Importance:		***
Remark:			NP problem
*************************************************/

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