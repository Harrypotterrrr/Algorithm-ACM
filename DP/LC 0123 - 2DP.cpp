/*
123. Best Time to Buy and Sell Stock III
*/

// Solution 1: two array to dp

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), m = 2;
        vector<vector<int>>local(n, vector<int>(m+1, 0));
        vector<vector<int>>global(n, vector<int>(m+1, 0));

        for(int j=1 ; j<=m ; j++){ // date
            for(int i=1 ; i<n ; i++){ // stock
                int diff = prices[i] - prices[i-1];
                local[i][j] = max(local[i-1][j], global[i-1][j-1]) + diff;
                global[i][j] = max(global[i-1][j], local[i][j]);
            }
        }
        return global[n-1][m];
    }
};

// Solution 2: space optimization of solution 1

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), m = 2;
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

// Solution 3: iterate stock first then 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), m = 2;
        vector<int>local(m+1, 0);
        vector<vector<int>>global(2, vector<int>(m+1, 0));
        bool flag = false;
        
        for(int i=1 ; i<n ; i++){
            int diff = prices[i] - prices[i-1];
            for(int j=1 ; j<=m ; j++){
                local[j] = max(local[j], global[!flag][j-1]) + diff;
                global[flag][j] = max(global[!flag][j], local[j]);
            }
            flag = !flag;
        }
        return global[!flag][m];
    }
};