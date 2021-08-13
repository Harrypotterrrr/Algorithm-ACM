/*
131. Palindrome Partitioning
*/

// Solution 1: dfs

class Solution {
public:
    
    vector<vector<string>> ans;
    
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> flag(s.size(), vector<bool>(s.size(), false));
        for(int i=0 ; i<s.size() ; i++){
            for(int j=i ; j<s.size() ; j++)
                if(isPalindrome(s, i, j))
                    flag[i][j] = true;
        }
        vector<string>tmp;
        dfs(s, 0, s.size()-1, tmp, flag);
        return ans;
    }
    
    
    bool isPalindrome(string &s, int start, int end){
        int len = (end - start + 1) >> 1;
        for(int i=0 ; i<len ; i++){
            if(s[start+i] != s[end-i])
                return false;
        }
        return true;
    }
    
    void dfs(string &s, int start, int end, vector<string>&vec, vector<vector<bool>>&flag){
        if(start >= s.size())
            return;
        if(end == s.size() - 1 && flag[start][end]){
            vec.push_back(s.substr(start));
            ans.push_back(vec);
            vec.pop_back();
        }
        for(int i=start ; i<=end ; i++){
            if(flag[start][i]){
                vec.push_back(s.substr(start, i-start+1));
                dfs(s, i+1, end, vec, flag);
                vec.pop_back();
            }
        }
    }
};

// Solution 2: a bit of optimization

class Solution {
public:
    
    vector<vector<string>> ans;
    
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> flag(s.size(), vector<bool>(s.size(), false));
        for(int i=0 ; i<s.size() ; i++){
            for(int j=i ; j<s.size() ; j++)
                if(isPalindrome(s, i, j))
                    flag[i][j] = true;
        }
        vector<string>tmp;
        dfs(s, 0, tmp, flag);
        return ans;
    }
    
    
    bool isPalindrome(string &s, int start, int end){
        while(start < end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    
    void dfs(string &s, int start, vector<string>&vec, vector<vector<bool>>&flag){
        if(start >= s.size()){
            ans.push_back(vec);
            return;
        }
        for(int i=start ; i<s.size() ; i++){
            if(flag[start][i]){
                vec.push_back(s.substr(start, i-start+1));
                dfs(s, i+1, vec, flag);
                vec.pop_back();
            }
        }
    }
};

// Solution 3: DP to optimize isPalindrome

class Solution {
public:
    
    vector<vector<string>> ans;
    
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> flag(s.size(), vector<bool>(s.size(), false));
        processPalindrome(s, flag);
        vector<string>tmp;
        dfs(s, 0, tmp, flag);
        return ans;
    }
    
    
    void processPalindrome(string &s, vector<vector<bool>> &flag){
        for(int i=0 ; i<s.size() ; i++){
            for(int j=0 ; j<s.size()-i ; j++)
                if(s[j] == s[j+i] && (i <= 2 || flag[j+1][j+i-1]))
                    flag[j][j+i] = true;
        }
    }
    
    void dfs(string &s, int start, vector<string>&vec, vector<vector<bool>>&flag){
        if(start >= s.size()){
            ans.push_back(vec);
            return;
        }
        for(int i=start ; i<s.size() ; i++){
            if(flag[start][i]){
                vec.push_back(s.substr(start, i-start+1));
                dfs(s, i+1, vec, flag);
                vec.pop_back();
            }
        }
    }
};

// Solution 4: TLE due to no reference pass on

class Solution {
public:
    
    vector<vector<string>> ans;
    vector<string>tmp;
    vector<vector<string>> partition(string s) {
        if(s.size() == 0){
            ans.push_back(tmp);
            return ans;
        }
        for(int i=0 ; i<s.size() ; i++){
            if(isPalindrome(s.substr(0, i+1))){
                tmp.push_back(s.substr(0, i+1));
                partition(s.substr(i+1));
                tmp.pop_back();
            }
        }
        return ans;
    }
    
    bool isPalindrome(string s){
        for(int i=0 ; i<(s.size() >> 1) ; i++){
            if(s[i] != s[s.size() - i - 1])
                return false;
        }
        return true;
    }
};

// Solution 5: Solution 3 with optimization to AC

class Solution {
public:
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(s.size() == 0){
            return {{}};
        }
        for(int i=0 ; i<s.size() ; i++){
            if(isPalindrome(s.substr(0, i+1))){
                for(auto &vec: partition(s.substr(i+1))){
                    vec.insert(vec.begin(), s.substr(0, i+1));
                    ans.push_back(vec);
                }
            }
        }
        return ans;
    }
    
    bool isPalindrome(string s){
        for(int i=0 ; i<(s.size() >> 1) ; i++){
            if(s[i] != s[s.size() - i - 1])
                return false;
        }
        return true;
    }
};

// Solution 6: sparculous iteration version, iterate non-diagonally

class Solution {
public:
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<vector<string>>> ans(s.size()+1);
        ans[0].push_back({});
        
        vector<vector<bool>> flag(s.size(), vector<bool>(s.size(), false));
        
        for(int i=0 ; i<s.size() ; i++){
            for(int j=0 ; j<=i ; j++){
                if(s[j] == s[i] && (i - j <= 2 || flag[j+1][i-1])){
                    flag[j][i] = true;
                    string cur = s.substr(j, i-j+1);
                    for(auto k: ans[j]){
                        k.push_back(cur);
                        ans[i+1].push_back(k);
                    }
                }
            }
        }
        return ans[s.size()];
    }
    
};