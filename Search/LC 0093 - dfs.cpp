/*
93. Restore IP Addresses
*/

class Solution {
public:
    
    vector<string>ans;
    
    bool valid(const string s){
        if(s[0] == '0' && s.size() != 1)
            return false;
        int num = 0;
        for(auto &i : s){
            num *= 10;
            num += i - '0';
        }
        if (num <= 255 && num >= 0)
            return true;
        return false;
    }
    
    void dfs(const string &s, string ss, int k, int ctr){
        if(ctr >= 4 && k < s.size())
            return;
        
        if(k == s.size() && ctr == 4){
            ss.pop_back(); // remove '.';
            ans.push_back(ss);
            return;
        }
        for(int i=1 ; i<=3 && k + i <= s.size(); i++){
            string sub_str = s.substr(k, i);
            if(!valid(sub_str))
                continue;

            dfs(s, ss+sub_str+'.', k + i, ctr + 1);
            if(i == 1 && s[k] == '0')
                return;
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        dfs(s, "", 0, 0);
        return ans;
    }
};


// Solution 2: optimization

class Solution {
public:
    
    vector<string>ans;
    
    void dfs(const string &s, string ss, int k, int ctr){
        if(ctr == 4){
            if(k == s.size()){
                ans.push_back(ss);
            }
        }
        else{
            int max_i = min(3, s[k] == '0' ? 1 : 3);
            for(int i=1 ; i<=max_i && k + i <= s.size(); i++){
                string sub_str = s.substr(k, i);
                if(stoi(sub_str) <= 255){
                    dfs(s, ss+sub_str+ (ctr == 3 ? "" : "."), k + i, ctr + 1);
                }
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        dfs(s, "", 0, 0);
        return ans;
    }
};

// Solution: iteration

class Solution {
public:
    
    bool valid(string & s){
        if(s[0] == '0' && s.size() != 1)
            return false;
        return true;
    }
        
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        for(int a=1 ; a<=3 ; a++)        
        for(int b=1 ; b<=3 ; b++)
        for(int c=1 ; c<=3 ; c++)
        for(int d=1 ; d<=3 ; d++){
            if(a + b + c + d == s.size()){
                string num_a = s.substr(0, a);
                string num_b = s.substr(a, b);
                string num_c = s.substr(a + b, c);
                string num_d = s.substr(a + b + c, d);
                if(valid(num_a) && valid(num_b) && valid(num_c) && valid(num_d)){
                    if(stoi(num_a) <= 255 && stoi(num_b) <= 255 && stoi(num_c) <= 255 && stoi(num_d) <= 255){
                        ans.push_back(num_a + '.' + num_b + '.' + num_c + '.' + num_d);
                    }
                }
            }
        }

        return ans;
    }
};