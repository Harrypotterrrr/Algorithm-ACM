/************************************************
Problem: 		1834. Single-Threaded CPU
Algorithm: 		STL, Simulation
Difficulty: 	***
Importance:		****
Remark:			priority_queue
*************************************************/

// Solution 1: 

class Solution {
public:
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i=0 ; i<n ; i++) tasks[i].push_back(i); // start_t, process_t, id
        sort(tasks.begin(), tasks.end(), [](vector<int>&a, vector<int>&b){
            return a[0] < b[0];
        });
        auto cmp = [](pair<int, int>&a, pair<int, int>&b){
            if(a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>pQ(cmp); // process_t, id;
        vector<int> ans;
        long cur = tasks[0][0];
        for(int k=0, p = 0 ; k<n ; k++){
            while(p<n && (tasks[p][0] <= cur || pQ.empty())){
                pQ.push({tasks[p][1], tasks[p][2]});
                cur = cur > tasks[p][0] ? cur : tasks[p][0];
                p++;
            }
            auto [time, id] = pQ.top(); pQ.pop();
            cur += time;
            ans.push_back(id);
        }
        return ans;
    }
};
