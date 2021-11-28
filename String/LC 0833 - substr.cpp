/************************************************
Problem: 		833. Find And Replace in String
Algorithm: 		String
Difficulty: 	**
Importance:		*
Remark:			
*************************************************/

// Solution 1: from front to the back

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        vector<pair<int, int>>vec; // id, value of indices
        for(int i=0 ; i<n ; i++) vec.push_back({i, indices[i]});
        sort(vec.begin(), vec.end(), [](pair<int, int>&a, pair<int, int>&b){
            return a.second < b.second;
        });
        int inc_len = 0;
        for(int i=0 ; i<n ; i++){
            int id = vec[i].first;
            int p = inc_len + indices[id];
            auto &source = sources[id];
            auto &target = targets[id];
            auto sub_str = s.substr(p, source.size());
            if(sub_str.size() == source.size() && sub_str == source){
                s = s.substr(0, p) + target + s.substr(p+source.size());
                inc_len += target.size() - source.size(); //no potential bug
            }
        }
        return s;
    }
};

// Solution 2: optimized from back to the front

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        vector<pair<int, int>>vec; // id, value of indices
        for(int i=0 ; i<n ; i++) vec.push_back({i, indices[i]});
        sort(vec.begin(), vec.end(), [](pair<int, int>&a, pair<int, int>&b){
            return a.second > b.second;
        });
        for(int i=0 ; i<n ; i++){
            int id = vec[i].first;
            int p = indices[id];
            auto &source = sources[id];
            auto &target = targets[id];
            auto sub_str = s.substr(p, source.size());
            if(sub_str.size() == source.size() && sub_str == source){
                s = s.substr(0, p) + target + s.substr(p+source.size());
            }
        }
        return s;
    }
};

