/*
22. Generate Parentheses
*/

class Solution {
public:
    
    vector<string>ans;
    void find(string &ss, int left, int right){
        if(left == 0 && right == 0){
            ans.push_back(ss);
            return;
        }
        if(left>0){
            ss += '(';
            find(ss, left-1, right);
            ss.pop_back();
        }
        if(right>0 && right>left){
            ss += ')';
            find(ss, left, right-1);
            ss.pop_back();
        }
        
        // below is full permutation
        
//         for(int i=left ; i > 0 ; i--){
//             ss += '(';
//             find(ss, left-1, right);
//             ss.pop_back();
//         }
        
//         for(int j=right; j>left;j--){
//             ss += ')';
//             find(ss, left, right-1);
//             ss.pop_back();
//         }
    }
    vector<string> generateParenthesis(int n) {
        string ss;
        find(ss, n, n);
        return ans;
    }
};


// solution 2: unordered_set

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