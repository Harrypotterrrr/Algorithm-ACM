/************************************************
Problem: 		210. Course Schedule II
Algorithm: 		Topological Sorting, Graph, BFS, DFS
Difficulty: 	**
Importance:		***
Remark:			
*************************************************/

// Solution 1: Topological sorting, BFS, time O(E+V), space O(E + V)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>adj_list;
        unordered_map<int, int> uM;
        for(int i=0 ; i<numCourses ; i++) uM[i] = 0;
        for(auto &item: prerequisites){
            adj_list[item[1]].push_back(item[0]);
            uM[item[0]] ++;
        }
        queue<int>Q;
        for(auto &[id, indegree]: uM)
            if(!indegree)
                Q.push(id);
        vector<int> ans;
        while(!Q.empty()){
            auto start = Q.front(); Q.pop();
            ans.push_back(start);
            for(auto &end: adj_list[start]){
                if(--uM[end] == 0)
                    Q.push(end);
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};

// Solution 2: Topological sorting, DFS, time O(E+V), space O(E + V)

class Solution {
public:
    
    enum visit_status {unvisited, visiting, visited};
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>adj_list;
        for(auto &item: prerequisites) adj_list[item[0]].push_back(item[1]);
        vector<int> visit(numCourses, unvisited);
        vector<int> ans;
        for(int i=0 ; i<numCourses ; i++){
            if(visit[i] == unvisited)
                if(!dfs(adj_list, visit, i, ans))
                    return {};
        }
        return ans;
    }
    
    bool dfs(unordered_map<int, vector<int>>&adj_list, vector<int>&visit, int start, vector<int>&ans){
        visit[start] = visiting;
        for(auto &end: adj_list[start]){
            if(visit[end] == visiting) return false;
            if(visit[end] == unvisited)
                if(!dfs(adj_list, visit, end, ans))
                    return false;
        }
        ans.push_back(start);
        visit[start] = visited;
        return true;
    }
};