/*
188. Best Time to Buy and Sell Stock IV
*/

// Solution 1: same to Problem 0123

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(), m = k;
        if(!n || !k) return 0;
        vector<int>local(n, 0);
        vector<vector<int>>global(2, vector<int>(n, 0));
        bool flag = false;
        for(int j=1 ; j<=m ; j++){
            for(int i=0 ; i<n-1 ; i++){
                int diff = prices[i+1] - prices[i];
                local[i+1] = max(local[i], global[!flag][i]) + diff;
                global[flag][i+1] = max(global[flag][i], local[i+1]);
            }
            flag = !flag;
        }
        return global[!flag][n-1];
    }
};

// Solution 2: same to Problem 0123