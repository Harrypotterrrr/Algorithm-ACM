/*
9. Palindrome Number

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true

Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
*/

#include "../include/include.h"

class Solution {
public:
    
    bool isPalindrome_extraSpace(int x) {
        if(x < 0) return false;
        vector<int> V;
        while(x){
            V.push_back(x % 10);
            x /= 10;
        }
        for(auto i=0 ; i<V.size()>>1 ; i++)
            if(V[i] != V[V.size()-1-i])
                return false;
        return true;
        
    }
    bool isPalindrome(int x) {
        if(x < 0 || (x > 0 && x % 10 == 0)) return false;
        int sum = 0;
        while(sum < x){
            sum *= 10;
            sum += x % 10;
            x /= 10;
        }
        return sum == x || sum / 10 == x;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}