/*
242. Valid Anagram
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>M;
        if(s.size() != t.size())
            return false;
        for(auto &i : s){
            if(M.find(i) == M.end())
                M[i] = 1;
            else
                M[i] ++;
        }
        for(auto &i : t){
            if(M.find(i) == M.end())
                return false;
            else if(M[i] == 0)
                return false;
            M[i] --;
        }
        return true;
    }
};