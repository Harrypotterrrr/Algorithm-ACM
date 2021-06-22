/*
349. Intersection of Two Arrays
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>uS(nums1.begin(), nums1.end());
        vector<int>ans;
        for(auto &i : nums2){
            if(uS.count(i)){
                ans.push_back(i);
                uS.erase(i);
            }
        }
        return ans;
    }
};

// Solution 2:

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>uS(nums1.begin(), nums1.end()), ans;
        for(auto &i : nums2){
            if(uS.count(i)){
                ans.insert(i);
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};

// Solution 3:

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        unordered_set<int>uS;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                uS.insert(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        return vector<int>(uS.begin(), uS.end());
    }
};