/*
5. Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"
*/

#include"../include/include.h"

class Solution {
public:

    string longestPalindrome_bruceForce(string s) {
        auto n = s.length();
        int st = 0;
        int rtn = 1;
        for(auto i=0 ; i<n; i++){
            for(auto j=i+1 ; j<n; j++){
                auto k = (j-i+1 >> 1) - 1;
                for(; k>=0 ; k--){
                    if(s[j-k] != s[i+k])
                        break;
                }
                if(k < 0 && j - i + 1 > rtn){
                    rtn = j - i + 1;
                    st = i;
                }
            }
            if(rtn >= n - i + 1)
                return s.substr(st, rtn);
        }
        return s.substr(st, rtn);
    }
    
    string longestPalindrome(string s) {
        if(s == "")
            return s;
        bool flags[s.length()][s.length()];
        memset(flags, false, sizeof(flags));
        int s_len = s.length();
        int len = 1, st = 0;

        for(auto i=0 ; i<s_len-1 ; i++){
            flags[i][i] = true;
            if(s[i] == s[i+1]){
                flags[i][i+1] = true;
                st = i;
                len = 2;
            }
        }
        flags[s_len-1][s_len-1] = true;
        
        for(auto i=0; i<s_len-2 ; i++){
            for(auto j=0 ; j<s_len-2-i ; j++){
                if(flags[j+1][1+i+j] && s[j] == s[2+i+j]){
                    flags[j][2+i+j] = true;
                    if(i+3 > len){
                        len = i+3;
                        st = j;
                    }
                }
            }
        }
        return s.substr(st, len);
        
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}