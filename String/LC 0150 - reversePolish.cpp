/*
150. Evaluate Reverse Polish Notation
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>S;
        for(auto &i: tokens){
            if(isSymbol(i)){
                int tmp = S.top(); S.pop();
                if(i == "+")
                    tmp = S.top() + tmp;
                if(i == "-")
                    tmp = S.top() - tmp;
                else if(i == "*")
                    tmp = S.top() * tmp;
                else if(i == "/")
                    tmp = S.top() / tmp;
                S.pop();
                S.push(tmp);
            }
            else
                S.push(stoi(i));
        }
        return S.top();
    }
    bool isSymbol(string &i){
        return (i == "+") || (i == "-") || (i == "*") || (i == "/");
    }
};