/*
3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include "../include/include.h"


// Solution 1: O(2n) two times traverse

class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        auto head = 0;
        int rtn = 0;
        std::unordered_map<char, int> uM;
        for(auto i=0 ; i<s.length() ; i++){
            if(uM.find(s[i]) == uM.end())
                uM[s[i]] = i;
            else {
                if(head <= uM[s[i]]){
                    rtn = rtn > i - head ? rtn : i - head;
                    head = uM[s[i]] + 1;
                }
                uM[s[i]] = i;
            }
            if(rtn >= s.length() - head)
                return rtn;
        }
        return rtn > s.length() - head? rtn : s.length() - head;
    }
};

// Solution 2: O(1n) one time traverse

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>uM;
        int left = -1, ans = 0, pos;
        for(int i=0 ; i<s.size() ; i++){
            if(uM.find(s[i]) != uM.end()){
                pos = uM[s[i]];
                left = left > pos ? left : pos;
            }
            ans = ans > i - left ? ans : i - left;
            uM[s[i]] = i;
        }
            
        return ans;
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
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}