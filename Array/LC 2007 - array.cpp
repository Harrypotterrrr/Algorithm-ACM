/************************************************
Problem: 		2007. Find Original Array From Doubled Array
Algorithm: 		Array, STL
Difficulty: 	**
Importance:		**
Remark:			
*************************************************/

// Solution 1:

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        sort(changed.begin(), changed.end());
        unordered_map<int, int>uM;
        unordered_map<int, int>visited;
        vector<int> ans;
        for(int i=0 ; i<n ; i++){
            uM[changed[i]] = i;
            visited[changed[i]] ++;
        }
        for(int i=n-1 ; i>=0 ; i--){
            auto cur = changed[i];
            if(!visited[cur]) continue;
            visited[cur]--;
            if(cur & 1 || uM.find(cur >> 1) == uM.end() || !visited[changed[uM[cur>>1]]])
                return {};
            ans.push_back(cur>>1);
            visited[changed[uM[cur>>1]]]--;
        }
        return ans;
    }
};

// Solution 2: more elegant

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() & 1) return {};
        unordered_map<int, int>uM;
        for(auto &i: changed) uM[i]++;
        vector<int> vec, ans;
        for(auto &[i, ctr]: uM) vec.push_back(i);
        sort(vec.begin(), vec.end());
        int n = vec.size();
        for(auto &i: vec){
            if(uM[i] > uM[i<<1]) return {};
            for(int j=0 ; j<uM[i] ; ++j,--uM[i<<1])
                ans.push_back(i);
        }
        return ans;
    }
};
