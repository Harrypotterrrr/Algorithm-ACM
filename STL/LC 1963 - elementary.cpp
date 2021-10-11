/*
1963. Minimum Number of Swaps to Make the String Balanced
*/


// Solution 1: stack

class Solution {
public:
    int minSwaps(string s) {
        stack<char>S;
        for(auto &i: s){
            if(i == ']' && !S.empty() && S.top() == '[') S.pop();
            else S.push(i);
        }
        return ((S.size()>> 1) + 1) >> 1;
    }
};

// Solution 2: no stack

class Solution {
public:
    int minSwaps(string s) {
        stack<char>S;
        int imbalance = 0, left = 0;
        for(auto &i: s){
            if(i == '[') left++;
            else{
                if(left) left--;
                else imbalance++;
            }
        }
        return (imbalance + 1) >> 1;
    }
};

// Solution 3: more elegant

class Solution {
public:
    int minSwaps(string s) {
        int mismatch = 0;
        for(auto &i: s){
            if(i == '[') mismatch++;
            else if(mismatch > 0) mismatch --;
        }
        return (mismatch + 1) >> 1;
    }
};