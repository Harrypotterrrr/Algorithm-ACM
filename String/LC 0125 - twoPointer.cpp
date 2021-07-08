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
    
    bool isValid(string &s, int k){
        if(s[k] >= 'A' && s[k] <= 'Z')
            s[k] += 32;
        return (s[k] >= 'a' && s[k] <= 'z') || (s[k] >= '0' && s[k] <= '9');
    }
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            while(!isValid(s, left) && left < right)left ++;
            while(!isValid(s, right) && left < right)right --;
            if(left >= right)
                return true;
            if(s[left] != s[right])
                return false;
            left ++;
            right --;
        }
        return true;
    }
};

// Solution 2: a little bit optimization, use % ans isalnum lib function

class Solution {
public:

    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            while(!isalnum(s[left]) && left < right)left ++;
            while(!isalnum(s[right]) && left < right)right --;
            if(left >= right)
                return true;
            if((s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32)
                return false;
            left ++;
            right --;
        }
        return true;
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