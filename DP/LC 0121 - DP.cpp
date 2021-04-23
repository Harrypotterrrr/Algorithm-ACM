/*
121. Best Time to Buy and Sell Stock
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, min_price = INT_MAX;
        for(auto &i : prices){
            min_price = min_price > i ? i : min_price;
            max_profit = max_profit > (i - min_price) ? max_profit : (i - min_price);
        }
        return max_profit;
    }
};

// Solution 2: convert the problem into the maximum subarray

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>sub_arr(prices.size()+1, 0);
        for(int i=1 ; i<prices.size() ; i++){
            int diff = prices[i] - prices[i-1];
            sub_arr[i] = diff > sub_arr[i-1] + diff ? diff : sub_arr[i-1] + diff;
        }
        return *std::max_element(sub_arr.begin(), sub_arr.end());
    }
};

// Solution 3: optimization

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int dp = 0;
        for(int i=1 ; i<prices.size() ; i++){
            int diff = prices[i] - prices[i-1];
            dp = diff > dp + diff ? diff : dp + diff;
            max_profit = max_profit > dp ? max_profit : dp;
        }
        return max_profit;
    }
};

// Solution 4: further optimization a little bit

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int dp = 0;
        for(int i=1 ; i<prices.size() ; i++){
            dp += prices[i] - prices[i-1];
            if(dp < 0)
                dp = 0;
            max_profit = max_profit > dp ? max_profit : dp;
        }
        return max_profit;
    }
};