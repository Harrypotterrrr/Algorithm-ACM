/*
122. Best Time to Buy and Sell Stock II
*/

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