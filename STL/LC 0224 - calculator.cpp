/*
224. Basic Calculator
*/

// Solution 1: WA due to the minus

class Solution {
public:

    int calculate(string s) {
        stack<char>S;
        vector<string>vec;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == ' '){
                continue;
            }
            if(s[i] >= '0'){
                int j = i;
                while(j < s.size() && s[j] >= '0'){
                    j++;
                }
                vec.push_back(s.substr(i, j - i));
                i = j - 1;
            }
            else if(s[i] == '('){
                S.push('(');
            }
            else if(s[i] == ')'){
                while(S.top() != '('){
                    vec.push_back(string(1, S.top()));
                    S.pop();
                }
                S.pop();
            }
            else if(s[i] == '+' || s[i] == '-'){
                while(!S.empty() && S.top() != '('){
                    vec.push_back(string(1, S.top()));
                    S.pop();
                }
                S.push(s[i]);
            }
            else if(s[i] == '*' || s[i] == '/'){
                while(!S.empty() && (S.top() == '*' || S.top() == '/')){
                    vec.push_back(string(1, S.top()));
                    S.pop();
                }
                S.push(s[i]);
            }
        }
        while(!S.empty()){
            vec.push_back(string(1, S.top()));
            S.pop();
        }
        stack<int>S2;
        for(int i=0 ; i<vec.size() ; i++){
            if(vec[i][0] >= '0' && vec[i][0] <= '9'){
                S2.push(stoi(vec[i]));
            }
            else{
                int val2 = S2.top(); S2.pop();
                int val1 = S2.top(); S2.pop();
                if(vec[i] == "+"){
                    S2.push(val1 + val2);
                }
                else if(vec[i] == "-"){
                    S2.push(val1 - val2);
                }
                else if(vec[i] == "*"){
                    S2.push(val1 * val2);
                }
                else if(vec[i] == "/"){
                    S2.push(val1 / val2);
                }
            }
        }
        return S2.top();
    }
};

// Solution 2: 

class Solution {
public:

    int calculate(string s) {
        int ans = 0, sign = 1;
        stack<int>S;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] >= '0'){
                int num = 0;
                while(i<s.size() && s[i] >= '0'){
                    num *= 10;
                    num += s[i++] - '0';
                }
                ans += num * sign;
                i--;
            }
            else if(s[i] == '+')
                sign = 1;
            else if(s[i] == '-')
                sign = -1;
            else if(s[i] == '('){
                S.push(ans);
                S.push(sign);
                ans = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                ans = ans * S.top();
                S.pop();
                ans = S.top() + ans;
                S.pop();
            }
        }
        return ans;
    }
};