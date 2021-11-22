/************************************************
Problem: 		1525. Number of Good Ways to Split a String
Algorithm: 		Array, Prefix Sum
Difficulty: 	*
Importance:		**
Remark:			
*************************************************/

// Solution 1:

class Solution {
public:
    int numSplits(string s) {
	int n = s.size();
    vector<int>left_ctr(n, 0);
    vector<int>right_ctr(n, 0);
	unordered_set<char>uS({s[0]});
	for(int i=1 ; i<n; i++){
		if(uS.count(s[i]))
			left_ctr[i] = left_ctr[i-1];
		else{
			left_ctr[i] = left_ctr[i-1] + 1;
			uS.insert(s[i]);
		}
	}
	uS.clear(); uS.insert(s[n-1]);
	for(int i=n-2 ; i>=0; i--){
		if(uS.count(s[i]))
			right_ctr[i] = right_ctr[i+1];
		else{
			right_ctr[i] = right_ctr[i+1] + 1;
			uS.insert(s[i]);
		}
	}
	int ans = 0;
	for(int i=0 ; i<n-1 ; i++)
		if(left_ctr[i] == right_ctr[i+1]) ans ++;
	return ans;
    }
};

// Solution 2:

class Solution {
public:
    int numSplits(string s) {
        int n = s.size(), ans = 0;
        unordered_map<char, int> left, right;
        for(auto &c: s) right[c]++;
        for(auto &c: s){
            left[c]++;
            right[c]--;
            int ctr_l = 0, ctr_r = 0;
            for(int i='a' ; i<='z' ; i++) {
                if(left[i]) ctr_l++;
                if(right[i]) ctr_r++;
            }
            if(ctr_l == ctr_r) ans++;
        }
        return ans;
    }
};


