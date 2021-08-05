/*
409. Longest Palindrome
*/

// Solution 1: trivial

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>uM;
        for(auto &i: s){
            uM[i] ++;
        }
        int ans = 0;
        bool flag = false;
        for(auto &i: uM){
            if(i.second % 2){
                ans += i.second - 1;
                flag = true;
            }
            else
                ans += i.second;
        }
        if(flag)
            return ans + 1;
        return ans;
    }
};

// Solution 2: 	set

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char>uS;
        for(auto &i: s){
            if(uS.find(i) != uS.end())
                uS.erase(i);
            else
                uS.insert(i);
        }
        return s.size() - max(int(uS.size() - 1), 0);
    }
};