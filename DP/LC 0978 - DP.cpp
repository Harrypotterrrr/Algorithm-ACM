/*
978. Longest Turbulent Subarray
*/


// Solution 1: simulation

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() < 2)
            return 1;
        int raise = 0;
        
        int ans = 1, ctr = 1;
        for(int i=1 ; i<arr.size() ; i++){
            if(arr[i] > arr[i-1]){
                if(raise > 0){
                    ans = ans > ctr ? ans : ctr;
                    ctr = 2;
                }
                else
                    ctr++;
                raise = 1;
            }
            else if(arr[i] < arr[i-1]){
                if(raise < 0){
                    ans = ans > ctr ? ans : ctr;
                    ctr = 2;
                }
                else
                    ctr++;
                raise = -1;
            }
            else{
                ans = ans > ctr ? ans : ctr;
                ctr = 1;
                raise = 0;
            }
        }
        ans = ans > ctr ? ans : ctr;
        return ans;
    }
};

// Solution 2: DP

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int>inc(arr.size(), 1);
        vector<int>dec(arr.size(), 1);
        int ans = 1;
        for(int i=1 ; i<arr.size() ; i++){
            if(arr[i] > arr[i-1])
                inc[i] = dec[i-1] + 1;
            else if(arr[i] < arr[i-1])
                dec[i] = inc[i-1] + 1;
            ans = max(ans, max(dec[i], inc[i]));
        }
        return ans;
    }
};

// Solution 3: sliding windows

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1;
        int anchor = 0;
        for(int i=1 ; i<arr.size(); i++){
            int c = cmp(arr[i], arr[i-1]);
            if(c == 0)
                anchor = i;
            else if(i == arr.size() - 1 || c * cmp(arr[i+1], arr[i]) != -1){
                ans = max(ans, i - anchor + 1);
                anchor = i;
            }
        }
        return ans;
    }
    int cmp(int &a, int &b){
        if(a == b)
            return 0;
        else if(a > b)
            return 1;
        return -1;
    }
};