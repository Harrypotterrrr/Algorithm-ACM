/*
49. Group Anagrams
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> um;
        for(auto &i:strs){
            string tmp = i;
            sort(tmp.begin(), tmp.end());
            if(um.find(tmp) == um.end()){
                um[tmp] = ans.size();
                vector<string> new_vec({i});
                ans.push_back(new_vec);
            }
            else{
                ans[um[tmp]].push_back(i);
            }
        }
        return ans;
    }
};

// solution 2
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> um;
        for(auto &ss : strs) {
            vector<int>ctr(26);
            for(int i=0 ; i<ss.size();i++)
                ctr[ss[i]-'a']++;
            string key;
            for(int i=0 ; i<ctr.size();i++){
                if(!ctr[i])
                    continue;
                key += string(1, 'a'+ i) + to_string(ctr[i]);
            }
            um[key].push_back(ss);
        }
        for(auto &item: um){
            ans.push_back(item.second);
        }
        return ans;
    }
};