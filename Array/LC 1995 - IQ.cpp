/*
1995. Count Special Quadruplets
*/

// Solution 1: brute force, O(n^4)

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int a=0 ; a<n-3 ; a++){
            for(int b=a+1 ; b<n-2 ; b++){
                for(int c=b+1 ; c<n-1 ; c++){
                    for(int d=c+1 ; d<n ; d++){
                        if(nums[d] == nums[a] + nums[b] + nums[c]){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// Solution 2: optimization, split the array into two part, O(n^2)

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> uM;
        for(int i=1 ; i<n-2 ; i++){
            for(int j=0 ; j<i ; j++)
                uM[nums[i] + nums[j]] ++;
            for(int j=i+2 ; j<n ; j++)
                if(uM.count(nums[j]-nums[i+1]))
                    ans += uM[nums[j]-nums[i+1]];
        }
        return ans;
    }
};