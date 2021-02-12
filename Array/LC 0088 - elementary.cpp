/*
88. Merge Sorted Array
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1_bak;
        for(int i=0 ;i<m;i++)
            nums1_bak.push_back(nums1[i]);
        
        int p=0, q=0, r=0;
        while(p<nums1_bak.size() && q <nums2.size()){
            if(nums1_bak[p] > nums2[q])
                nums1[r++] = nums2[q++];
            else
                nums1[r++] = nums1_bak[p++];
        }
        while(p<nums1_bak.size()){
            nums1[r++] = nums1_bak[p++];
        }
        while(q<nums2.size()){
            nums1[r++] = nums2[q++];
        }
    }
};