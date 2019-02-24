/*
394. Decode String

Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

#include "../include/include.h"

class Solution {
public:
    
    int parseNum(const string ss, int& begin){
        int cur = 0;
        while(ss[begin] <='9' && ss[begin] >= '0'){
            cur *= 10;
            cur += ss[begin++] - '0';
        }
        if(cur == 0) return 1;
        return cur;
    }
    bool isChar(char c){
        return (c <= 'z' && c >= 'a') || (c <='Z' && c >= 'A');
    }
    
    string parseExpression(const string ss, int & begin){
        string cur;
        while(begin < ss.length()){
            if(ss[begin] == ']'){
                begin++;
                break;
            }
            else if(isChar(ss[begin]))
                cur += ss[begin++];
            else{
                int mul = parseNum(ss, begin);
                string rtn = parseExpression(ss, ++begin);
                while(mul--) cur += rtn;
            }
        }
        return cur;
    }
    string decodeString(string s) {
        int begin = 0;
        return parseExpression(s, begin);
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
        
        string ret = Solution().decodeString(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}