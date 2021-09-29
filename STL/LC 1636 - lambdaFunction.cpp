/*
1636. Sort Array by Increasing Frequency
*/

class Solution {
public:
    
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        if(a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int>>vec;
        for(int i=0 ; i<205 ; i++)
            vec.push_back({i-100, 0});
        
        for(auto &i: nums){
            vec[i+100].second++;
        }
        sort(vec.begin(), vec.end(), cmp);
        
        for(int i=0, k=0 ; i<vec.size(); i++){
            for(int j=0 ; j<vec[i].second ; j++)
                nums[k++] = vec[i].first;
        }
        return nums;
    }
};

// Solution 2: unordered_map + lambda function sorting

class Solution {
public:
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>uM;
        for(auto& i:nums)
            uM[i]++;
        sort(nums.begin(), nums.end(), [&uM](int a, int b){
            if(uM[a] == uM[b]) return a > b;
            return uM[a] < uM[b];
        });
        return nums;
    }
};