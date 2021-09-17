/*
415. Add Strings
*/


// Solution 1:

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans(max(num1.size(), num2.size())+1, '1');
        int p = num1.size()-1, q = num2.size()-1, r = ans.size()-1;
        int flag = 0, tmp;
        while(p >=0 && q >=0){
            tmp = flag + (num1[p--] - '0') + (num2[q--] - '0');
            flag = tmp / 10;
            tmp %= 10;
            ans[r--] = tmp + '0';
        }
        while(p >= 0){
            tmp = (num1[p--] - '0') + flag;
            flag = tmp / 10;
            ans[r--] = tmp % 10 + '0';
        }
        while(q >= 0){
            tmp = (num2[q--] - '0') + flag;
            flag = tmp / 10;
            ans[r--] = tmp % 10 + '0';
        }
        if(!flag)
            ans.erase(0, 1);
        return ans;
    }
};

// Solution 2: a bit more elegant

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans(max(num1.size(), num2.size()), ' ');
        int p = num1.size()-1, q = num2.size()-1, r = ans.size()-1;
        int flag = 0, tmp;
        while(p >=0 || q >=0){
            tmp = 0;
            if(p >= 0) tmp += num1[p--] - '0';
            if(q >= 0) tmp += num2[q--] - '0';
            tmp += flag;
            flag = tmp / 10;
            tmp %= 10;
            ans[r--] = tmp + '0';
        }
        return flag ? "1" + ans : ans;
    }
};