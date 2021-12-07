/************************************************
Problem: 		788. Rotated Digits
Algorithm: 		Dynamic Programming
Difficulty: 	**
Importance:		***
Remark:			
*************************************************/

// Solution 1: O(Nlog(N)) stupid

class Solution {
public:
    int rotatedDigits(int n) {
        int ctr = 0;
        for(int i=1 ; i<=n ; i++){
            int rotate = get_rotate(i);
            if(rotate != -1 && rotate != i){
                ctr++;
            }
        }
        return ctr;
    }
    
    int get_rotate(int num){
        int rtn = 0;
        int base = 1;
        while(num){
            int tmp = get_rotate_digit(num % 10);
            if(tmp == -1) return -1;
            rtn += tmp * base;
            base *= 10;
            num /= 10;
        }
        return rtn;
    }
    
    int get_rotate_digit(int num){
        if(num == 0 || num == 1 || num == 8) return num;
        if(num == 2) return 5;
        if(num == 5) return 2;
        if(num == 6) return 9;
        if(num == 9) return 6;
        return -1;
    }
};

// Solution 2: DP O(n)

class Solution {
public:
    int rotatedDigits(int n) {
        enum valid_status {invalid, valid, good};
        vector<int> dp(n+1, invalid);
        int ctr = 0;
        for(int i=0 ; i<=n ; i++){
            if(i < 10){
                if(i == 0 || i == 1 || i == 8) dp[i] = valid;
                else if(i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = good;
                    ctr++;
                }
            }
            else{
                if(dp[i/10] == good && dp[i%10] != invalid){
                    dp[i] = good;
                    ctr++;
                }
                else if(dp[i/10] == valid && dp[i%10] == good){
                    dp[i] = good;
                    ctr++;
                }
                else if(dp[i/10] == valid && dp[i%10] == valid)
                    dp[i] = valid;
            }
        }
        return ctr;
    }
};

// Solution 3: unordered_set subset O(Nlog(N))

class Solution {
public:
    int rotatedDigits(int n) {
        unordered_set<int>S1 = {1, 8, 0};
        unordered_set<int>S2 = {1, 8, 0, 2, 5, 6, 9};
        int cur = 0, ctr = 0;
        for(int i=1 ; i<=n ; i++){
            int cur = i;
            unordered_set<int> cur_set;
            while(cur){
                cur_set.insert(cur % 10);
                cur /= 10;
            }
            if(!issubset(cur_set, S1) && issubset(cur_set, S2)) ctr++;
        }
        return ctr;
    }
    
    bool issubset(unordered_set<int>&s1, unordered_set<int>&s2){
        for(auto &i: s1)
            if(s2.find(i) == s2.end())
                return false;
        return true;
    }
};