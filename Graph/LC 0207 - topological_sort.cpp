/************************************************
Problem: 		207. Course Schedule
Algorithm: 		Topological Sorting, Graph, BFS, DFS
Difficulty: 	*
Importance:		**
Remark:			
*************************************************/

// Solution 1: Topological sorting, BFS, time O(E+V), space O(E + V)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj_list;
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
        int ctr = 0;
        while(!Q.empty()){
            auto start = Q.front(); Q.pop();
            for(auto &end: adj_list[start]){
                if(--uM[end] == 0)
                    Q.push(end);
            }
            ctr ++;
        }
        return ctr == numCourses;
    }
};

// Solution 2: Topological sorting, DFS, time O(E+V), space O(E + V)

class Solution {
public:
    
    enum visit_status {unvisited, visiting, visited};
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj_list;
        for(auto &item: prerequisites)
            adj_list[item[1]].push_back(item[0]);
        int ctr = 0;
        vector<int>visit(numCourses, unvisited);
        for(int i=0 ; i<numCourses ; i++)
            // dfs(adj_list, visit, i, ctr);
            if(!dfs(adj_list, visit, i, ctr))
                return false;
        return ctr == numCourses;
    }
    
    bool dfs(unordered_map<int, vector<int>> &adj_list, vector<int>&visit, int start, int &ctr){
        if(visit[start] == visited) return true;
        visit[start] = visiting;
        for(auto &end: adj_list[start]){
            if(visit[end] == visiting) return false;
            if(visit[end] == unvisited){
                if(!dfs(adj_list, visit, end, ctr))
                    return false;
            }
        }
        visit[start] = visited;
        ctr++;
        return true;
    }
};