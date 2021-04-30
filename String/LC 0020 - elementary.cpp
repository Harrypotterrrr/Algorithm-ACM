/*
20. Valid Parentheses
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char>S;
        for(auto &i : s){
            if(i == '(' || i == '{' || i == '['){
                S.push(i);
            }
            else if(i == ')'){
                if(S.empty() || S.top() != '(')
                    return false;
                S.pop();
            }
            else if(i == ']'){
                if(S.empty() || S.top() != '[')
                    return false;
                S.pop();
            }
            else if(i == '}'){
                if(S.empty() || S.top() != '{')
                    return false;
                S.pop();
            }
        }
        if(S.empty())
            return true;
        return false;
    }
};