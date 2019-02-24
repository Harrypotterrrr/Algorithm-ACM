/*
726. Number of Atoms

Given a chemical formula (given as a string), return the count of each atom.

An atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

1 or more digits representing the count of that element may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

Two formulas concatenated together produce another formula. For example, H2O2He3Mg4 is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.

Given a formula, output the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

Example 1:
Input: 
formula = "H2O"
Output: "H2O"
Explanation: 
The count of elements are {'H': 2, 'O': 1}.

Example 2:
Input: 
formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: 
The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.

Example 3:
Input: 
formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: 
The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
Note:

All atom names consist of lowercase letters, except for the first character which is uppercase.
The length of formula will be in the range [1, 1000].
formula will only consist of letters, digits, and round parentheses, and is a valid formula as defined in the problem.
*/

#include "../include/include.h"

class Solution {
public:
    
    map<string,int>M;

    int getNum(const string ss, int& begin){
        int cur = 0;
        if(begin >= ss.length())
            return 1;
        while(ss[begin] <= '9' && ss[begin] >= '0'){
            cur *= 10;
            cur += ss[begin] - '0';
            begin ++;
        }
        if(cur == 0) return 1;
        return cur;
    }
    void getElem(const string ss, int& begin, map<string, int>&curM){
        if(begin >= ss.length()) return;
        string cur;
        cur += ss[begin++];
        while(ss[begin] <= 'z' && ss[begin] >= 'a') 
            cur += ss[begin++];
        int num = getNum(ss, begin);
        if(curM.find(cur) != curM.end())
            curM[cur] += num;
        else curM[cur] = num;
    }
    
    void scanString(const string ss, int & begin, map<string, int> & preM){
        map<string, int>curM;
        while(begin < ss.length()){
            if(ss[begin] == ')'){
                begin ++;
                break;
            }
            if(ss[begin] == '('){
                scanString(ss, ++begin, curM);
                continue;   // important, loop again to check formula like this "(OH)2(NO)"
            }
            getElem(ss, begin, curM);
        }
        int mul = getNum(ss, begin);
        for(auto iter = curM.begin(); iter != curM.end() ; iter++){
            if(preM.find(iter->first) != preM.end())
                preM[iter->first] += iter->second * mul;
            else
                preM[iter->first] = iter->second * mul;
        }
    }
    
    string itoa(int num){
        if(num == 1) return "";
        string rtn;
        while(num){
            rtn += num % 10 + '0';
            num /= 10;
        }
        reverse(rtn.begin(), rtn.end());
        return rtn;
    }
    
    string countOfAtoms(string formula) {
        string ans;
        int begin = 0;
        scanString(formula, begin, M);
        for(auto iter=M.begin();iter!=M.end() ; iter++)
            ans += iter->first + itoa(iter->second);
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
        string formula = stringToString(line);
        
        string ret = Solution().countOfAtoms(formula);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}