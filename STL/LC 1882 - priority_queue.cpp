/************************************************
Problem: 		1882. Process Tasks Using Servers
Algorithm: 		STL, Simulation
Difficulty: 	**
Importance:		***
Remark:			
*************************************************/


// Solution 1: TLE, per_second operation. O(c*nlog(n)), the constant is too large

class Solution {
public:
	using pii = pair<int, int>;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        int k = 0, t = 0;
        vector<pair<int, int>> vec;
        for(int i=0 ; i<n ; i++) vec.push_back({i, servers[i]});
        auto cmp = [](pii &a, pii&b){
            return a.second > b.second || (a.second == b.second && a.first > b.first);
        };
        priority_queue<pii, vector<pii>, decltype(cmp)>pQ(cmp); // idle server
        unordered_map<int, int>uM; // work server: server_id, time_left
        for(auto &p: vec) {
            pQ.push(p);
            uM[p.first] = -1;
        }
        vector<int> ans;
        while(k < m){
            for(auto &[id, time]: uM){
                if(--time == 0) 
                    pQ.push({id, servers[id]});
            }
            while(k < m && k <= t && !pQ.empty()){
                auto [id, weight] = pQ.top(); pQ.pop();
                uM[id] = tasks[k++];
                ans.push_back(id);
            }
            t++;
        }
        return ans;
    }
};


// Solution 2: two heap
// reference link: https://leetcode.com/problems/process-tasks-using-servers/discuss/1241936/Two-Heaps

class Solution {
public:
    using piii = pair<pair<int, int>, long>;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        auto cmp_piii = [](piii &a, piii &b){
            if(a.second == b.second){
                if(a.first.second == b.first.second)
                    return a.first.first > b.first.first;
                return a.first.second > b.first.second;
            }
            return a.second > b.second;
        };
        priority_queue<piii, vector<piii>, decltype(cmp_piii)>busy(cmp_piii); // busy server: id, weight, time
        priority_queue<piii, vector<piii>, decltype(cmp_piii)>idle(cmp_piii); // idle server: id, weight, time
        for(int i=0 ; i<n ; i++) idle.push({{i, servers[i]}, 0});
        vector<int> ans;
        for(int t=0 ; t<m ; t++){
            while(!busy.empty() && (busy.top().second <= t || idle.empty())){
                auto [p, timestamp] = busy.top(); busy.pop();
                idle.push({{p.first, servers[p.first]}, timestamp <= t ? 0 : timestamp});
            }
            auto [p, timestamp] = idle.top(); idle.pop(); // TODO [[,],]
            busy.push({p, max(timestamp, long(t))+tasks[t]});
            ans.push_back(p.first);
        }
        return ans;
    }

};

// Solution 3: more elegant using array<long, 3> library
// reference link: https://leetcode.com/problems/process-tasks-using-servers/discuss/1241936/Two-Heaps

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        auto cmp = [](array<long, 3> &a, array<long, 3> &b){
            if(a[0] == b[0]){
                if(a[1] == b[1])
                    return a[2] > b[2];
                return a[1] > b[1];
            }
            return a[0] > b[0];
        };
        priority_queue<array<long, 3>, vector<array<long, 3>>, decltype(cmp)>busy(cmp), idle(cmp); // time, weight, id
        // or using greater
        // priority_queue<array<long, 3>, vector<array<long, 3>>, greater<array<long, 3>>>busy, idle; // time, weight, id

        for(int i=0 ; i<n ; i++) idle.push({0, servers[i], i});
        vector<int> ans;
        for(int t=0 ; t<m ; t++){
            while(!busy.empty() && (idle.empty() || busy.top()[0] <= t)){
                auto [time, weight, id] = busy.top(); busy.pop();
                idle.push({time <= t ? 0 : time, weight, id});
            }
            auto [time, weight, id] = idle.top(); idle.pop();
            busy.push({(time > t ? time : t) + tasks[t], weight, id});
            ans.push_back(id);
        }
        return ans;
    }

};
