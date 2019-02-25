/*
125. Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:

Input: "race a car"
Output: false
*/

#include "../include/include.h"

class Solution {
public:

    bool isValid(char& c){
        if(c <= '9' && c >= '0') return true;
        if(c <= 'z' && c >= 'a') { c -= 32; return true;}
        if(c <= 'Z' && c >= 'A') return true;
        return false;
    }

    bool isPalindrome(string s) {
        int st = 0, ed = s.size() - 1;
        while(st < ed){
            while(st < s.size() && !isValid(s[st])) st ++;
            if(st >= s.size()) break;
            while(!isValid(s[ed])) ed --;
            if(s[st] != s[ed]) break;
            st ++;
            ed --;
        }
        if(st >= ed) return true;
        return false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        bool ret = Solution().isPalindrome(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}