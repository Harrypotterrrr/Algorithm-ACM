/************************************************
Problem: 		1340. Jump Game V
Algorithm: 		Monotone Stack, DFS
Difficulty: 	***
Importance:		*****
Remark:			
*************************************************/

// Solution 1: monotone stack, DFS O(Nd)

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int>left(n, 0), right(n, 0);
        stack<pair<int, int>>S; // id, value
        for(int i=0 ; i<n ; i++){
            while(!S.empty() && S.top().second < arr[i]) S.pop();
            if(S.empty()){
                if(i > d) left[i] = i - d;
                else left[i] = 0;
            }
            else{
                if(i - S.top().first > d) left[i] = i - d;
                else left[i] = S.top().first + 1;
            }
            S.push({i, arr[i]});
        }
        while(!S.empty()) S.pop();
        for(int i=n-1 ; i>=0 ; i--){
            while(!S.empty() && S.top().second < arr[i]) S.pop();
            if(S.empty()){
                if(n-1-i > d) right[i] = i + d;
                else right[i] = n-1;
            }
            else{
                if(S.top().first - i > d) right[i] = i + d;
                else right[i] = S.top().first - 1;
            }
            S.push({i, arr[i]});
        }
        
        vector<int>memo(n, 0);

        function<int(int)> solve = [&memo, &solve, &left, &right](int k){
            if(memo[k]) return memo[k];
            int cur = 1;
            for(int i=left[k] ; i<=right[k] ; i++){
                if(i == k) continue;
                cur = max(cur, solve(i) + 1);
            }
            return memo[k] = cur;
        };
        
        int ans = 1;
        for(int i=0 ; i<n ; i++){
            ans = max(ans, solve(i));
        }
        return ans;
    }
};