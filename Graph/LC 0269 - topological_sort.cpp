/************************************************
Problem: 		269. Alien Dictionary
Algorithm: 		Topological Sorting, Graph, BFS, DFS
Difficulty: 	***
Importance:		****
Remark:			
*************************************************/

// Solution 1: Topological sorting, BFS

class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        string pre = words[0];
        unordered_map<char, vector<char>> adj_list;
        unordered_map<char, int> uM;
        for(auto &c: words[0]) uM[c] = 0;
        
        for(int i=1 ; i<n ; i++){
            auto &cur = words[i];
            int cur_n = cur.size(), pre_n = pre.size(), j = 0;
            while(j < cur_n && j < pre_n && cur[j] == pre[j]) j++;
            if(j < pre.size()) {
                if(j >= cur_n) return "";
                adj_list[pre[j]].push_back(cur[j]);
            }
            pre = cur;
            for(auto &c: pre) uM[c] = 0;
        }
        for(auto &item: adj_list){
            for(auto &end: item.second)
                uM[end]++;
        }
        queue<char>Q;
        for(auto &[node, indegree]: uM)
            if(indegree == 0)
                Q.push(node);
        
        string ans = "";
        while(!Q.empty()){
            auto start = Q.front(); Q.pop();
            ans += start;
            for(auto &end: adj_list[start]){
                if(--uM[end] == 0){
                    Q.push(end);
                }
            }
        }
        if(ans.size() < uM.size()) return "";
        return ans;
    }
};

// Solution 2: Topological sorting + dfs

class Solution {
public:
    enum visit_status {unvisited, visiting, visited};
    string alienOrder(vector<string>& words) {
        int n = words.size();
        string pre = words[0];
        unordered_map<char, vector<char>> rev_adj_list;
        for(auto &word: words)
            for(auto &c: word)
                rev_adj_list.insert({c, vector<char>()}); // insert an empty vector to map[x]

        for(int i=1 ; i<n ; i++){
            auto &cur = words[i];
            int cur_n = cur.size(), pre_n = pre.size(), j = 0;
            while(j < cur_n && j < pre_n && cur[j] == pre[j]) j++;
            if(j < pre.size()) {
                if(j >= cur_n) return "";
                rev_adj_list[cur[j]].push_back(pre[j]);
            }
            pre = cur;
        }
        string ans = "";
        vector<int>flag(26, unvisited);
        for(auto &[c, vec]: rev_adj_list)
            if(flag[c-'a'] == unvisited)
                if(!dfs(rev_adj_list, flag, c, ans))
                    return "";
        return ans;
    }
    
    bool dfs(unordered_map<char, vector<char>> &rev_adj_list, vector<int>&flag, char c, string &ans){
        flag[c-'a'] = visiting;
        for(auto &next: rev_adj_list[c]){
            if(flag[next-'a'] == visiting) return false;
            if(flag[next-'a'] == unvisited){
                if(!dfs(rev_adj_list, flag, next, ans))
                    return false;
            }
        }
        flag[c-'a'] = visited;
        ans += c;
        return true;
    }
};

