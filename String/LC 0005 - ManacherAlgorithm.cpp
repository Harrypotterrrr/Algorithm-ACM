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

    # Manacher's Algorithm solution
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        
        string str((s.length()<<1) + 1, '#');
        for (auto i=0 ; i<s.length() ; i++)
            str[(i<<1) + 1] = s[i];
        
        int len = str.length(), center = 1, right = 2;
        int max_ra = 1, max_center= 1;
        int ra[len] = {0, 1}, mirror;
        
        for(int i=2 ; i<len ; i++){
            mirror = (center << 1) - i;
            if(ra[mirror] >= right - i){
                do{
                    right++;
                }while(right < len && (i<<1) >= right && str[right] == str[(i<<1)-right]);
                
                right--; 
                ra[i] = right - i;
                center = i;
                if(max_ra < ra[i]){
                    max_ra = ra[i];
                    max_center = i;
                }
            }
            else
                ra[i] = ra[mirror];
        }
        
        return s.substr((max_center - max_ra) >> 1, max_ra);
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