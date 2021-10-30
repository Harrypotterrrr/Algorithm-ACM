/************************************************
Problem: 		1048. Longest String Chain
Algorithm: 		Dynmaic Programming, STL, Recursion, Memorization
Difficulty: 	****
Importance:		****
Remark:			
*************************************************/

// Solution 1: Recursion + memorization + STL

class Solution {
public:
    
    int longestStrChain(vector<string>& words) {
        unordered_set<string>uS(words.begin(), words.end());
        unordered_map<string, int>memo;
        int ans = 1;
        for(int i=0 ; i<words.size() ; i++){
            int rtn = dfs(memo, uS, words[i]);
            ans = ans > rtn ? ans : rtn;
        }
        return ans;
    }
    
    int dfs(unordered_map<string, int>& memo, unordered_set<string>&uS, string ss){
        if(!ss.size()) return 0;
        if(memo.find(ss) != memo.end()) return memo[ss];
        
        auto &cur = memo[ss] = 1;
        int len = ss.size();
        for(int i=-1 ; i<len-1 ; i++){
            string tmp = ss.substr(0, i+1) + (i < len-2 ? ss.substr(i+2) : "");
            if(uS.find(tmp) != uS.end()){
                int rtn = dfs(memo, uS, tmp) + 1;
                cur = cur > rtn ? cur : rtn;
            }
        }
        return memo[ss];
    }
    
};

// Solution 2: DP + sorting + STL

class Solution {
public:
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b){
            if(a.size() == b.size())
                return a < b;
            return a.size() < b.size();
        });
        unordered_map<string, int> dp;
        for(auto &i: words) dp[i] = 1;
        int ans = 1;
        for(int i=0 ; i<words.size() ; i++){
            auto &cur = words[i];
            int len = cur.size();
            dp[cur] = 1;
            for(int j=-1 ; j<len-1 ; j++){
                string tmp = cur.substr(0, j+1) + (j < len-2 ? cur.substr(j+2) : "");
                if(dp.find(tmp) == dp.end()) continue;
                dp[cur] = dp[cur] > dp[tmp] + 1 ? dp[cur] : dp[tmp] + 1;
            }
            ans = ans > dp[cur] ? ans : dp[cur];
        }
        return ans;
    }
    
};