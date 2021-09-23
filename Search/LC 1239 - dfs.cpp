/*
1239. Maximum Length of a Concatenated String with Unique Characters
*/

// Solution 1: dfs

class Solution {
public:
    vector<vector<bool>>vec;
    vector<bool>flag;
    int maxLength(vector<string>& arr) {
        flag.resize(26, false);
        for(auto &i: arr){
            vector<bool> tmp(26, false);
            int j = 0;
            for(j=0 ; j<i.size() ; j++){
                if(tmp[i[j] - 'a']) break;
                tmp[i[j] -'a'] = true;
            }
            if(j == i.size())
                vec.push_back(tmp);
        }
        return dfs(0);
    }
    
    int dfs(int k){
        if(k >= vec.size())
            return 0;
        int num1 = dfs(k+1), num2=0, inc=0;
        
        int i = 0;
        for(i=0 ; i<26 ; i++){
            if(vec[k][i]){
                if(flag[i]) break;
                inc++;
                flag[i] = true;
            }
        }
        
        if(i == 26)
            num2 = dfs(k+1) + inc;
        for(i = i-1;i>=0 ; i--){
            if(vec[k][i])
                flag[i] = false;
        }
        return num1 > num2 ? num1 : num2;
    }
};

// Solution 2: dfs + bit space optimization

class Solution {
public:
    vector<int>vec;
    int flag = 0;
    int maxLength(vector<string>& arr) {
        for(auto &i: arr){
            int tmp = 0;
            int j = 0;
            for(j=0 ; j<i.size() ; j++){
                if(tmp & (1 << (i[j] - 'a'))) break;
                tmp |= (1 << (i[j] - 'a'));
            }
            if(j == i.size())
                vec.push_back(tmp);
        }
        
        return dfs(0);
    }
    
    int dfs(int k){
        if(k >= vec.size())
            return 0;
        int num1 = dfs(k+1), num2=0, inc=0;
        
        int i = 0;
        for(i=0 ; i<26 ; i++){
            if(vec[k] & (1 << i)){
                if(flag & (1 << i)) break;
                inc++;
                flag |= (1 << i);
            }
        }
        
        if(i == 26)
            num2 = dfs(k+1) + inc;
        for(i = i-1;i>=0 ; i--){
            if(vec[k] & (1 << i))
                flag &= ~(1 << i);
        }
        return num1 > num2 ? num1 : num2;
    }
};