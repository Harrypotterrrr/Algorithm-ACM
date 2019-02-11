/*
6. ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

class Solution {
public:
  
	// using extra space to store string
  	string convert_extraSpaces(string s, int numRows) {
        if(numRows <= 1) return s;
        vector<string>storage(numRows);
        string ans;
        int tmp = numRows - 1 << 1;
        for(auto i=0, line=0 ; i<s.length() ; i++){
            storage[line]+= s[i];
            if(i % tmp < numRows - 1) line++;
            else line--;
        }
        for(auto i=0 ; i<numRows ; i++)
                ans += storage[i];
        return ans;
    }
  
    string convert(string s, int numRows) {
        
        if(numRows == 1) return s;

        string ans;
        int len = s.length();
        int cycLen = numRows - 1 << 1;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < len; j += cycLen) {
                ans += s[j + i];
                if(i > 0 && i < numRows - 1 && j + cycLen - i < len)
                    ans += s[j + cycLen - i];
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);
        
        string ret = Solution().convert(s, numRows);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}