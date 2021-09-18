/*
387. First Unique Character in a String
*/

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>ctr(26, 0);
        for(auto &i: s){
            ctr[i-'a'] ++;
        }
        for(int i=0 ; i<s.size() ; i++)
            if(ctr[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};

// Solution 2: unordered_map

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int>uM;
        for(auto &i: s)
            uM[i] ++;
        for(int i=0 ; i<s.size() ; i++)
            if(uM[s[i]] == 1)
                return i;
        return -1;
    }
};