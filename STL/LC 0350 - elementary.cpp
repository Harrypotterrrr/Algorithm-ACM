/*
350. Intersection of Two Arrays II
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>uM;
        vector<int>ans;
        for(auto &i: nums1){
            if(uM.find(i) == uM.end()){
                uM[i] = 1;
            }
            else
                uM[i] ++;
        }
        for(auto &i: nums2){
            if(uM.find(i) != uM.end() && uM[i]){
                uM[i] --;
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Solution 2: optimization

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>uM;
        vector<int>ans;
        for(auto &i: nums1){
            uM[i] ++;
        }
        for(auto &i: nums2){
            if(uM[i]-- > 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Solution 3:

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};