/************************************************
Problem: 		1345. Jump Game IV
Algorithm: 		BFS, STL
Difficulty: 	***
Importance:		**
Remark:			
*************************************************/

// Solution 1: BFS + unordered_map

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        unordered_map<int, vector<int>>uM;
        vector<bool>visited_id(n, false);
        unordered_map<int, bool>visited_value;
        for(int i=0 ; i<n ; i++) {
            uM[arr[i]].push_back(i);
            visited_value[arr[i]] = false;
        }
        queue<int>Q({0}); // store the index
        visited_id[0] = true;
        while(!Q.empty()){
            for(int i=Q.size()-1 ; i>=0 ; i--){
                auto cur_id = Q.front(); Q.pop();
                auto cur_value = arr[cur_id];
                if(cur_id == n-1) return ans;
                if(cur_id + 1 < n && !visited_id[cur_id+1]) {
                    visited_id[cur_id+1] = true;
                    Q.push(cur_id+1);
                }
                if(cur_id - 1 >= 0 && !visited_id[cur_id-1]){
                    visited_id[cur_id+1] = true;
                    Q.push(cur_id-1);
                }
                if(!visited_value[cur_value]){
                    auto &vec = uM[cur_value];
                    for(int j=0 ; j<vec.size() ; j++){
                        if(!visited_id[vec[j]]){
                            visited_id[vec[j]] = true;
                            Q.push(vec[j]);
                        }
                    }
                    visited_value[cur_value] = true;
                }
            }
            ans ++;
        }
        return -1;
    }
};