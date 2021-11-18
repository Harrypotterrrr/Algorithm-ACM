/************************************************
Problem: 		1578. Minimum Deletion Cost to Avoid Repeating Letters
Algorithm: 		Two Pointer, Array
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

// Solution: time O(n)

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = s.size();
        int ans = 0, left = 0, right = 1;
        while(right < n){
            while(right < n && s[left] == s[right]){
                if(cost[left] < cost[right]){
                    ans += cost[left];
                    left = right;
                }
                else{
                    ans += cost[right];
                }
                right++;
            }
            right++;
            left = right - 1;
        }
        return ans;
    }
};

// Solution 2: more elegant and clear

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = s.size();
        int ans = 0, maxn = cost[0];
        for(int i=1 ; i<n ; i++){
            if(s[i] == s[i-1]){
                ans += min(maxn, cost[i]);
                maxn = max(maxn, cost[i]);
            }
            else maxn = cost[i];
        }
        return ans;
    }
};