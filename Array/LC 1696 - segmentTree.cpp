/************************************************
Problem: 		1696. Jump Game VI
Algorithm: 		Dynamic Programming, Monotone Queue, Segment Tree, STL
Difficulty: 	***
Importance:		*****
Remark:			
*************************************************/

// Solution 1: TLE, top-to-bottom: DFS + memorization O(Nk)

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>memo(n, INT_MIN);
        function<int(int)> solve = [&memo, &n, &solve, &k, &nums](int cur){
            if(cur == n - 1) return nums[cur];
            if(memo[cur] != INT_MIN) return memo[cur];
            int score = INT_MIN;
            for(int i=cur+1 ; i<=cur+k && i<n ; i++){
                score = max(score, nums[cur] + solve(i));
            }
            return memo[cur] = score;
        };
        
        solve(0);
        return memo[0];
    }
};

// Solution 2: DP + monotone queue O(N), space O(N)

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n);
        deque<int>dQ; // monotone queue: decreasing order
        for(int i=0 ; i<n ; i++){
            while(!dQ.empty() && i - dQ.front() > k) dQ.pop_front();
            if(dQ.empty()) dp[i] = nums[i];
            else dp[i] = dp[dQ.front()] + nums[i];
            while(!dQ.empty() && dp[dQ.back()] < dp[i]) dQ.pop_back();
            dQ.push_back(i);
        }
        return dp[n-1];
    }
};

// Solution 3: space optimization of solution 2, time O(N), space O(k)

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, int>>dQ; // id, value, monotone queue: decreasing order
        for(int i=0 ; i<n ; i++){
            while(!dQ.empty() && i - dQ.front().first > k) dQ.pop_front();
            int cur;
            if(dQ.empty()) cur = nums[i];
            else cur = dQ.front().second + nums[i];
            while(!dQ.empty() && dQ.back().second < cur) dQ.pop_back();
            dQ.push_back({i, cur});
        }
        return dQ.back().second;
    }
};

// Solution 4: DP + priority_queue, time O(Nlog(N)), space O(N)

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size(), score;
        
        auto cmp = [](pair<int, int>&a, pair<int, int>&b){
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>pQ(cmp);
        for(int i=0 ; i<n ; i++){
            while(!pQ.empty() && i - pQ.top().first > k) pQ.pop();
            if(pQ.empty()) score = nums[i];
            else score = pQ.top().second + nums[i];
            pQ.push({i, score});
        }
        return score;
    }
};
