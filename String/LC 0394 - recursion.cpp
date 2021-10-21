/*
394. Decode String
String, Parsing
**
*/

#include "../include/include.h"

class Solution {
public:
    string decodeString(string s) {
        string ans = "", cur_str = "";
        int cur_num = 0;
        stack<int>S;
        stack<string>SS;
        for(auto &i: s){
            if(i <= '9' && i >= '0'){
                cur_num = cur_num * 10 + i - '0';
            }
            else if(i >= 'a' && i <= 'z'){
                if(S.empty()) ans += i;
                else if(SS.size() == S.size()) SS.top() += i;
                else SS.push(string(1, i));
            }
            else if(i == '['){
                S.push(cur_num);
                cur_num = 0;
                if(SS.size() != S.size()) SS.push("");
            }
            else{
                int top_num = S.top(); S.pop();
                string tmp = "";
                for(int j=0 ; j<top_num ; j++) tmp += SS.top();
                SS.pop();
                if(S.empty()) ans += tmp; 
                else if(SS.size() == S.size()) SS.top() += tmp;
                else SS.push(tmp);
            }
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
        
        string ret = Solution().decodeString(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}