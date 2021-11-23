/************************************************
Problem: 		2034. Stock Price Fluctuation
Algorithm: 		STL, Design
Difficulty: 	**
Importance:		*****
Remark:			custom map
*************************************************/

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

// Solution 1: 

class StockPrice {
public:
    
    // different with priority_queue, < is ascending order, > is descending order
    function<bool(const int, const int)> cmp_min = [](const int a, const int b) ->bool {
        return a < b;
    };

    function<bool(const int, const int)> cmp_max = [](const int a, const int b) ->bool {
        return a > b;
    };
    
    map<int, int, decltype(cmp_max)> min_m;
    map<int, int, decltype(cmp_max)> max_m;
    unordered_map<int, int>uM; // timestamp, price
    int cur;
    
    StockPrice() {
        min_m = map<int, int, decltype(cmp_min)>(cmp_min);
        max_m = map<int, int, decltype(cmp_max)>(cmp_max);
        cur = -1;
    }
    
    void update(int timestamp, int price) {
        if(uM.find(timestamp) != uM.end()){
            auto old_price = uM[timestamp];
            if(--min_m[old_price] == 0)
                min_m.erase(old_price);
            if(--max_m[old_price] == 0)
                max_m.erase(old_price);
            uM[timestamp] = price;
            min_m[price]++;
            max_m[price]++;
        }
        else{
            uM[timestamp] = price;
            min_m[price]++;
            max_m[price]++;
            cur = cur > timestamp ? cur : timestamp;
        }
    }
    
    int current() {
        return uM[cur];
    }
    
    int maximum() {
        return max_m.begin()->first;
    }
    
    int minimum() {
        return min_m.begin()->first;
    }
};

// Solution 2: more elegant

class StockPrice {
public:
    
    // map default order: small to large
    map<int, int> price_m; // price, num
    unordered_map<int, int> time_m; // timestamp, price
    pair<int, int> cur_price; // timestamp, price
    
    StockPrice() {
        cur_price = {-1, -1};
    }
    
    void update(int timestamp, int price) {
        if(time_m.find(timestamp) != time_m.end()){
            auto old_price = time_m[timestamp];
            if(--price_m[old_price] == 0)
                price_m.erase(old_price);
        }
        time_m[timestamp] = price;
        price_m[price]++;
        
        if(timestamp >= cur_price.first)
            cur_price = {timestamp, price};
    }
    
    int current() {
        return cur_price.second;
    }
    
    int maximum() {
        return price_m.rbegin()->first;
    }
    
    int minimum() {
        return price_m.begin()->first;
    }
};