/************************************************
Problem: 		871. Minimum Number of Refueling Stops
Algorithm: 		Dynamic Programming, Priority Queue, Greedy
Difficulty: 	****
Importance:		*****
Remark:			0-1 Knapsack problem
*************************************************/

// Solution 1: WA

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel >= target) return 0;
        int n = stations.size(), cur = -1;
        vector<int>dp(stations.size()+1, INT_MIN);
        dp[0] = startFuel;
        for(int i=1 ; i<=n ; i++){
            int maxn = INT_MIN, id = -1;
            for(int j=cur+1 ; j<n ; j++){
                if(dp[i-1] < stations[j][0]) break;
                if(stations[j][1] + dp[i-1] >= maxn){
                    maxn = stations[j][1] + dp[i-1];
                    id = j;
                }
            }
            if(maxn == INT_MIN) return -1;
            if(maxn >= target) return i;
            dp[i] = maxn;
            cur = id;
        }
        return -1;
    }
};

// Solution 2: iterate the station first then iterate the fueling time

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long>dp(stations.size()+1, INT_MIN);
        dp[0] = startFuel;
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j>=0 ; j--){
                if(dp[j] < stations[i][0]) break;
                dp[j+1] = max(dp[j+1], dp[j] + long(stations[i][1]));
            }
        }
        for(int i=0 ; i<=n ; i++)
            if(dp[i] >= target)
                return i;
        return -1;
    }
};

// Solution 3: greedy + priority_queue (decltype)

class Solution {
public:
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size(), cur = startFuel, ans = 0;
        
        auto cmp = [](const int& a, const int&b){
            return a < b;
        };
        priority_queue<int, vector<int>, decltype(cmp)>pQ(cmp);
        
        for(int i=0 ; cur<target ; ans++){
            while(i < n && stations[i][0] <= cur)
                pQ.push(stations[i++][1]);
            if(pQ.empty()) return -1;
            auto highest = pQ.top(); pQ.pop();
            cur += highest;
        }
        return ans;
    }
};

// Solution 4: greedy + priority_queue (function)

class Solution {
public:
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size(), cur = startFuel, ans = 0;
        
        priority_queue<int, vector<int>, function<bool(int& a, int& b)> >pQ(
            [](int& a, int& b){
                return a < b;
            }
        );

        for(int i=0 ; cur<target ; ans++){
            while(i < n && stations[i][0] <= cur)
                pQ.push(stations[i++][1]);
            if(pQ.empty()) return -1;
            auto highest = pQ.top(); pQ.pop();
            cur += highest;
        }
        return ans;
    }
};