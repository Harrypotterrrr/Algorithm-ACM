/*
769. Max Chunks To Make Sorted
*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, maxn = INT_MIN;
        for(int i=0 ; i < arr.size() ; i++){
            maxn = maxn > arr[i] ? maxn : arr[i];
            if(i == maxn) ans ++;
        }
        return ans;
    }
};