/************************************************
Problem: 		425. Word Squares
Algorithm: 		Trie Tree, 
Difficulty: 	***
Importance:		***
Remark:			
*************************************************/

class Solution {
public:

    struct TrieNode{
        unordered_map<char, TrieNode*> uM;
        TrieNode(){}
    };
    
    vector<vector<string>> ans;
    TrieNode *root;
    int n;
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        root = new TrieNode;
        // build Trie Tree
        for(auto &word: words){
            TrieNode *p = root;
            for(auto &c: word){
                if(p->uM.find(c) == p->uM.end()){
                    TrieNode *new_node = new TrieNode;
                    p->uM[c] = new_node;
                }
                p = p->uM[c];
            }
        }
        vector<string> cur;
        n = words[0].size();
        solve(words, 0, cur);
        return ans;
    }
    
    void solve(const vector<string>& words, int k, vector<string> &cur){
        if(k >= n){
            ans.push_back(cur);
            return;
        }
        TrieNode* p = root;
        int i = 0;
        string cur_str = "";
        for(i=0 ; i<k ; i++){
            char c = cur[i][k];
            if(p->uM.find(c) != p->uM.end()){
                cur_str += c;
                p = p->uM[c];
            }
            else break;
        }
        if(i != k) return;
        get_string(words, k, cur, p, k, cur_str);
    }
    
    void get_string(const vector<string>& words, const int k, vector<string> &cur, TrieNode* node, int len, string cur_string){
        if(len >= n){
            cur.push_back(cur_string);
            solve(words, k+1, cur);
            cur.pop_back();
            return;
        }
        for(auto &i: node->uM){
            cur_string += i.first;
            get_string(words, k, cur, i.second, len+1, cur_string);
            cur_string.pop_back();
        }
    }
    
    
};