/************************************************
Problem: 		792. Number of Matching Subsequences
Algorithm: 		Trie Tree, String
Difficulty: 	*****
Importance:		****
Remark:			
*************************************************/

// Solution 1: TLE O(S*total_num_node(trie)), where S is the length of string, N is the length of words and L is the depth of trie

class Solution {
public:
	struct TrieNode{
		unordered_map<char, TrieNode*> uM;
		bool is_end;
        int ctr;
		TrieNode() :is_end(false), ctr(0){}
	};
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        TrieNode *root = new TrieNode;
        for(auto &word: words){
            TrieNode *p = root;
            for(auto &c: word){
                if(p->uM.find(c) == p->uM.end()){
                    TrieNode *new_node = new TrieNode;
                    p->uM[c] = new_node;
                }
                p = p->uM[c];
            }
            p->ctr ++;
            p->is_end = true;
        }

        int ans = 0;
        function<bool(TrieNode*, int)> dfs = [&](TrieNode *node, int k) -> bool{ // how to not use &
            bool flag = false;
            if(node->is_end){
                flag = true;
                ans += node->ctr;
            }
            if(k >= n) return flag;
            for(auto &[c, next]: node->uM){
                for(int i=k ; i<n ; i++){
                    if(s[i] == c && dfs(next, i+1)){
                        flag = true;
                        break;
                    }
                }
            }
            return flag;
        };
        dfs(root, 0);
        return ans;
    }
};

// Solution 2: brute force O(S*total_length(words))

class Solution {
public:
	int numMatchingSubseq(string s, vector<string>& words) {
		int n = s.size(), ans = 0;
		unordered_set<string>pass, fail;
		for(auto &word: words){
			if(pass.count(word)){
				ans ++;
				continue;
			}
			if(fail.count(word)) continue;
			int p = 0, q = 0, m = word.size();
			while(p < n && q < m){
				if(word[q] == s[p]){
					p++;
					q++;
				}
				else p++;
			}
			if(q >= m) {
				pass.insert(word);
				ans++;
            }
			else fail.insert(word);
        }
        return ans;
    }
};

