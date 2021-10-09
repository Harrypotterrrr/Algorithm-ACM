/*
208. Implement Trie (Prefix Tree)
*/

class Trie {
public:
    struct TrieNode {
        vector<TrieNode*>vec;
        bool end;
        TrieNode(){
            vec.resize(26, nullptr);
            end = false;
        }
    };
    TrieNode* root;
    
    Trie() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* p = root;
        for(auto &c: word){
            if(!p->vec[c-'a']){
                TrieNode* node = new TrieNode;
                p->vec[c-'a'] = node;
                p = node;
            }
            else p = p->vec[c-'a'];
        }
        p->end = true;
    }
    
    bool search(string word) {
        TrieNode* p = root;
        for(auto &c: word){
            p = p->vec[c-'a'];
            if(!p) return false;
        }
        return p->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(auto &c: prefix){
            p = p->vec[c-'a'];
            if(!p) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */