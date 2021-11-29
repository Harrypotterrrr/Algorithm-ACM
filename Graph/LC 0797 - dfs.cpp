/************************************************
Problem: 		797. All Paths From Source to Target
Algorithm: 		Search, DFS, Graph
Difficulty: 	**
Importance:		*
Remark:			DAG
*************************************************/

// Solution 1: BFS

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> uM;
        int n = graph.size();
        for(int i=0 ; i<n ; i++){
            for(auto &dest: graph[i])
                uM[i].push_back(dest);
        }
        vector<int> cur;
        vector<vector<int>> ans;

        function<void(int)> dfs = [&](int start) ->void{
            if(start == n-1) {
                ans.push_back(cur);
                return;
            }
            for(auto &dest: uM[start]){
                cur.push_back(dest);
                dfs(dest);
                cur.pop_back();
            }
        };
        cur.push_back(0);
        dfs(0);
        return ans;
    }
};


// Solution 2: DFS + memo

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> uM;
        unordered_map<int, vector<vector<int>>> memo;
        int n = graph.size();
        for(int i=0 ; i<n ; i++){
            for(auto &dest: graph[i])
                uM[i].push_back(dest);
        }
        function<bool(int)> dfs = [&dfs, &uM, &memo, &n](int start) ->bool{
            if(memo[start].size()){
                return true;
            }
            if(start == n-1){
                memo[start].push_back({n-1});
                return true;
            }
            bool flag = false;
            for(auto &dest: uM[start]){
                if(dfs(dest)){
                    flag = true;
                    for(auto &vec: memo[dest]){
                        vector<int>tmp(vec.begin(), vec.end());
                        tmp.insert(tmp.begin(), start);
                        memo[start].push_back(tmp);
                    }
                }
            }
            return flag;
        };
        dfs(0);
        return memo[0];
    }
};


